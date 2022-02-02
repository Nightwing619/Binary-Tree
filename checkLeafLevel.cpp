#include <bits/stdc++.h>
using namespace std;
struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode*right;
};
struct treeNode* newNode(int data){
    struct treeNode* temp = new treeNode();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
bool checkUtil(treeNode* root,int level,int* leafLevel){
    if(root==NULL)
        return true;
    if(!(root->left) && !(root->right)){ //if leaf node
        if(*leafLevel==0){ //if this is the first leaf node, assign it it's level
            *leafLevel=level;
            return true;
        }
        return (level == *leafLevel); //if not the first node visited, compare the level of the current leaf with that of the first leaf node
    }
    return checkUtil(root->left,level+1,leafLevel) && checkUtil(root->right,level+1,leafLevel); //if not a leaf node, recursively traverse both left and right subtrees until leaf node is found and then compare their levels
}
bool checkLevel(treeNode* root){
    int level=0, leafLevel=0;
    return checkUtil(root,level,&leafLevel);
}
int main(){
    struct treeNode *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (checkLevel(root))
        cout << "Leaves are at same level\n";
    else
        cout << "Leaves are not at same level\n";
    return 0;
}
//T.N. = O(n)