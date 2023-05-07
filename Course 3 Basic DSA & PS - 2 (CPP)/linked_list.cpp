#include <bits/stdc++.h>
using namespace std;


class node
{
public:
    int data;
    node *next;
};
class linked_list
{
public:
    node *head;
    int sz;
    linked_list()
    {
        head = NULL;
        sz=0;
    }
private:
    node* new_node(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->next = NULL;

        return newnode;
    }
public:
    void insert_value(int value)
    {
        sz++;
        node *newnode = new_node(value);
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        else
        {
            node *temp;
            temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    int getSize()
    {
        return sz;
    }
    void print()
    {
        node *temp;
        temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }

    }
    void sortList()
    {
        if(getSize()<2)
        {
            return;
        }
        node *temp;
        node *temp2;
        temp = head;
        temp2 = head;
        temp = temp->next;
        while(temp!=NULL)
        {
            temp2 = head;
            while(temp2!=temp)
            {
                if((temp2->data)>(temp->data))
                {
                    swap((temp2->data),(temp->data));
                }
                temp2=temp2->next;
            }
            temp = temp->next;
        }
    }
};
int main()
{
    linked_list l;
    l.insert_value(10);
    l.insert_value(2);
    l.insert_value(15);
    l.insert_value(1);
    l.insert_value(0);
    l.insert_value(100);
    l.insert_value(5);
    l.insert_value(3);
    l.insert_value(7);

    l.print();
    cout<<"\n";
    l.sortList();
    l.print();
    cout<<"\n";
    cout<<l.getSize();
    return 0;
}

