#include<bits/stdc++.h>
using namespace std;

class disjointSet{
  vector<int> rank,parent;
  public:
  disjointSet(int n){
      rank.assign(n,0);
      parent.assign(n,-1);
      for(int i=0;i<n;i++){
          parent[i]=i;
      }
  }
  
  int ulp(int x){
      if(parent[x]==x) return x;
      else return parent[x]=ulp(parent[x]);
  }
  
  void unionbyrank(int u,int v){
      u=ulp(u);
      v=ulp(v);
      if(u==v) return;
      if(rank[u]==rank[v]) rank[u]++;
      if(rank[u]>=rank[v]){
          parent[v]=u;
      }
      else parent[u]=v;
  }
};

int main(){
    
}
