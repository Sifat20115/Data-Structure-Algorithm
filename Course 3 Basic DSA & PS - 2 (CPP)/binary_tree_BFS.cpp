#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int id;
    node *left;
    node *right;
    node *parent;
};
class tree{
public:
    node *root;
    node *arr[7];
    tree()
    {
        root = NULL;
    }

    node* createnode(int value)
    {
        node *newnode = new node;
        newnode->id = value;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->parent = NULL;
        return newnode;
    }
    void bintree()
    {

        arr[0] = createnode(1);
        arr[1] = createnode(2);
        arr[2] = createnode(3);
        arr[3] = createnode(4);
        arr[4] = createnode(5);
        arr[5] = createnode(6);
        arr[6] = createnode(7);

        arr[0]->left = arr[1];
        arr[0]->right = arr[2];
        arr[1]->parent = arr[0];
        arr[1]->left = arr[3];
        arr[1]->right = arr[4];
        arr[2]->parent = arr[0];
        arr[2]->left = arr[5];
        arr[2]->right = arr[6];

        arr[3]->parent = arr[1];
        arr[4]->parent = arr[1];

        arr[5]->parent = arr[2];
        arr[6]->parent = arr[2];

        root = arr[0];
    }
    void print()
    {
        queue<node*>q;
        q.push(root);
        int i = 0;
        while(!q.empty())
        {
            node *a = q.front();
            q.pop();
            int p=-1,l=-1,r=-1;

            if(a->parent!=NULL)
            {
                p = a->parent->id;
            }
            if(a->left!=NULL)
            {
                l = a->left->id;
                q.push(a->left);
            }
            if(a->right!=NULL)
            {
                r = a->right->id;
                q.push(a->right);
            }
            if(a->parent==NULL)
            {
                cout<<"Node "<<i<<" Nijei parent Left child holo "<<l<<" Right child holo "<<r<<"\n";
            }
            else
            {
                cout<<"Node "<<i<<" er parent holo "<<p<<" Left child holo "<<l<<" Right child holo "<<r<<"\n";
            }
            i++;
        }
    }


};

int main()
{
    tree t1;
    t1.bintree();
    t1.print();




    return 0;
}
