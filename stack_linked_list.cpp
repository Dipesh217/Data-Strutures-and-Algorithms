#include <iostream>
using namespace std;

class stack
{
public:
    int data;
    stack *next;

    stack(int val)
    {
        data = val;
        next = NULL;
    }

    void display(stack *&head)
    {
        stack *temp = head;
        cout << "head -> ";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

    int isEmpty(stack *&head)
    {
        if (head == NULL)
        {
            return 1;
        }
        return 0;
    }

    //Note:
    //Insertion and Deletion takes place at head

    void push(stack *&head, int val)
    {
        //Whenever i will push it will be insert at head.

        stack *n = new stack(val);
        n->next = head;
        head = n;
    }

    void pop(stack *&head)
    {
        //Whenever i will pop it will be deleted at head.

        if (isEmpty(head))
        {
            cout << "Stack is empty" << endl;
            return;
        }
        stack *a = head;
        head = head->next;
        a->next = NULL;
        delete a;
    }

    int top(stack *&head)
    {
        return head->data;
    }

    int bottom(stack *&head)
    {
        stack *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp->data;
    }
};

int main()
{
    stack *a;
    //IMP:In stack head=top
    stack *head = NULL;
    a->push(head, 1);
    a->push(head, 2);
    a->push(head, 3);
    a->push(head, 4);
    a->push(head, 5);
    a->pop(head);
    a->display(head);
    cout << endl;
    cout << a->top(head);
    cout << endl;
    cout << a->bottom(head);
    return 0;
}