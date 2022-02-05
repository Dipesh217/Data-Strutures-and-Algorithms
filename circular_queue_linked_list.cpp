#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;

    node(int x){
        data = x;
        next = NULL;
    }
};


class queue{
    node* front;
    node* back;

    public:
    queue(){
        front=NULL;
        back=NULL;
    }

    bool isEmpty(){
        if(front==NULL){
            return true;
        }
        return false;
    }

    void enqueue(int x){
        node* n = new node(x);
        if(isEmpty()){
            back = n;
            front=n;
            return;
        }
        back->next = n;
        back = n;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        node* todelete = front;
        front = front->next;
        delete todelete;
    }

    void traversal(){
        node *temp = front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    int peek(){
        if(isEmpty()){
            return -1;
        }
        return front->data;
    }
};

int main(){
    queue q;
    cout<<q.isEmpty();
    cout<<endl;
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(2);
    q.traversal();
    cout<<endl;
    q.dequeue();
    q.traversal();
    cout<<endl;
    cout<<q.peek();
    return 0;
}