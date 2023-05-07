#include <bits/stdc++.h>
using namespace std;

template<class T>
class node
{
public:
    T data;
    node *next;
};

template<class T>
class Stack
{
public:
    node<T> *head;
    node<T> *top;
    int sz;
    Stack()
    {
        top = NULL;
        head = NULL;
        sz=0;
    }
private:
    node<T>* new_node(T value)
    {
        node<T> *newnode = new node<T>;
        newnode->data = value;
        newnode->next = NULL;

        return newnode;
    }
public:
    void Push(T value)
    {
        sz++;
        node<T> *newnode = new_node(value);
        if(head == NULL)
        {
            head = newnode;
            top = newnode;
            return;
        }
        else
        {
            node<T> *temp;
            temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            top = newnode;
        }
    }
    int getSize()
    {
        return sz;
    }
    void print()
    {
        if(sz==0)
        {
            cout<<"Stack in empty !";
            return;
        }
        node<T> *temp;
        temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    T Top()
    {
        if(sz==0)
        {
            return 0;
        }
        return top->data;
    }
    void Pop()
    {
        if(sz==0)
        {
            cout<<"Stack in empty !";
            return;
        }
        else if(sz==1)
        {
            sz--;
            delete head;
            return;
        }
        node<T> *temp;
        node<T> *dlt;
        temp = head;
        while(temp->next!=top)
        {
            temp = temp->next;
        }
        dlt = top;
        top = temp;
        top->next = NULL;

        delete dlt;
        sz--;
    }

};
int main()
{
    Stack<int> l;
    l.Push(10);
    l.Pop();

    Stack<float> l1;
    l1.Push(10.5);
    l1.Push(2.6);
    l1.Push(15.45);
    l1.Pop();


    l.print();
    cout<<"\n";
    cout<<l.Top()<<"\n";
    cout<<l.getSize();
    cout<<"\n";

    l1.print();
    cout<<"\n";
    cout<<l1.Top()<<"\n";
    cout<<l1.getSize();
    cout<<"\n";
    return 0;
}

