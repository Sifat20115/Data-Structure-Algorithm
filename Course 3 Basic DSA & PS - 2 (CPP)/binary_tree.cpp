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
    int p;
    node *root;
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
    void make_tree(int id)
    {
        node *newnode = createnode(id);
        if(root==NULL)
        {
            root = newnode;
            return;
        }
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node *a = q.front();
            q.pop();
            if(a->left!=NULL)
            {
                q.push(a->left);
            }
            else
            {
                a->left = newnode;
                newnode->parent = a;
                return;
            }
            if(a->right!=NULL)
            {
                q.push(a->right);
            }
            else
            {
                a->right = newnode;
                newnode->parent = a;
                return;
            }
            q.push(a->left);
        }
    }
    void bfs_print()
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
    void dfs_print(node *a)
    {
        if(a==NULL)
        {
            return;
        }
        cout<<a->id<<" ";
        dfs_print(a->left);
        dfs_print(a->right);
    }
    void dfs_inorder_print(node *a)
    {
        if(a==NULL)
        {
            return;
        }

        dfs_inorder_print(a->left);
        cout<<a->id<<" ";
        dfs_inorder_print(a->right);
    }
    void dfs_preorder_print(node *a)
    {
        if(a==NULL)
        {
            return;
        }
        cout<<a->id<<" ";
        dfs_preorder_print(a->left);
        dfs_preorder_print(a->right);
    }
    void dfs_postorder_print(node *a)
    {
        if(a==NULL)
        {
            return;
        }

        dfs_postorder_print(a->left);
        dfs_postorder_print(a->right);
        cout<<a->id<<" ";
    }


};

int main()
{
    tree t1;
    t1.make_tree(1);
    t1.make_tree(2);
    t1.make_tree(3);
    t1.make_tree(4);
    t1.make_tree(5);
    t1.make_tree(6);
    t1.make_tree(7);
    t1.dfs_print(t1.root);




    return 0;
}
