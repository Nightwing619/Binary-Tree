#include<bits/stdc++.h>
using namespace std;
class treeNode{
    public:
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
    int sum(treeNode* root){
        if(root==NULL)
            return 0;
        return (sum(root->left)+root->data+sum(root->right));
    }
    int isSum(treeNode* root){
        if(root==NULL||root->left==NULL && root->right==NULL)
            return 1;
        int ls=sum(root->left);
        int rs=sum(root->right);
        if(root->data==ls+rs && sum(root->left) && sum(root->right)){
            return 1;
        }
        return 0;
    }
};
int main(){
    treeNode *root = new treeNode(26);
    root->left = new treeNode(10);
    root->right = new treeNode(3);
    root->left->left = new treeNode(4);
    root->left->right = new treeNode(6);
    root->right->right = new treeNode(3);
    if(root->isSum(root))
        cout<<"THe given tree is a sum tree.";
    else
        cout<<"The given tree is not a sum tree";
    return 0;
}
//T.C. = O(nlogn)