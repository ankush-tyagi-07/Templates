#include<bits/stdc++.h>
using namespace std;

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int*degree[V];
	    for(int i=0;i<V;i++){
	        degree[i]=0;
	    }
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            int m=adj[i][j];
	            degree[m]++;
	        }
	    }
	    
	    queue<int> q;
	    vector<int> topo;
	    for(int i=0;i<V;i++){
	        if(degree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(q.size()>0){
	        int i=q.front();
	        q.pop();
	        topo.push_back(i);
	        for(int j=0;j<adj[i].size();j++){
	            int m=adj[i][j];
	            degree[m]--;
	            if(degree[m]==0){
	                q.push(m);
	            }
	        }
	    }
	    return topo;
	}

int main(){

}
