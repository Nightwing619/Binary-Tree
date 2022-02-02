//Construct a tree from two given arrays consisting of inorder and preorder traversals
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
struct treeNode{
    char data;
    struct treeNode* left;
        struct treeNode* right;
};
struct treeNode* newNode(char val){
    struct treeNode* node=new treeNode();
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}
void inOrder(treeNode* root){
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
struct treeNode* buildTree(char in[], char pre[], int inStrt,int inEnd, unordered_map<char, int>& mp){
    static int preIndex = 0;
    if (inStrt > inEnd)
        return NULL;
    char curr = pre[preIndex++];
    struct treeNode* tNode = newNode(curr);
    if (inStrt == inEnd)
        return tNode;
    /* Else find the index of this node in Inorder traversal */
    int inIndex = mp[curr];
    /* Using index in Inorder traversal, construct left and
    right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp);
    return tNode;
}
struct treeNode* buldTreeWrap(char in[], char pre[], int len){
    unordered_map<char, int> mp;
    for (int i = 0; i < len; i++)
        mp[in[i]] = i;
    return buildTree(in, pre, 0, len - 1, mp);
}
int main(){
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    struct treeNode* root = buldTreeWrap(in, pre, len);
    printf("Inorder traversal of the constructed tree is \n");
    inOrder(root);
    return 0;
}