#include<bits/stdc++.h>
using namespace std;
const int n = 1e5;//Important

int visited[n];///1-1,2-1,3-1,4
int check = -1;
vector<int> graph[n];

bool dfs(int node)
{
    visited[node] = 1;

    for(int under_node: graph[node])///2,3
    {
        if(under_node==check)
        {
            continue;
        }
        else if(visited[under_node] == 0)
        {
            check = node;//4
            bool dekho = dfs(under_node);
            if(dekho)
            {
                return true;
            }
            else
            {
                check = -1;
            }
        }
        else if(visited[under_node] == 1)
        {
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

int main()//make the graph with vector
{
    int v,e;
    cin>>v;
    cin>>e;

    for(int i=0;i<e;i++)
    {
        int l1,l2;
        cin>>l1;
        cin>>l2;

        graph[l1].push_back(l2);
        graph[l2].push_back(l1);
    }
    bool get_it = false;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            bool cycle = dfs(i);
            if(cycle)
            {
                get_it = true;
                break;
            }
        }
    }
    if(get_it==true)
    {
        cout<<"Cycle Exist\n";
    }
    else
    {
        cout<<"No Cycle\n";
    }
    return 0;
}

