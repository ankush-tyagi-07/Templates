	#include<bits/stdc++.h>
    using namespace std;

    void help(vector<int> adj[],int*visited,int cv,stack<int>*s){
	    visited[cv]=1;
	    
	    for(int j=0;j<adj[cv].size();j++){
	        int i=adj[cv][j];
	        if(visited[i]==0){
	            help(adj,visited,i,s);
	        }
	    }
	    s->push(cv);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int>* s=new stack<int>;
	    int*visited=new int[V];
	    for(int i=0;i<V;i++){
	        visited[i]=0;
	    }
	    help(adj,visited,0,s);
	    for(int i=0;i<V;i++){
	        if(visited[i]==0){
	            help(adj,visited,i,s);
	        }
	    }
	    vector<int> ans;
	    while(s->size()>0){
	        ans.push_back(s->top());
	        s->pop();
	    }
	   // delete s;
	    return ans;
	}

    int main(){

    }