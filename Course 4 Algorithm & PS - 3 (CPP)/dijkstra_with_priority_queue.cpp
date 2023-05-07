#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

vector< pair<int, int> >adj_list[N];

int d[N], visited[N],parent[N]={0};
int nodes, edges;

void dijkstra(int src) {
    for(int i = 1 ; i <= nodes ; i++) {
        d[i] = INF;
    }
    d[src] = 0;
    parent[src] = 0;
    priority_queue<pair <long long,int> > pq;
    pq.push({0,src});

    while(!pq.empty())
    {
        pair <long long,int> head = pq.top();
        pq.pop();

        int selNode = head.second;
        if(visited[selNode]==1)
        {
            continue;
        }
        visited[selNode] = 1;

        for(auto adj_entry: adj_list[selNode]) {
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;

            if(d[selNode] + edge_cst < d[adj_node]) {
                d[adj_node] = d[selNode] + edge_cst;
                pq.push({-d[adj_node],adj_node});
                parent[adj_node] = selNode;
            }
        }
    }
}

int main() {

    cin >> nodes >> edges;

    for(int i = 0 ; i < edges ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({ v, w });
        adj_list[v].push_back({ u, w });
    }

    int src = 1;
    dijkstra(src);

    for(int i = 1 ; i <= nodes ; i++) {
        cout << d[i] << " ";
    }

    cout<<endl;
    vector<int> path;
    int mark = nodes;

    while(true)
    {
        path.push_back(mark);
        mark = parent[mark];
        if(mark == src)
        {
            path.push_back(mark);
            break;
        }
    }
    reverse(path.begin(),path.end());
    cout<<"Path:- "
    for(int i : path)
    {
        cout<<i<<" ";
    }
    return 0;
}

