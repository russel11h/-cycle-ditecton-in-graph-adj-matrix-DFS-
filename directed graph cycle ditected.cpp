#include <iostream>
using namespace std;

const int maxx=4;
int adj[maxx][maxx];
int visited[maxx];
int restack[maxx];
int v;

bool dfs(int node){

    visited[node]=1;
    restack[node]=1;

    for(int i=0;i<v;i++){
        if(adj[node][i]){
            if (!visited[i]){
                if(dfs(i))  return true;
            }
            else if (restack[i]){
                return true;
            }
        }
    }

    restack [node]=0;
    return false;

}


bool hascycle(){

    for(int i= 0;i<v;i++){

        visited[i]=0;
        restack[i]=0;
    }

    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(dfs(i)) return true;
        }
    }
    return false;
}

int main(){

    v=4;

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            adj[i][j]=0;

        }
    }


    adj[0][1]=1;
    adj[1][2]=1;
    adj[2][0]=1;
    adj[2][3]=1;


    if(hascycle()){
        cout<<"have Cycle"<<endl;
    }

    else{
        cout<<" have No cycle"<<endl;
    }

    return 0;


}
