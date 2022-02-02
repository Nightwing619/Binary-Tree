#include<bits/stdc++.h>
using namespace std;
struct treeNode{
	char data;
	treeNode* left, *right;
};
struct treeNode* newNode(char data){
	treeNode* node = new treeNode();
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}
const string Marker="$";
unordered_set<string> subTree;
string dupCheckUtil(treeNode* root){
    string s="";
    if(root==NULL)
        return s + Marker;
    string lStr=dupCheckUtil(root->left);
    if(lStr.compare(s)==0)
        return s;
    string rStr=dupCheckUtil(root->right);
    if(rStr.compare(s)==0)
        return s;
    //serialize the subtree
    s+=root->data+lStr+rStr;
    // If current subtree already exists in hash
    // table. [Note that size of a serialized tree
    // with single node is 3 as it has two marker
    // nodes.
    if(s.length()>3 && subTree.find(s) != subTree.end())
        return "";
    subTree.insert(s);
    return s;
}
int main(){
    treeNode *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('B');
    root->right->right->right = newNode('E');
    root->right->right->left= newNode('D');
 
    string str = dupCheckUtil(root);
    (str.compare("") == 0) ? cout << " Yes ": cout << " No " ;
    return 0;
}