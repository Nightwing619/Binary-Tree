//this is an optimised version where, instead of using a map, we use a queue to store the left subtree nodes and a treeNode* type variable to store the right subtree nodes, and after the operation, store the nodes of entire level in a 2D vector.
#include<bits/stdc++.h>
using namespace std;
struct treeNode{
    int data;
    struct treeNode* left;
    struct treeNode* right;
};
struct treeNode* newNode(int val){
    struct treeNode* node= new treeNode();
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}
vector<vector<int>> result;
void diagonalTraversal(treeNode* root){
    if(root==NULL)
        return;
    queue<treeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> answer;
        while(size--){
            struct treeNode* temp=q.front();
            q.pop();
            while(temp){
                answer.push_back(temp->data);
                if(temp->left)
                    q.push(temp->left);
                temp=temp->right;
            }
        }
        result.push_back(answer);
    }
}
int main(){
    struct treeNode* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    diagonalTraversal(root);
    for(int i=0 ; i<result.size() ; i++){
        for(int j=0 ; j<result[i].size() ; j++)
            cout<<result[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}
//T.N.=O(n)