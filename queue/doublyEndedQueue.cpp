#include <iostream>
using namespace std;

class DoublyQueue {
    int* arr;
    int front;
    int rear;
    int size;

public:
    DoublyQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }


    bool pushFront(int value)
{
    if((front==0 && rear==size-1) || (rear==
       (front-1)%(size-1)))
    {
        return false;
    }
    else if(front==-1)
    {
        front=rear=0;
    }
    else if(front==0 && rear!=size-1)
    {
        front=size-1;
    }
    else {
      front--;
    }

    arr[front] = value;
    return true;
}

bool pushRear(int value)
{
    if((front==0 && rear==size-1) || (rear==
       (front-1)%(size-1)))
    {
        return false;
    }
    else if(front==-1)
    {
        front=rear=0;
    }
    else if(rear==size-1 && front!=0)
    {
        rear=0;
    }
    else {
      rear++;
    }

    arr[rear] = value;
    return true;
}
   
int popfront()
{
   if(front==-1)
       {
           //cout<<"queue is empty"<<endl;
           return -1;
       }
       int ans=arr[front];
       arr[front]=-1;
       if(front==rear){
           //single element is present
           front=rear=-1;
       }
       else if(front==size-1)
       {
           front=0;  // to main circular nature
       }
       else
       {
           front++;
       }
       return ans;
}


int popRear()
{
    if(rear==-1)
       {
           //cout<<"queue is empty"<<endl;
           return -1;
       }
       int ans=arr[rear];
       arr[rear]=-1;
       if(front==rear){
           //single element is present
           front=rear=-1;
       }
       else if(rear==0)
       {
           rear=size-1;  // to main circular nature
       }
       else
       {
           rear--;
       }
       return ans;
}    
        
};


int main() {
    DoublyQueue dq(5);  // Create a doubly ended queue of size 5

    // Inserting at rear
    dq.pushRear(10);
    dq.pushRear(20);

    // Inserting at front
    dq.pushFront(5);
    dq.pushFront(2);

    // Removing from rear
    cout << "Popped from rear: " << dq.popRear() << endl;

    // Removing from front
    cout << "Popped from front: " << dq.popfront() << endl;

    // Inserting again
    dq.pushRear(30);
    dq.pushFront(1);

    cout << "Popped from front: " << dq.popfront() << endl;
    cout << "Popped from rear: " << dq.popRear() << endl;

    return 0;
}



