#include <iostream> // for input-output operations
using namespace std;

const int MAX = 100; // maximum number of vertices
int adj[MAX][MAX];   // adjacency matrix to store edges (1 if edge exists)
int visited[MAX];    // keeps track of visited nodes
int recStack[MAX];   // keeps track of nodes in the current recursion stack
int V;               // number of vertices in the graph

bool dfs(int node) {
    visited[node] = 1;      // mark this node as visited
    recStack[node] = 1;     // add this node to the recursion stack

    for (int i = 0; i < V; i++) {         // iterate through all vertices
        if (adj[node][i]) {              // if there is an edge from current node to node i
            if (!visited[i]) {           // if node i has not been visited yet
                if (dfs(i)) return true; // recursively visit node i; if a cycle is found, return true
            } else if (recStack[i]) {    // if node i is in the recursion stack, a cycle is detected
                return true;
            }
        }
    }

    recStack[node] = 0;   // remove the node from the recursion stack after exploring all its neighbors
    return false;         // no cycle detected from this path
}

bool hasCycle() {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;    // initialize visited array to 0
        recStack[i] = 0;   // initialize recursion stack to 0
    }

    for (int i = 0; i < V; i++) {         // check all nodes (important for disconnected graphs)
        if (!visited[i]) {               // if the node has not been visited
            if (dfs(i)) return true;     // perform DFS from the node; return true if a cycle is found
        }
    }

    return false;   // no cycle found in any component
}

int main() {
    V = 4; // number of vertices

    // Clear adjacency matrix (no edges initially)
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Create a sample directed graph
    adj[0][1] = 1; // edge from 0 to 1
    adj[1][2] = 1; // edge from 1 to 2
    adj[2][0] = 1; // edge from 2 to 0 (forms a cycle)
    adj[2][3] = 1; // edge from 2 to 3

    if (hasCycle()) // check for cycle in the graph
        cout << "Cycle Detected!" << endl;
    else
        cout << "No Cycle Detected." << endl;

    return 0;
}

