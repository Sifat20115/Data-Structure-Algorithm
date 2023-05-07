#include<bits/stdc++.h>
using namespace std;

class Array
{
private:
    int *arr;
    int cap;
    int sizee;
    void increase()
    {
        cap = cap*2;
        int *temp = new int[cap];
        for(int i=0;i<sizee;i++)
        {
            temp[i] = arr[i];
        }

        swap(arr,temp);
        delete [] temp;
    }
public:
    Array()
    {
        arr = new int[1];
        cap=1;
        sizee = 0;
    }
    void push_Back(int x)
    {
        if(cap==sizee)
        {
            increase();
        }
        arr[sizee]=x;
        sizee++;
    }
    void print()
    {
        for(int i=0;i<sizee;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    int sz()
    {
        return sizee;
    }
};
int main()
{
    Array a;
    a.push_Back(10);
    a.push_Back(20);
    a.push_Back(30);
    a.push_Back(40);

    a.print();
    cout<<"\n";
    cout<<a.sz();
    return 0;
}
