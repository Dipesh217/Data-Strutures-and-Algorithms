#include<iostream>
using namespace std;

#define size 10

class queue{
    int front;
    int back;
    int *arr;

    public:

    queue(){
        front =-1;
        back = -1;
        arr = new int[size];
    }

    bool isEmpty(){
        if(back==-1 || front>back){
            cout<<"Queue is Empty"<<endl;
            return true;
        }
        return false;
    }

    bool isFull(){
        if(back==size-1){
            return true;
        }
        return false;
    }

    void push(int x){
        if(isFull()){
            return;
        }
        back++;
        arr[back] =x;

        if(front==-1){
            front++;
        }
    }

    void pop(){
        if(isEmpty()){
            return;
        }
        front++;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    void display(){
        for (int i = front; i < back+1; i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }
};

int main(){
    queue q;
    q.isEmpty();
    q.push(3);
    q.push(1);
    q.push(2);
    cout<<q.peek();
    cout<<endl;
    q.display();
    return 0;
}