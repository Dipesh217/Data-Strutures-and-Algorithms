#include <iostream>
#include <vector>
using namespace std;

//Created a Node Struture
//->It consist of integer data and two pointer left and right
struct Node
{
    int data;
    Node *left;
    Node *right;

    //Created a Constructor that sets value of the memeber of the struture
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }

    int isBST(Node *root)
    {
        static  Node *prev = NULL;
        if (root != NULL)
        {
            if (!isBST(root->left))
            {
                return 0;
            }

            if (prev != NULL && root->data <= prev->data)
            {
                return 0;
            }
            prev = root;
            return isBST(root->right);
        }
        else
        {
            return 1;
        }
    }
};

 Node *searchBST( Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
    return NULL;
}

int search_iter_BST( Node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return 1;
            break;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return 0;
}

void insertBST(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            cout << "Element already exist in the BST";
            return;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct Node *p = new Node(key);
    if (prev->data > key)
    {
        prev->left = p;
    }
    else
    {
        prev->right = p;
    }
}

 Node *inorderPre( Node *root)
{
    root = root->left;
    while (root != NULL)
    {
        root = root->right;
    }
    return root;
}
 Node *deleteNode( Node *root, int key)
{

    Node *iPre;
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL and root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        iPre = inorderPre(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" "; 
    inorder(root->right);
}

int main()
{
    //Created the root of the tree
     Node *root = new Node(5);

    //Created the left node of the root
    root->left = new Node(3);

    //Created the right node of the root
    root->right = new Node(8);

    // and so on...
    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(7);
    root->right->right = new Node(9);

    // // Checking if a tree is BST or not
    // struct Node *a;
    // cout << a->isBST(root);

    // //Searching in binary search tree recurssive
    // int key = 70;
    // struct Node *b;
    // b =searchBST(root , key);
    // if(!b){
    //     cout<<"Not Found";
    // }
    // else{
    //     cout<<b->data;
    // }

    // //Searching in a BST iterative
    // int b = search_iter_BST(root,70);
    // if(b){
    //     cout<<"Element was Found";
    // }
    // else{
    //     cout<<"Element was not Found";
    // }

    // //Insertion in BST
    // insertBST(root,20);
    // cout<<root->right->right->right->data;

    //Deletion in BST
    inorder(root);
    cout<<endl;
    deleteNode(root, 2);

    inorder(root);
    return 0;
}
