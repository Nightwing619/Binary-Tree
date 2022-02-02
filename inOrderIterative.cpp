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
void inOrder(treeNode* root){
    if(root==NULL)
        return;
    stack<treeNode*> s;
    struct treeNode* curr=root;
    while(curr!=NULL||s.empty()==false){
        //reach the leftmost node of the tree
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
    //after this while loop, curr becomes null, cuz that's the condition of exiting the loop
    curr=s.top();
    s.pop();
    cout<<curr->data<<" ";
    curr=curr->right;
    }
}
int main()
{
 
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct treeNode *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 
    inOrder(root);
    return 0;
}