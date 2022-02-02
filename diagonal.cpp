#include<bits/stdc++.h>
using namespace std;
struct treeNode{
    int data;
    int hd;
    struct treeNode* left;
    struct treeNode* right;
};
struct treeNode* newNode(int val){
    struct treeNode* node=new treeNode();
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}
void diagonalTraversalUtil(treeNode* root,int d,map<int,vector<int>> &dp){
    //here d is the depth of the node wrt the root
    if(root==NULL)
        return;
    //push the node of the current depth into the map
    dp[d].push_back(root->data);
    //we need to increase the depth by 1. Let's say we increase it for every left node, and for every right node, the depth stays same, as for all the nodes on a level, depth needs to be incremented only once
    diagonalTraversalUtil(root->left,d+1,dp);
    diagonalTraversalUtil(root->right,d,dp);
}
void diagonalTraversal(treeNode* root){
    map<int,vector<int>> diagonalPrint;
    diagonalTraversalUtil(root,0,diagonalPrint);
    cout<<"Diagonal traversal of the tree: "<<endl;
    for(auto it:diagonalPrint){
        vector<int> v=it.second;
        for(auto it:v)
            cout<<it<<" ";
        cout<<endl;
    }
}
int main(){
    struct treeNode* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    diagonalTraversal(root);
    return 0;
}
//T.N. = O(nlogn)