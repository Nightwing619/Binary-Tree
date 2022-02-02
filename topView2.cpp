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
void topView(treeNode* root){
    if(root==NULL)
        return;
    queue<pair<treeNode*,int>> q;
    q.push(make_pair(root,0));
    treeNode* node;
    int hd=0,l=0,r=0;
    stack<int> left;
    vector<int> right;
    while(q.size()){
        node=q.front().first;
        hd=q.front().second;
        if(hd<l){
            left.push(node->data);
            l=hd;
        }
        else if(hd>r){
            right.push_back(node->data);
            r=hd;
        }
        if(node->left)
            q.push(make_pair(node->left,hd-1));
        if(node->right)
            q.push(make_pair(node->right,hd+1));
        q.pop();
    }
    while (left.size()) {
        cout << left.top() << " ";
        left.pop();
    }
    cout << root->data << " ";// finally printing the right node's data
    for (auto x : right) {
        cout << x << " ";
    }
}
int main(){    
    treeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    topView(root);
    return 0;
}