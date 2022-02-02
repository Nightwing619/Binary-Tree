#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
    int height(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        return (1+max(height(node->left),height(node->right)));
    }
    void printGivenLevel(TreeNode* node, int level){
        if(node==NULL){
            return;
        }
        else if(level==0){
            cout<<node->data<<" ";
        }
        else{
            printGivenLevel(node->left,level-1);
            printGivenLevel(node->right,level-1);
        }
    }
    void printLevelOrder(TreeNode* node){
        if(node==NULL){
            return;
        }
        int h=height(node);
        for(int i=0;i<h;i++){
            printGivenLevel(node,i);
        }
    }
};
int main(){
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(20);
    root->right=new TreeNode(30);
    root->left->left=new TreeNode(40);
    root->left->right=new TreeNode(60);
    root->printLevelOrder(root);
    return 0;
}