#include<iostream>
using namespace std;

//Created a Node Struture
//Tree->It consist of integer data and two pointer left and right
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    //Created a Constructor that sets value of the memeber of the struture
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }

    void preorder(struct Node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void inOrder(struct Node* root){
        if(root==NULL){
            return;
        }
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    void postOrder(struct Node* root){
        if(root==NULL){
            return;
        }
        inOrder(root->left);
        inOrder(root->right);
        cout<<root->data<<" ";
        
    }
};

int main(){
    //Created the root of the tree
    struct Node* root = new Node(1);

    //Created the left node of the root
    root->left =new Node(2);

    //Created the right node of the root 
    root->right =new Node(3);

    // and so on...
    root->left->left = new Node(4); 
    root->left->right = new Node(5);

    root->right->left = new Node(6); 
    root->right->right = new Node(7); 


    // Traversal In a Tree
    // 1.PreOrder Traversal
    // Root
    //Left Subtree
    //Right Subtree0

    struct Node *a;
    a->preorder(root);
    cout<<endl;

    //2.InOrder Traversal
    // Left Subtree
    // Root
    // Right Subtree

    a->inOrder(root);
    cout<<endl;

    // 3.PostOrder
    // Left Subtree
    // Right Subtree
    // Root 

    a->postOrder(root);

    return 0;
}