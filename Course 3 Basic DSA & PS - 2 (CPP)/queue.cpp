#include<bits/stdc++.h>
using namespace std;

template<class T>
class Queue
{
private:
    T *arr;
    int cap;
    int sizee;
    int l,r;
    void increase()
    {
        cap = cap*2;
        T *temp = new T[cap];
        int idx=0;
        for(int i=l; i<sizee; i++)
        {
            temp[idx] = arr[i];
            idx++;
        }
        for(int i=0; i<r; i++)
        {
            temp[idx] = arr[i];
            idx++;
        }

        swap(arr,temp);
        delete [] temp;
    }
    void increase1()
    {
        cap = cap*2;
        T *temp = new T[cap];
        for(int i=0; i<sizee; i++)
        {
            temp[i] = arr[i];
        }

        swap(arr,temp);
        delete [] temp;
    }
public:
    Queue()
    {
        arr = new T[1];
        cap=1;
        sizee = 0;
        l=0;
        r=-1;
    }
    void enqueue(T x)
    {
        r++;
        if(cap==r)
        {
            if((r-l)+1<cap)
            {
                r=0;
            }
            else
            {
                increase1();
            }
        }
        else if(r==l)
        {
            increase();
            l=0;
            r=sizee;
        }
        arr[r]=x;
        sizee++;
    }
    void dequeue()
    {
        if(sizee==0)
        {
            assert(false);
        }
        l++;
        sizee--;
    }
    void print()
    {
        if(r<l)
        {
            for(int i=l; i<cap; i++)
            {
                cout<<arr[i]<<" ";
            }
            for(int i=0; i<=r; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        else
        {
            for(int i=l; i<=r; i++)
            {
                cout<<arr[i]<<" ";
            }
        }

    }
    int sz()
    {
        return sizee;
    }
    T Front()
    {
        return arr[l];
    }
};
int main()
{
    Queue<int> a;
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(30);
    a.enqueue(40);

    a.print();
    cout<<"\n";
    cout<<a.sz();
    a.dequeue();

    cout<<"\n";
    a.print();
    cout<<"\n";
    cout<<a.sz();

    a.enqueue(50);

    cout<<"\n";
    a.print();
    cout<<"\n";
    cout<<a.sz();

    a.dequeue();
    a.dequeue();
    a.dequeue();

    cout<<"\n";
    a.print();
    cout<<"\n";
    cout<<a.sz();

    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(20);
    a.enqueue(30);

    cout<<"\n";
    a.print();
    cout<<"\n";
    cout<<a.sz();

    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(20);
    a.enqueue(30);
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(20);
    a.enqueue(30);
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(20);
    a.enqueue(30);
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(20);
    a.enqueue(30);
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(20);
    a.enqueue(30);
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(20);
    a.enqueue(30);

    cout<<"\n";
    a.print();
    cout<<"\n";
    cout<<a.sz();

    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();

    cout<<"\n";
    a.print();
    cout<<"\n";
    cout<<a.sz();

    a.enqueue(20);
    a.enqueue(20);
    a.enqueue(30);
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(20);
    a.enqueue(30);
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(20);
    a.enqueue(30);

    cout<<"\n";
    a.print();
    cout<<"\n";
    cout<<a.sz();

    cout<<"\n";
    cout<<a.Front();
    a.dequeue();
    cout<<"\n";
    cout<<a.Front();

    return 0;
}
