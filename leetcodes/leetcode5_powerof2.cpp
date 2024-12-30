#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
      for(int i=0;i<=30;i++)
      {
        int ans=pow(2,i);
        if(ans==n)
        {
            return true;
        }
      }  
      return false;
    }
};
int main()
{
   unsigned int n;
    cout<<"enter a  no.";
    cin>>n;
    Solution obj;
    int result=obj.isPowerOfTwo(n);
    cout<<"is it power of 2"<<"  "<<result;
    return 0;
}