#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        height = 1;
    }

    int getHeight(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return root->height;
        }
    }

    Node *createNode(int x)
    {
        Node *n = new Node(x);
        return n;
    }

    int getBalanceFactor(Node *root)
    {
        if (root == NULL)
        {
            return 1;
        }
        return getHeight(root->left) - getHeight(root->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        x = y->left;
        T2 = x->right;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return y;
    }

    Node *insert(Node *root, int key)
    {
        if (root == NULL)
        {
            return createNode(key);
        }

        if (key < root->data)
        {
            root->left = insert(root->left, key);
        }
        else
        {
            root->right = insert(root->right, key);
        }

        return root;
    }
};

int main()
{

    return 0;
}