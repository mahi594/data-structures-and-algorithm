#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string str= "umbrella";
    stack<char> s;

    for(int i=0;i<str.length();i++)   //array to stack
    {
        char ch=str[i];
        s.push(ch);    //array to stack
    }

    string ans= "";

    while(!s.empty())   //stack to array in reverse order
    {
       char ch= s.top();
       ans.push_back(ch);  //array push

       s.pop();  //pop the element which is already pushed
    }

    cout<<"answer is  "<< ans <<endl;

    return 0;
}
