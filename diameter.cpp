#include<bits/stdc++.h>
using namespace std;
struct treeNode{
    int data;
    treeNode* left;
    treeNode* right;
};
treeNode* newNode(int data){
    treeNode* node = new treeNode();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
int height(treeNode* root){
    if(root==NULL)
        return 0;
    return (1+max(height(root->left),height(root->right)));
}
int diameter(treeNode* root){
    if(root==NULL)
        return 0;
    int lheight=height(root->left);
    int rheight=height(root->right);

    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);

    return max((lheight+rheight+1),max(ldiameter,rdiameter));
}
int main(){
    treeNode* root=newNode(10);
    root->left=newNode(20);
    root->right=newNode(30);
    root->left->left=newNode(40);
    root->left->right=newNode(60);
    cout<<"Diameter: "<<diameter(root)<<endl;
    return 0;
}