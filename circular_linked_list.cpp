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
        while (temp->next != head)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data;
    }

    void insertAtHead(node *&head, int val)
    {
        node *n = new node(val);

        if (head == NULL)
        {
            n->next = n;
            head = n;
        }
        node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
        head = n;
    }

    void deleteAtHead(node *&head)
    {

        node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }
        node *todelete = head;
        head = head->next;
        temp->next = head;

        delete todelete;
    }

    void insertAtTail(node *&head, int val)
    {
        if (head == NULL)
        {
            insertAtHead(head, val);
        }
        node *n = new node(val);
        node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }

    void deleteat_pos(node *&head, int pos)
    {
        if (pos == 1)
        {
            deleteAtHead(head);
            return;
        }

        node *temp = head;
        int count = 1;

        while (count != pos - 1)
        {
            temp = temp->next;
            count++;
        }
        node *todelete = temp->next;
        temp->next = temp->next->next;
    }
};

int main()
{
    node *head = NULL;
    node *a;
    a->insertAtHead(head, 4);
    a->insertAtHead(head, 5);
    cout << "Insert at head--->" << endl;
    a->display(head);
    cout << endl;
    a->insertAtTail(head, 6);
    a->insertAtTail(head, 7);
    a->insertAtTail(head, 8);
    cout << "Insert at tail--->" << endl;
    a->display(head);
    cout << endl;
    a->deleteAtHead(head);
    cout << "delete at head--->" << endl;
    a->display(head);
    cout << endl;
    a->deleteat_pos(head, 3);
    cout << "delete at 3--->" << endl;
    a->display(head);
    return 0;
}
