#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty() {
        return qfront == rear;
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (rear == qfront) {
            return -1;  // Queue is empty
        }

        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;

        if (rear == qfront) {
            rear = qfront = 0;
        }

        return ans;
    }

    int front() {
        if (rear == qfront) {
            return -1;
        }
        return arr[qfront];
    }
};

// ----------- Main Function -------------
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;  // Output: 10

    cout << "Dequeued: " << q.dequeue() << endl;     // Output: 10

    cout << "Front element: " << q.front() << endl;  // Output: 20

    cout << "Dequeued: " << q.dequeue() << endl;     // Output: 20

    cout << "Dequeued: " << q.dequeue() << endl;     // Output: 30

    cout << "Dequeued: " << q.dequeue() << endl;     // Output: -1 (Queue is empty)

    if (q.isEmpty()) {
        cout << "Queue is empty now." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
