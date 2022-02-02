#include <bits/stdc++.h>
using namespace std;
struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};
treeNode *newNode(int val)
{
    treeNode *node = new treeNode();
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void inOrder(treeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int sumTree(treeNode *root)
{
    if (root == NULL)
        return 0;
    int old_val = root->data;
    root->data = sumTree(root->left) + sumTree(root->right);
    return (root->data + old_val);
}
int main()
{
    treeNode *root = NULL;
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
    sumTree(root);
    cout << "Inorder Traversal of the resultant tree is: \n";
    inOrder(root);
    return 0;
}
//Time Complexity: The solution involves a simple traversal of the given tree. 
//So the time complexity is O(n) where n is the number of nodes in the given Binary Tree.