 #include<iostream>
 #include<vector>
using namespace std;
int countPrime(int n)
{
    int count=0;
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;

    for(int i=2;i<n;i++)  //for(int i=0;i<n;i++)
    {
        if(prime[i])
        {
            cout<<i<<" ";
            count++;
            for(int j=i*i;j<n;j=j+i)  //for(int j=2*i;j<n;j=j+i)
            {
                prime[j]=false;
            }
        }
    }
    
    return count;
}

int main()
{
    int n;
    cin>>n;

    cout<<"no. of prime no "<<n<<"is"<<countPrime(n)<<endl;
    return 0;
}




