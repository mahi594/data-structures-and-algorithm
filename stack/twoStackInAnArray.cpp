#include<iostream>
#include<stack>
using namespace std;

class Stack
{
    int *arr;
    int top1;
    int top2;
    int size;

    public:
     
    Stack(int s)
    {
        this->size=s;
        top1=-1;
        top2=s;
        arr= new int[s];
    }

    void push1(int element)
    {
       if(top2-top1 >1)
       {
         top1=top1+1;
         arr[top1]=element;
       } 
       else
       {
        cout<<"overflow"<<endl;
       }
    }

    void push2(int element)
    {
       if(top2-top1 >1)
       {
         top2=top2-1;
         arr[top2]=element;
       } 
       else
       {
        cout<<"overflow"<<endl;
       }
    }

    int pop1()
    {
        if(top1>=0)
        {
            int ans= arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    int pop2()
    {
        if(top2 < size)
        {
            int ans= arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main() {
    Stack st(10);  // Total size of array is 10

    // Push elements to Stack 1
    st.push1(1);
    st.push1(2);
    st.push1(3);

    // Push elements to Stack 2
    st.push2(100);
    st.push2(200);
    st.push2(300);

    // Pop from Stack 1
    cout << "Pop from Stack 1: " << st.pop1() << endl;  // 3
    cout << "Pop from Stack 1: " << st.pop1() << endl;  // 2

    // Pop from Stack 2
    cout << "Pop from Stack 2: " << st.pop2() << endl;  // 300
    cout << "Pop from Stack 2: " << st.pop2() << endl;  // 200

    return 0;
}
