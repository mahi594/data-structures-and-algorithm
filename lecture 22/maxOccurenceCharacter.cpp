#include<iostream>
using namespace std;



//creayte an array bto count characters
char getMaxCharacter(string s)
{
    int arr[26]={0};

    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
 
        int number=0;
        if(ch>='a'&&ch<='z')
        {
            number=ch-'a';
        }
        else{
             number=ch-'A';
        }
        arr[number]++;
    }
   
   //find masimum occur character 
    int maxi=-1,ans=0;
    for(int i=0;i<26;i++)
    {
         if(maxi<arr[i])
         {
            ans=i;
            maxi=arr[i];
         }
    }

    char finalAns  ='a'+ans; 
    return finalAns;
     

}


int main()
{
   

   string s;
   cin>>s;
   cout<<"max character"<<" "<<getMaxCharacter(s);
}
 
