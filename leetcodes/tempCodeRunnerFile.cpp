#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int reverse(int n)
     {
        int digit=0;
        int answer=0;
        int INT_MIN=-2^31;
        int INT_MAX=2^31 - 1;
        int i=0;
        while(n!=0)
        {  
           digit=n%10;
          
          if(answer>INT_MAX/10 ||answer<INT_MIN/10)
          
          {
            return 0;
          }
          answer=answer*10 +digit;
            n=n/10;
            i++;
          
         }
        cout<<"the reverse no. is"<<answer;
        
     }
};
int main()
{
   unsigned int n;
    cout<<"enter a  no.";
    cin>>n;
    Solution obj;
    obj.reverse(n);
    return 0;
}