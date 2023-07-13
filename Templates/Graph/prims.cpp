#include<bits/stdc++.h>
using namespace std;

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum=0;
        vector<int> visited(V,0);
        while(!pq.empty()){
            auto f=pq.top();
            int dist=f.first;
            int node=f.second;
            pq.pop();
            if(visited[node]==1){
                continue;
            }
            visited[node]=1;
            sum+=dist;
            for(auto it:adj[node]){
                int edw=it[1];
                int adjnode=it[0];
                if(visited[adjnode]==0){
                    pq.push({edw,adjnode});
                }
            }
        }
        return sum;
    }

    int main(){
        
    }