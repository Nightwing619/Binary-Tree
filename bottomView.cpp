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
void bottomView(treeNode* root){
    if (root == NULL)
        return;
    queue<treeNode*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    cout << "The bottom view of the tree is : \n";
    while (q.size()) {
        hd = root->hd;
        m[hd] = root->data;
        if (root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }
}
int main(){    
    treeNode* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    bottomView(root);
    return 0;
}