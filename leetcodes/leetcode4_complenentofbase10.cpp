#include<iostream>

using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) {
        int m=n;
        int mask=0;

        if(n==0)
        { return 1;}
        
        while(m!=0)
        {
            mask=(mask<<1)|1;
            m=m>>1;
        }
        int answer=(~n)&mask;
        return answer;
    }
};
int main()
{
   unsigned int n;
    cout<<"enter a  no.";
    cin>>n;
    Solution obj;
    int result=obj.bitwiseComplement(n);
    cout << "The bitwise complement is: " << result << endl;
    

    return 0;
}