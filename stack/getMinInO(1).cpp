#include<iostream>
#include<stack>
#include<climits>
using namespace std;

stack<int>s;
int mini=INT_MAX;

void push(int data)
{
    //for fisrt elemnt
    if(s.empty())
    {
        s.push(data);
        mini=data;
    }
    else{
        if (data<mini)
        {
            int value=2*data-mini;
            s.push(value);
            mini=data;
        }
        else{
            s.push(data);
        }
        
    }
}

int pop()
{
    if(s.empty())
    {
        return -1;
    }

    int curr=s.top();
    s.pop();

    if(curr< mini)
    {
        return curr;
    }
    else
    {
       int prevMin=mini;
       int val=2*mini-curr; 
       mini=val;
       return prevMin;
    }
}

int top()
{
    if(s.empty())
    {
        return -1;
    }
    int curr=s.top();
    if(curr<mini)
    {
       return mini; 
    }
    else
    {
        return curr;
    }
}


bool isEmpty()
{
    return s.empty();
}

int getMIn()
{
    if(s.empty())
    {
        return -1;
    }

    return mini;
}

int main() {
    push(5);
    cout << "Pushed: 5, Min: " << getMIn() << endl;

    push(3);
    cout << "Pushed: 3, Min: " << getMIn() << endl;

    push(7);
    cout << "Pushed: 7, Min: " << getMIn() << endl;

    cout << "Top: " << top() << endl;
    cout << "Popped: " << pop() << ", New Min: " << getMIn() << endl;

    cout << "Top: " << top() << endl;
    cout << "Popped: " << pop() << ", New Min: " << getMIn() << endl;

    cout << "Top: " << top() << endl;
    cout << "Popped: " << pop() << ", New Min: " << getMIn() << endl;

    cout << "Is stack empty? " << (isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
