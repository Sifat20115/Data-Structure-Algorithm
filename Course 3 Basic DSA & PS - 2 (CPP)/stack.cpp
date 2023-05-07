#include<bits/stdc++.h>
using namespace std;

template<class T>
class Stack
{
private:
    T *arr;
    int cap;
    int sizee;
    void increase()
    {
        cap = cap*2;
        T *temp = new T[cap];
        for(int i=0;i<sizee;i++)
        {
            temp[i] = arr[i];
        }

        swap(arr,temp);
        delete [] temp;
    }
public:
    Stack()
    {
        arr = new T[1];
        cap=1;
        sizee = 0;
    }
    void push_Back(T x)
    {
        if(cap==sizee)
        {
            increase();
        }
        arr[sizee]=x;
        sizee++;
    }
    void pop()
    {
        if(sizee==0)
        {
            cout<<"Sorry your stack is empty";
            return;
        }
        sizee--;
    }
    void print()
    {
        for(int i=0;i<sizee;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    int top()
    {
        return arr[sizee-1];
    }
    int sz()
    {
        return sizee;
    }
};
int main()
{
    Stack<int> a;
    a.push_Back(10);
    a.push_Back(20);
    a.push_Back(30);
    a.push_Back(40);
    a.pop();
    cout<<a.top();
    cout<<"\n";


    a.print();
    cout<<"\n";
    cout<<a.sz();
    cout<<"\n";

    Stack<float> a1;
    a1.push_Back(10.5);
    a1.push_Back(20.5);
    a1.push_Back(30.5);

    a1.print();
    cout<<"\n";
    cout<<a1.sz();
    cout<<"\n";

    Stack<char> a2;
    a2.push_Back('S');
    a2.push_Back('I');
    a2.push_Back('F');
    a2.push_Back('A');
    a2.push_Back('T');

    a2.print();
    cout<<"\n";
    cout<<a2.sz();

    return 0;
}
