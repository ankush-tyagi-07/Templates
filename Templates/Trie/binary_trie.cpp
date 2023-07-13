#include<bits/stdc++.h> 
using namespace std; 

struct TrieNode{
    int value;
    TrieNode *child[2];
    TrieNode(){
        this->value = 0;
        this->child[0] = this->child[1] = NULL;
    }
};

class Solution{   
public:
    void insert(TrieNode *root,int pre_xor){
        TrieNode *temp = root;
        for(int i=31;i>=0;i--){
            bool curr  = pre_xor & (1<<i);
            if(temp->child[curr]==NULL){
                temp->child[curr] = new TrieNode();
            }
            temp = temp->child[curr];
        }
        temp->value=pre_xor;
    }
    int query(TrieNode *root,int pre_xor){
        TrieNode *temp = root;
        for(int i=31;i>=0;i--){
            bool curr = pre_xor & (1<<i);
            if(temp->child[1-curr] != NULL){
                temp = temp->child[1-curr];
            }else if(temp->child[curr] != NULL){
                temp = temp->child[curr];
                
            }
        }
        return pre_xor^(temp->value);
    }
    int maxSubarrayXOR(int N, int arr[]){    
        TrieNode *root = new TrieNode();
        insert(root,0);
        int result = INT_MIN,pre_xor=0;
        for(int i=0;i<N;i++){
            pre_xor= pre_xor^arr[i];
            insert(root,pre_xor);
            result = max(result,query(root,pre_xor));
        }
        return result;
    }
};
int main(){ 

} 