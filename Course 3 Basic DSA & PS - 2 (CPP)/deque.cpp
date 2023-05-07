#include<bits/stdc++.h>

using namespace std;

template<class T>
class node
{
public:
    T data;
    node * nxt;
    node * prv;
};

template<class T>
class Deque
{
public:
    node<T> *head;
    node<T> *last;
    int sz;
    Deque()
    {
        head = NULL;
        last = NULL;
        sz = 0;
    }


    node<T> * CreateNewNode(T data)
    {
        node<T> *newnode = new node<T>;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    void Push_back(T data)
    {
        sz++;
        node<T> *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            last = newnode;
            return;
        }
        else
        {
            node<T> *temp;
            temp = head;
            while(temp->nxt!=NULL)
            {
                temp = temp->nxt;
            }
            temp->nxt = newnode;
            newnode->prv = temp;
            last = newnode;
        }
    }

    void Push_front(T data)
    {
        sz++;
        node<T> *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        else
        {
            newnode->nxt = head;
            head = newnode;
        }
    }

    void Pop_back()
    {
        if(sz==0)
        {
            cout<<" doesn't exist.\n";
            return;
        }
        node<T> *a;
        a=last;
        last = last->prv;
        last->nxt = NULL;

        delete a;
        sz--;
    }
    void Pop_front()
    {
        if(sz==0)
        {
            cout<<" doesn't exist.\n";
            return;
        }
        node<T> *a;
        a=head;
        head = head->nxt;

        delete a;
        sz--;
    }
    T Front()
    {
        if(sz==0)
        {
            cout<<" doesn't exist.\n";
            return 0;
        }
        return head->data;
    }
    T Back()
    {
        if(sz==0)
        {
            cout<<" doesn't exist.\n";
            return 0;
        }
        return last->data;
    }
    void Traverse()
    {
        node<T> *a = head;
        while(a!=NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
    }
    int getSize()
    {
        return sz;
    }
    void Reverse()
    {
        if(head==NULL)
        {
            return;
        }
        node<T> *a = head;
        int cur_index = 0;
        while(cur_index != sz-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node<T> *b = head;
        while(b!= NULL)
        {
            swap(b->nxt, b->prv);
            b = b->prv;
        }
        head = a;
    }
};


int main()
{
    Deque<char> dl;
    dl.Push_back('a');
    dl.Push_back('S');
    dl.Push_back('A');
    dl.Traverse();
    cout<<"\n";

    dl.Push_front('b');
    dl.Traverse();
    cout<<"\n";

    cout<<dl.Back();
    cout<<"\n";
    dl.Pop_front();
    dl.Traverse();
    cout<<"\n";

    dl.Pop_back();
    dl.Traverse();
    cout<<"\n";
    cout<<dl.getSize();
    cout<<"\n";

    cout<<"\n";
    Deque<int> di;
    di.Push_back(20);
    di.Push_back(30);
    di.Push_back(40);
    di.Traverse();
    cout<<"\n";

    di.Push_front(10);
    di.Traverse();
    cout<<"\n";

    cout<<di.Back();
    cout<<"\n";
    di.Pop_front();
    di.Traverse();
    cout<<"\n";

    di.Pop_back();
    di.Traverse();
    cout<<"\n";
    cout<<di.getSize();
    cout<<"\n";

    return 0;
}

