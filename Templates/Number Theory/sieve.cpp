#include<bits/stdc++.h>
using namespace std;

    vector<int> sieveOfEratosthenes(int n){
        // Write Your Code here
        vector<int> p(n+1);
	    vector<int> ans;
	    p[2] = 1;
	    for(int i=3; i<=n; i+=2){
	        p[i] = 1;
	    }
	    
	    ans.push_back(2);
	    
	    for(long long i=3; i<=n; i+=2){
	        
	        if(p[i]){
	            for(long long j=i*i; j<=n; j+=2*i){
	                p[j] = 0;
	            }
	            ans.push_back(i);
	        }
	    }
	    return  ans;
 }


int main(){

}