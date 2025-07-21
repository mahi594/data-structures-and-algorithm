#include<iostream>
#include<stack>
using namespace std;

class NStack
{
    int *arr;
    int *next;
    int *top;

    int n, s;  // s = size of array, n = number of stacks
    int freeSpot;

public:
    // Constructor
    NStack(int N, int S)
    {
        n = N;
        s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialize all stacks as empty
        for (int i = 0; i < n; i++)
            top[i] = -1;

        // Initialize all spaces as free and link them
        for (int i = 0; i < s - 1; i++)
            next[i] = i + 1;
        next[s - 1] = -1;

        // Initialize beginning of free list
        freeSpot = 0;
    }

    // Push x into m-th stack
    bool push(int x, int m)
    {
        if (freeSpot == -1)
            return false;  // No space left

        //1:>> Get the first free index
        int index = freeSpot; 

        //2:>> Update freeSpot
        freeSpot = next[index];     

        //3:>> Insert the element
        arr[index] = x;       

        // 4:>>Link current to previous top
        next[index] = top[m - 1];  

        //5:>> Update top of m-th stack
        top[m - 1] = index;        

        return true;
    }



    // Pop from m-th stack
    int pop(int m)
    {
        if (top[m - 1] == -1)  // Stack underflow
            return -1;  

        //1:>> Index to pop            
        int index = top[m - 1];   

        //2:>> Update top to next element
        top[m - 1] = next[index];    

        //3:>> Add this index to free list
        next[index] = freeSpot;  

        //4:>> Update freeSpot
        freeSpot = index;            

        //5:>> return
        return arr[index];
    }
};


int main()
{
    // Create 3 stacks in an array of size 10
    NStack st(3, 10);

    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 2);
    st.push(40, 2);
    st.push(50, 3);

    cout << "Pop from stack 1: " << st.pop(1) << endl;  // Should print 20
    cout << "Pop from stack 2: " << st.pop(2) << endl;  // Should print 40
    cout << "Pop from stack 3: " << st.pop(3) << endl;  // Should print 50

    st.push(60, 1);
    st.push(70, 2);

    cout << "Pop from stack 1: " << st.pop(1) << endl;  // Should print 60
    cout << "Pop from stack 2: " << st.pop(2) << endl;  // Should print 70

    return 0;
}
