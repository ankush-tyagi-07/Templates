#include<bits/stdc++.h>
using namespace std;

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,1e9);
        dist[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        
        while(!pq.empty()){
            auto f=pq.top();
            int dis=f.first;
            int node=f.second;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it[0];
                int edw=it[1];
                if(dis+edw<dist[adjnode]){
                    dist[adjnode]=dis+edw;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }

    int main(){
        
    }