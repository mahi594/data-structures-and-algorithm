#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int d) {
        data = d;
        next = NULL;
        bottom = NULL;
    }
};




// Merge two bottom-linked sorted lists
Node* merge(Node* list1, Node* list2) {
    // Base cases
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node* mergedHead = NULL;

    // Choose the smaller node and recurse
    if (list1->data < list2->data) {
        mergedHead = list1;
        mergedHead->bottom = merge(list1->bottom, list2);
    } else {
        mergedHead = list2;
        mergedHead->bottom = merge(list1, list2->bottom);
    }

    return mergedHead;
}





// Flatten the multilevel linked list
Node* flatten(Node* root) {
    if (root == NULL || root->next == NULL)
        return root;

    // Recursively flatten the next list
    root->next = flatten(root->next);

    // Merge this list with the next list
    root = merge(root, root->next);

    return root;
}





// Print flattened list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}






int main() {
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Node* flat = flatten(head);

    cout << "Flattened List: ";
    printList(flat);

    return 0;
}
