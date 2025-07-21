#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int qfront;
    int rear;
    int size;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        qfront = rear = -1;
    }

    // Enqueues 'value' into the queue. Returns true if inserted, false otherwise.
    bool enqueue(int value) {
        if ((qfront==0 && rear==size-1) || (rear==
       (qfront-1)%(size-1))) {
            // Queue is full
            return false;
        }

        if (qfront == -1) {
            // First element
            qfront = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        return true;
    }

    // Dequeues front element from queue. Returns -1 if the queue is empty.
    int dequeue() {
        if (qfront == -1) {
            // Queue is empty
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;

        if (qfront == rear) {
            // Only one element
            qfront = rear = -1;
        } else {
            qfront = (qfront + 1) % size;
        }

        return ans;
    }
};


int main() {
    CircularQueue q(5); // queue size

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.enqueue(50) << endl; // Should return false (full)

    cout << "Dequeued: " << q.dequeue() << endl; // 10
    cout << "Dequeued: " << q.dequeue() << endl; // 20

    q.enqueue(50);
    q.enqueue(60);  // should be inserted at beginning (circular)

    while (true) {
        int val = q.dequeue();
        if (val == -1) break;
        cout << "Dequeued: " << val << endl;
    }

    return 0;
}
