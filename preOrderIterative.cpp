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
void preOrder(treeNode* root){
    if(root==NULL)
        return;
    stack<treeNode*> s;
    s.push(root);
    while(s.empty()==false){
        struct treeNode* curr=s.top();
        cout<<curr->data<<" ";
        s.pop();
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
}
int main(){
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
    struct treeNode* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    preOrder(root);
    return 0;
}