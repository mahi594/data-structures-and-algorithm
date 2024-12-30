#include<iostream>
#include<string>
using namespace std;

string removeOccurrences(string str,string part)
{
   while(str.length()!=0 && str.find(part) <str.length())
   {
    str.erase(str.find(part), part.length());
   }
    return str;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);  // Use getline to allow spaces in the input
    
    string part;
    cout << "Enter a part: ";
    getline(cin, part); 

   
    string result = removeOccurrences(str,part);
    cout << "Modified string: " << result << endl;
    return 0;
}
 