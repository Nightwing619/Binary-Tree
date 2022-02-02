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
int longestPathSum(treeNode* root){
    if(root==NULL)
        return 0;
    struct Element{
        struct treeNode* data;
        int sum;
        int level;
    };
    list<Element> que;
    Element e;
    e.data=root;
    e.level=0;
    e.sum=root->data;
    que.push_back(e);
    int maxSum=root->data, maxLevel=0;
    while(!que.empty()){
        Element front=que.front();
        treeNode* curr=front.data;
        que.pop_front();
        if(front.level > maxLevel){
            maxSum=front.sum;
            maxLevel=front.level;
        }
        if(front.level==maxLevel && front.sum>maxSum)
            maxSum=front.sum;
        if(curr->left){
            e.data=curr->left;
            e.sum=e.data->data;
            e.sum+=front.sum;
            e.level=front.level+1;
            que.push_back(e);
        }
        if(curr->right){
            e.data=curr->right;
            e.sum=e.data->data;
            e.sum+=front.sum;
            e.level=front.level+1;
            que.push_back(e);
        }
    }
    return maxSum;
}
int main() {  
  treeNode* root = newNode(4);        
  root->left = newNode(2);        
  root->right = newNode(5);       
  root->left->left = newNode(7);  
  root->left->right = newNode(1); 
  root->right->left = newNode(2);
  root->right->right = newNode(3);
  root->left->right->left = newNode(6);
   
  cout << longestPathSum(root) << "\n";
  return 0;
}
//T.N. = O(n)