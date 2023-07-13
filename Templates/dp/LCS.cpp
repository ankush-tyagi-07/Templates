#include<bits/stdc++.h>
using namespace std;

    int help(int x,int y, string s1,string s2,vector<vector<int>>& dp){
        // if(x==0||y==0){
        //     return 0;
        // }
        for(int i=0;i<x+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<y+1;i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                if(s1[i-1]==s2[j-1]){
                     dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
        
        // if(dp[x][y]!=-1){
        //     return dp[x][y];
        // }
        // if(s1[x-1]==s2[y-1]){
        //     return 1+help(x-1,y-1,s1,s2,dp);
        // }
        // return dp[x][y]=max(help(x-1,y,s1,s2,dp),help(x,y-1,s1,s2,dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x+1,(vector<int>(y+1,-1)));
        return help(x,y,s1,s2,dp);
    }

    int main(){
        
    }