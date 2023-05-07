#include<bits/stdc++.h>
using namespace std;
const int n = 1e5;//Important
int visited[n];

vector<int> graph[n];

void bfs(int node)
{
    queue<int> nodes;
    visited[node] = 1;
    nodes.push(node);

    while(!nodes.empty())
    {
        int head = nodes.front();//0
        cout<<head<<" ";
        nodes.pop();
        for(int i : graph[head])
        {
            if(visited[i]==0)
            {
                nodes.push(i);
                visited[i] = 1;
            }
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
    bfs(2);
    return 0;
}


