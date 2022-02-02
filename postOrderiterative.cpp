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
void postOrder(treeNode* root){
    if(root==NULL)
        return;
    stack<treeNode*> s;
    s.push(root);
    stack<int> out;
    while (!s.empty()){
        treeNode* curr=s.top();
        s.pop();
        out.push(curr->data);
        if(curr->left)
            s.push(curr->left);
        if(curr->right)
            s.push(curr->right);
    }
    while(!out.empty()){
        cout<<out.top()<<" ";
        out.pop();
    }
}
int main(){
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
    treeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);
    postOrder(root);
    return 0;
}