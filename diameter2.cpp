//this is the optimised version of previous code
#include<bits/stdc++.h>
using namespace std;
struct treeNode{
    int data;
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
int height(treeNode* root,int& ans){
    if(root==NULL)
        return 0;
    int lheight=height(root->left,ans);
    int rheight=height(root->right,ans);
    ans=max(ans,(1+lheight+rheight)); //diameter is nothing but the maximum value of 1+lheight+rheight for each node
    return (1+max(lheight,rheight));
}
int diameter(treeNode* root){
    if(root==NULL)
        return 0;
    int ans=INT_MIN;
    height(root,ans);
    return ans;
}
int main(){
    struct treeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    printf("Diameter is %d\n", diameter(root));
    return 0;
}
