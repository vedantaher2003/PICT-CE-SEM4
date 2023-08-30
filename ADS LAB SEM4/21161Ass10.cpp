#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
rules for heap:
1. tree should be complete tree
2. min heap--> value of parent is less than child
3. max heap--> value of parent is greater than child
*/
class heap
{
    int * arr;
    int size;

    public:
    heap(int n)
    {
        size = n;
        arr = new int[n];
    }

    //left child-->2i+1
    //right child-->2i+2
    //parent--> floor((i-1)/2)
    void readArr()
    {
        for(int i=0;i<size;i++)
        {
            cout<<"Enter value of "<<i+1<<" element: ";
            cin>>arr[i];
        }
        cout<<endl<<"------------------------------------------------"<<endl;
    }

    //heapify is thew process of getting heap data structure by either maxHeap or minHeap
    void maxHeap(int heapSize)
    {
        if(heapSize==0){
        cout<<"Array is empty.";
        return;
        }
        if(heapSize==1)
        {
            return;
        }

        //compare with its parent
        int i=1;
        while(i<heapSize)
        {
            int parent = floor((i-1)/2);
            if(arr[parent]<arr[i] && parent>=0)
            {
                //swap
                int temp = arr[parent];
                arr[parent] = arr[i];
                arr[i] = temp;

                //again compare with its parent
                i = parent;
                continue;
            }
            i++;
        }
        // cout<<"Max heap is- ";
        // for(int i=0;i<size;i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
    }

    void minHeap()
    {
        if(size==0){
        cout<<"Array is empty.";
        return;
        }
        if(size==1)
        {
            return;
        }

        //compare with its parent
        int i=1;
        while(i<size)
        {
            int parent = floor((i-1)/2);
            if(arr[parent]>arr[i] && parent>=0)
            {
                //swap
                int temp = arr[parent];
                arr[parent] = arr[i];
                arr[i] = temp;

                //again compare with its parent
                i = parent;
                continue;
            }
            i++;
        }
        cout<<"Min heap is- ";
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //Use heapify to get heap ds and then sort it using deletion
    void heapSort()
    {
        int sortSize = size;
        //while size of heap is greater than 1 follow following steps-
        //1. replace first element of heap with its last element and reduce size of heap by 1.
        //2. heapify the remaining heap.
        maxHeap(sortSize);//initially obtaing heap ds
        while(sortSize>1)
        {
            int temp = arr[0];
            arr[0] = arr[sortSize-1];
            arr[sortSize-1] = temp;

            //reduce size
            sortSize--;
            maxHeap(sortSize);
            
        }

    }
    void display()
    {
        
        for(int i=0;i<size;i++)
        {
           cout<<arr[i]<<" ";
        }
        cout<<endl<<"------------------------------------------------"<<endl;
    }

};
int main()
{
    int n;
    cout<<"\t\t**Heap Datastructure**\n";
    cout<<"Enter number of elements: ";
    cin>>n;
    heap obj(n);
    obj.readArr();
    cout<<"Input array is- ";
    obj.display();
    obj.heapSort();
    cout<<"Heap sorted result is- ";
    obj.display();
    return 0;
}