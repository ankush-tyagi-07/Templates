#include<bits/stdc++.h>
using namespace std;

    bool help(vector<int>& arr,int n,int sum,vector<vector<bool>>& dp){
        
        for(int i=0;i<sum+1;i++){
            dp[0][i]=false;
        }
        for(int i=0;i<n+1;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j]|dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<bool>> dp(arr.size()+1,vector<bool>(sum+1,false)); 
        return help(arr,arr.size(),sum,dp);
    }

int main(){

}