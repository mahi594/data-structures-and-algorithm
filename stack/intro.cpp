#include<iostream>
using namespace std;

class Stack {
   // properties 
   int top;
   int *arr;
   int size;

public:  // 🔁 Add this to allow external access to constructor and methods

   // constructor
   Stack(int size) {
     this->size = size;
     arr = new int[size];
     top = -1;
   }

   void push(int element) {
     if (size - top > 1) {
        top = top + 1;
        arr[top] = element;
     } else {
        cout << "overflow" << endl;
     }
   }

   void pop() {
    if (top >= 0) {
        top--;
    } else {
        cout << "underflow" << endl;
    }
   }

   int peek() {
      if (top >= 0) {
        return arr[top];
      } else {
        cout << "stack is empty" << endl;
        return -1;
      }
   }

   bool empty() {
      return top == -1;
   }
};

int main() {
    Stack st(5);

    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.peek() << endl;  

    st.pop();

    cout << st.peek() << endl;  

    st.pop();

    cout << st.peek() << endl;  

    st.pop();
    
    cout << st.peek() << endl;  
}
