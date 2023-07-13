#include<bits/stdc++.h>
using namespace std;


class disjointset{
    private:
    vector<int> size,parent;
    public:
    disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    
    int find_parent(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find_parent(parent[x]);
    }
    
    void union_size(int x,int y){
        int ulx=find_parent(x);
        int uly=find_parent(y);
        if(ulx!=uly){
            if(size[ulx]>=size[uly]){
                parent[uly]=ulx;
                size[ulx]+=size[uly];
            }
            else{
                parent[ulx]=uly;
                size[uly]+=size[ulx];
            }
        }
    }
};

	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> help;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjnode=it[0];
                int dist=it[1];
                help.push_back({dist,{i,adjnode}});
            }
        }
        sort(help.begin(),help.end());
        int sum=0;
        disjointset ds(V);
        for(int i=0;i<help.size();i++){
            int dist=help[i].first;
            int u=help[i].second.first;
            int v=help[i].second.second;
            if(ds.find_parent(u)!=ds.find_parent(v)){
                ds.union_size(u,v);
                sum+=dist;
            }
        }
        return sum;
    }

    int main(){
        
    }