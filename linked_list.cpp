#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }

    void display(node *&head)
    {
        node *temp = head;
        cout << "head -> ";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void insertAtHead(node *&head, int val)
    {
        node *n = new node(val);
        n->next = head;
        head = n;
    }

    void deleteAtHead(node *&head)
    {
        node *a = head;
        head = head->next;
        a->next = NULL;
        delete a;
    }

    void insertAtTail(node *&head, int val)
    {

        if (head == NULL)
        {
            insertAtHead(head, val);
        }
        else
        {
            node *n = new node(val);
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    void deleteAtTail(node *&head)
    {
        node *temp = head;
        node *a = head->next;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
            a = a->next;
        }
        temp->next = NULL;
        delete a;
    }

    int search(node *&head, int val)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                return 1;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    node *a;
    node *head = NULL;
    a->insertAtHead(head, 3);
    // a->deleteAtHead(head);
    a->insertAtTail(head, 2);
    a->insertAtTail(head, 1);
    // // a->deleteAtTail(head);
    // // a->deleteAtTail(head);
    // a->display(head);
    // cout << endl;
    // // cout << a->search(head, 2);
    cout<<head->next->data;
    node * b = head;
    cout<<b->data;
    return 0;
}