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

int main(){
    
}