#include<iostream>
using namespace std;

class heap
{
    public:
    int arr[100];
    int size=0;

    heap()
    {
        arr[0]= -1;
        size=0;
    }

    void insert(int val)
    {
        size=size+1;
        int index= size;
        arr[index]= val;

        while(index>1)
        {
            int parent= index/2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent],arr[index]);
                index= parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for(int i=1; i<= size; i++)
        {
            cout<< arr[i] << " ";
        }
        cout<<endl;
    }


    void heapify(int arr[],int n,int i)
    {
        int largest=i;   //node
        int left= 2*i;
        int right= 2*i + 1;

        if(left<=n && arr[largest]< arr[left])
        {
            largest=left;
        }

        if(right<=n && arr[largest]< arr[right])
        {
            largest=right;
        }

        //largest does not i whuch was our largest means largest has been updated 
        if(largest!= i)
        {
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }



    void haepSort(int arr[], int n)
    {
        int size=n;
        while(size>1)
        {
            //1:> swap
            swap(arr[size],arr[1]);
            size--;

            //2:> apply heapify
            heapify(arr,size,1);
        }
    }

};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(56);
    h.insert(58);
    h.insert(60);
    h.print();

    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--)
    {
          h.heapify(arr,n,i);
    }
    cout<<"printing array"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    h.haepSort(arr,n);
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}