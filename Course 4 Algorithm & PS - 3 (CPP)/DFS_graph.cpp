#include<bits/stdc++.h>
using namespace std;
const int n = 1e5;//Important
int visited[n];

vector<int> graph[n];

void dfs(int node)
{
    cout<<node<<" ";
    visited[node] = 1;

    for(int under_node: graph[node])
    {
        if(visited[under_node] == 0)
        {
            dfs(under_node);
        }
    }
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
    dfs(2);
    return 0;
}

