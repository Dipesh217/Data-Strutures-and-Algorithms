#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;

    node(int val)
    {
        prev = next = NULL;
        data = val;
    }

    void insertAtHead(node *&head, int val)
    {
        node *n = new node(val);
        n->next = head;
        if (head != NULL)
        {
            head->prev = n;
        }

        head = n;
    }

    void deleteAtHead(node *&head)
    {

        node* todelete = head;
        head = head->next;
        head->prev = NULL;
        delete todelete;

    }

    void insertAtTail(node *&head, int val)
    {
        if (head == NULL)
        {
            insertAtHead(head, val);
            return;
        }
        node *n = new node(val);
        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }

    void deleteAtTail(node *&head)
    {

        node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next=NULL;
    }

    void display(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    node *head = NULL;
    node *a;
    a->insertAtHead(head, 1);
    a->insertAtHead(head, 2);
    a->insertAtHead(head, 3);
    // a->display(head);
    a->insertAtTail(head, 1);
    a->insertAtTail(head, 2);
    a->insertAtTail(head, 3);
    a->deleteAtTail(head);
    a->deleteAtHead(head);
    a->deleteAtHead(head);
    a->display(head);

    return 0;
}