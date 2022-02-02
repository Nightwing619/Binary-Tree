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
void leftView(treeNode* root){
    if(root==NULL)
        return;
    queue<treeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            struct treeNode* temp=q.front();
            q.pop();
            if(i==1)
                cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
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
    treeNode* root = newNode(10);
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(8); 
    root->right->right = newNode(15); 
    root->right->left = newNode(12); 
    root->right->right->left = newNode(14);
    leftView(root);
    return 0;
}