#include <bits/stdc++.h>
using namespace std;

/*
Node class for Linked List
*/
class Node {
public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// Comparator for min-heap
class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;   // min-heap
    }
};

//vector<Node*> listArray = {list1, list2, list3};

// Function to merge K sorted linked lists
Node* mergeKLists(vector<Node*> &listArray) {
    priority_queue<Node*, vector<Node*>, compare> minheap;

    int k = listArray.size(); 

    // 1. Push first element of every list into the min-heap
    for (int i = 0; i < k; i++) {
        if (listArray[i] != NULL) {
            minheap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    // 2. Extract min element one by one and push next element of that list
    while (!minheap.empty()) {
        Node* temp = minheap.top();
        minheap.pop();

        if (temp->next != NULL) {
            minheap.push(temp->next);
        }

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}

// Utility function to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from a vector
Node* createList(vector<int> arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    // Example: K sorted linked lists
    vector<int> arr1 = {1, 4, 7};
    vector<int> arr2 = {2, 5, 8};
    vector<int> arr3 = {3, 6, 9};

    // Create linked lists
    Node* list1 = createList(arr1);
    Node* list2 = createList(arr2);
    Node* list3 = createList(arr3);

    // Store lists in vector
    vector<Node*> listArray = {list1, list2, list3};

    // Merge all K sorted lists
    Node* mergedHead = mergeKLists(listArray);

    // Print final merged list
    cout << "Merged Sorted List: ";
    printList(mergedHead);

    return 0;
}
