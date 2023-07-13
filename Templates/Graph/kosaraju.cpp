#include<bits/stdc++.h>
using namespace std;


	void dfs3(int v,int cv,vector<int> adj[],vector<int>& vis){
        vis[cv]=1;
        for(auto it:adj[cv]){
            if(!vis[it]){
                dfs3(v,it,adj,vis);
            }
        }
}

void dfs(int v,int cv,vector<int> adj[],stack<int>& s,vector<int>& vis){
        vis[cv]=1;
        for(auto it:adj[cv]){
            if(!vis[it]){
                dfs(v,it,adj,s,vis);
            }
        }
        s.push(cv);
}

int kosaraju(int V,vector<int> adj[]){
     vector<int> visited1(V,0);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited1[i]){
                dfs(V,i,adj,s,visited1);
            }
        }
        vector<int> visited2(V,0);
        vector<int> adj2[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adj2[it].push_back(i);
            }
        }
        int count=0;
        while(!s.empty()){
            int i=s.top();
            s.pop();
            if(!visited2[i]){
                dfs3(V,i,adj2,visited2);
                count++;
            }
        }

        return count;
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    cout<<kosaraju(v,adj);
}
