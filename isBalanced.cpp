//this is the optimised version. The easy one used before is O(n^2) time-complexity
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
bool isBalanced(treeNode* root, int* height){
    int lh=0,rh=0; //heights of the left and right subtrees
    bool l=0,r=0;
    if(root==NULL){
        *height=0;
        return 1;
    }
    l=isBalanced(root->left,&lh);
    r=isBalanced(root->right,&rh);

    *height=1+max(lh,rh);
    if(abs(lh-rh)>=2)
        return 0;
    else
        return l && r;
}
int main()
{
    int height = 0;

    /* Constructed binary tree is 
            1 
            / \ 
            2 3 
            / \ / 
            4 5 6 
            / 
            7 
    */
    struct treeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    //root->right->left = newNode(6);
    root->left->left->left = newNode(7);

    if (isBalanced(root, &height))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";

    return 0;
}