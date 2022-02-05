#include <iostream>
using namespace std;

#define size 5

class stack
{

public:
    int *arr;
    int top;

    stack()
    {
        arr = new int[size];
        top = -1;
    }

    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        top--;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            cout << "stack is full" << endl;
            return 1;
        }
        return 0;
    }

    int at_top()
    {
        if (top == -1)
        {
            return -1;
        }
        return arr[top];
    }

    //Check over here
    int bottom()
    {
        if (isEmpty())
        {
            cout << "There are no element in the stack" << endl;
            return 0;
        }
        return arr[0];
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(4);
    cout << st.at_top() << endl;
    cout << st.isEmpty() << endl;
    cout << st.isFull() << endl;
    cout << st.bottom();
    return 0;
}