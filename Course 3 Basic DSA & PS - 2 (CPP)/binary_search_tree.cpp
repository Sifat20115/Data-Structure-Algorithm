#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int id;
    node *left;
    node *right;
    node *parent;
};
class tree
{
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
        node *piche = NULL;
        node *aage = root;

        while(aage!=NULL)
        {
            if(newnode->id > aage->id)
            {
                piche = aage;
                aage = aage->right;
            }
            else
            {
                piche = aage;
                aage = aage->left;
            }
        }
        if(newnode->id > piche->id)
        {
            piche->right = newnode;
            newnode->parent = piche;
        }
        else
        {
            piche->left = newnode;
            newnode->parent = piche;
        }
    }
    bool Search(int id)
    {
        node *piche = NULL;
        node *aage = root;
        while(aage!=NULL)
        {
            if(aage->id == id)
            {
                return true;
            }
            if(aage->id > id)
            {
                piche = aage;
                aage = aage->left;
            }
            else
            {
                piche = aage;
                aage = aage->right;
            }

        }
        if(aage==NULL)
        {
            return false;
        }

    }
    void delete_node(int id)
    {
        int k =0;
        node *piche = NULL;
        node *aage = root;
        while(aage!=NULL)
        {
            if(aage->id > id)
            {
                piche = aage;
                aage = aage->left;
            }
            else
            {
                piche = aage;
                aage = aage->right;
            }
            if(aage->id == id)
            {
                break;
            }
        }

        if(aage==NULL)
        {
            cout<<"Node is not found";
            return;
        }
        if((aage->left != NULL) && (aage->right == NULL))
        {
            node *temp = aage;
            aage = aage->left;
            if(temp->id < piche->id)
            {
                piche->left = aage;
                aage->parent = piche;
            }
            else
            {
                piche->right = aage;
                aage->parent = piche;
            }
            delete temp;
            return;
        }
        else if((aage->left == NULL) && (aage->right != NULL))
        {
            node *temp = aage;
            aage = aage->right;
            if(temp->id < piche->id)
            {
                piche->left = aage;
                aage->parent = piche;
            }
            else
            {
                piche->right = aage;
                aage->parent = piche;
            }
            delete temp;
            return;
        }
        else if((aage->left == NULL) && (aage->right == NULL))
        {
            if(aage->id < piche->id)
            {
                piche->left = NULL;
            }
            else
            {
                piche->right = NULL;
            }
            delete aage;
            return;
        }
        else
        {
            node *temp = aage->right;
            while(temp->left != NULL)
            {
                temp = temp->left;
            }
            int s = temp->id;
            delete_node(s);
            aage->id = s;
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
            cout<<a->id<<" ";
            if(a->left!=NULL)
            {
                q.push(a->left);
            }
            if(a->right!=NULL)
            {
                q.push(a->right);
            }
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
    t1.make_tree(5);
    t1.make_tree(3);
    t1.make_tree(7);
    t1.make_tree(1);
    t1.make_tree(4);
    t1.make_tree(6);
    t1.make_tree(8);

    t1.bfs_print();

    cout<<"\n";
    t1.bfs_print();

    cout<<t1.Search(10);


    return 0;
}
