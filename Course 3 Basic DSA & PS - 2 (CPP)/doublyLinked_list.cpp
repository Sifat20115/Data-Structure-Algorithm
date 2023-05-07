#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node * nxt;
    node * prv;
};

class DoublyLinkedList
{
public:
    node *head;
    node *tail;
    int sz;
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    //Creates a new node with the given data and returns it O(1)
    node * CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    //Inserts a node with given data at head O(1)
    void InsertAtHead(int data)
    {
        sz++;
        node *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        node *a = head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }
    void insertTail(int data)
    {
        sz++;
        node *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        node *a = tail;
        newnode->prv = a;
        a->nxt = newnode;
        tail = newnode;
    }
    void insertMid(int data)
    {
        node *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        if(sz>1)
        {
            int insertat = 0;
            int At = sz/2;
            node *temp = head;
            node *temp1 =NULL;
            while(insertat!=At)
            {
                temp1 = temp;
                temp = temp->nxt;
                insertat++;
            }
            temp1->nxt = newnode;
            newnode->prv = temp1;
            newnode->nxt = temp;

        }
        sz++;
    }
    void Merge(DoublyLinkedList a)
    {
        tail->nxt = a.head;
    }


    //Inserts the given data at the given index O(n)
    void Insert(int index, int data)
    {
        if(index > sz)
        {
            return;
        }
        if(index==0)
        {
            InsertAtHead(data);
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index!= index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        // a = cur_index - 1
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        newnode->prv = a;
        node *b = a->nxt;
        b->prv = newnode;
        a->nxt = newnode;
        sz++;
    }

    //Deletes the given index O(n)
    void Delete(int index)
    {
        if(index >= sz)
        {
            cout<<index<<" doesn't exist.\n";
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != index)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->prv;
        node *c = a->nxt;
        if(b!=NULL)
        {
            b->nxt = c;
        }
        if(c!= NULL)
        {
            c->prv = b;
        }
        delete a;
        if(index==0)
        {
            head = c;
        }
        sz--;
    }

    //Prints the linked list O(n)
    void print()
    {
        node *a = head;
        while(a!=NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    // Returns the size of linked list O(1)
    int getSize()
    {
        return sz;
    }

    //Reverse the doubly linked list O(n)
    void Reverse()
    {
        if(head==NULL)
        {
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != sz-1)
        {
            a = a->nxt;
            cur_index++;
        }
        // last index is in a

        node *b = head;
        while(b!= NULL)
        {
            swap(b->nxt, b->prv);
            b = b->prv;
        }
        head = a;
    }
    void Swap(int i,int j)
    {
        int a = 0;
        node *temp;
        temp = head;

        while(a!=i)
        {
            a++;
            temp = temp->nxt;
        }
        int b = temp->data;
        temp = head;
        a=0;
        while(a!=j)
        {
            a++;
            temp = temp->nxt;
        }
        int c = temp->data;
        temp = head;
        a=0;
        while(a!=i)
        {
            a++;
            temp = temp->nxt;
        }
        temp->data = c;
        temp = head;
        a=0;
        while(a!=j)
        {
            a++;
            temp = temp->nxt;
        }
        temp->data = b;

    }
};


int main()
{
    DoublyLinkedList dl;
    dl.InsertAtHead(10);
    dl.InsertAtHead(5);
    dl.InsertAtHead(1);

    dl.insertTail(30);
    dl.insertTail(40);


    dl.print();
    dl.insertMid(15);
    dl.print();



    DoublyLinkedList d;
    d.InsertAtHead(9);
    d.InsertAtHead(8);
    d.InsertAtHead(7);

    d.insertTail(3);
    d.insertTail(2);


    d.print();
    d.insertMid(5);
    d.print();


    dl.Merge(d);
    dl.print();
    return 0;
}
