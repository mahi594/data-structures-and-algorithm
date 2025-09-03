#include<iostream>
#include<queue>
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


    void deleteHeap()
    {
        if(size==0)
        {
            cout<<"nothing to delete"<<endl;
            return;
        }

        //1:> last element to first index
        arr[1]=arr[size];
        //2:> remove last element
        size--;

        //3:> root node to its correct position
        for(int i=1;i<size;i++)
        {
            int child1= 2*i;
            int child2= (2*i)+1;

            if(child1<size  && arr[i] < arr[child1])
            {
               swap(arr[i],arr[child1]);
               i=child1;
            }
            else if(child2<size  && arr[i] < arr[child2])
            {
               swap(arr[i],arr[child2]);
               i=child2;
            }
            else{
                return;
            }
        }

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

    h.deleteHeap();
    h.print();
    h.deleteHeap();
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

//
//
//

    cout<<"using priority queue"<<endl;
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"element on top "<<pq.top()<<endl;
    pq.pop();
    cout<<"element on top "<<pq.top()<<endl;

    //
    //
    //


    //min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout<<"element on top "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"element on top "<<minHeap.top()<<endl;

  //
  
    return 0;
}