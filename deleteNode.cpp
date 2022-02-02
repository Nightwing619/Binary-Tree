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
void inOrder(treeNode* node){
    if(node==NULL)
        return;
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}
struct treeNode* deletion(treeNode* node,int val){
    if(node==NULL)
        return NULL;
    if(node->left==NULL && node->right==NULL){
        if(node->data==val)
            return NULL; 
        else
            return node;
    }
    struct treeNode* key_node=NULL;
    struct treeNode* temp;
    struct treeNode* last;
    queue<treeNode*> q;
    q.push(node);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp->data==val)
            key_node=temp;
        if(temp->left){
            last=temp; //storing the parent
            q.push(temp->left);
        }
        if(temp->right){
            last=temp;
            q.push(temp->right);
        }
    }
    if(key_node!=NULL){
        key_node->data=temp->data; //replacing the data of the node to be deleted with that of the deepest node
        if(last->right==temp)
            last->right=NULL;
        else
            last->left=NULL;
    }
    return node;
}
int main()
{
    struct treeNode* root = newNode(9);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(7);
    root->right = newNode(8);
    
 
    cout << "Inorder traversal before deletion : ";
    inOrder(root);
 
    int key = 2;
    root = deletion(root, key);
 
    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inOrder(root);

    return 0;
}