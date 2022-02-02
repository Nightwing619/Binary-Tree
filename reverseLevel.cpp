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
int height(treeNode* root){
    if(root==NULL)
        return 0;
    return (1+max(height(root->left),height(root->right)));
}
void printGivenLevel(treeNode* root,int level){
    if(root==NULL)
        return;
    else if(level==0)
        cout<<root->data<<" ";
    else{
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}
void reverseLevelOrder(treeNode* root){
    if(root==NULL)
       return;
    int h=height(root);
    for(int i=h;i>=0;i--)
        printGivenLevel(root,i);
}
int main(){ 
    treeNode *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 

    cout << "Level Order traversal of binary tree is \n"; 
    reverseLevelOrder(root); 

    return 0; 

} 