#include<bits/stdc++.h>
using namespace std;
struct treeNode{
    int data;
    treeNode* left;
    treeNode* right;
};
treeNode* newNode(int val){
    treeNode* node=new treeNode();
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}
struct Node{
    int data;
    Node* next;
    Node* prev;
};
struct Node* head=NULL;
void newNodeLL(int val){
    Node* temp=new Node();
    temp->data=val;
    if(head==NULL)
        head=temp;
    else{
        Node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    }
}
vector<int> res;
vector<int> preOrder(treeNode* root){
    if(root==NULL)
        return res;
    res.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
    return res;
}
void display(){
    if(head==NULL){
        printf("The list is empty.\n");
    }
    else{
        struct Node *ptr;
        ptr=head;
        while(ptr!=NULL){
            printf("%d-->",ptr->data);
            ptr=ptr->next;
        }
    }
}
int main(){
    struct treeNode* root=newNode(10);
    root->left=newNode(12);
    root->right=newNode(15);
    root->left->left=newNode(25);
    root->left->right=newNode(30);
    root->right->left=newNode(25);
    vector<int> vec=preOrder(root);
    for(int i=0;i<vec.size();i++)
        newNodeLL(vec[i]);
    display();
}