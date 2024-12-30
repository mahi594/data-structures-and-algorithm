#include<iostream>
#include<string>
using namespace std;

bool valid(char ch)
{
      if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
      {
        return 1;
      }
      return 0;
}

char toLowerCase(char ch)
{
    if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
    {
        return ch;
    }
    else{
        char temp;
        temp=ch-'A'+'a';
    }
}

bool checkPalindrome(string s)
{
    int st=0;
    int e=s.length()-1;

     while(st<=e)
     {
        if(s[st]!=s[e])
        {
            return 0;
        }
        else
        {
            st++;
            e--;
        }
     }

     return 1;
}

bool isPalindorme(string s)
{

    //faltu char hatao
    string temp;

    for(int i=0;i<s.length();i++)
    {
        if(valid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }

    //lower case mai kardo
    for(int i=0;i<s.length();i++)
    {
        temp[i]=toLowerCase(temp[i]);
    }

    //check palindrome
    return checkPalindrome(temp);

}


int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (isPalindorme(s)) {
        cout << "\"" << s << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << s << "\" is not a palindrome." << endl;
    }

    return 0;
}