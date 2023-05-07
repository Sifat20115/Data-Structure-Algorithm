#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
int n,e,change=0;
vector< pair<int,int> > graph[N];
int parent[n];

int d[N],parent[N];
void ballmanFord(int src)
{
    for(int i=1; i<=n; i++)
    {
        d[i]=INF;
    }
    d[src] = 0;
    parent[src] = 0;
    for(int i=1;i<=n;i++)
    {
         for(int j=1;j<=n;j++)
         {
             for(auto link : graph[j])
             {
                int node = j;
                int linkNode = link.first;
                int linkNodeCost = link.second;

                if(d[node]+linkNodeCost<d[linkNode])
                {
                    d[linkNode] = d[node]+linkNodeCost;
                    if(i==n)
                    {
                        change=linkNode;
                    }
                    parent[linkNode] = node;
                }
             }
         }
    }

}
int main()
{

    cin>>n>>e;

    for(int i=0; i<e; i++)
    {
        int nId,goTo,cost;

        cin>>nId>>goTo>>cost;
        graph[nId].push_back({goTo,cost});
    }

    ballmanFord(1);

    if(change!=0)
    {
        cout<<"\n";
        cout<<"Yes ";
        cout<<"\n";

        for(int i=1;i<n;i++)
        {
            change = parent[change];
        }
        int hold = change;
        vector<int> path;
        path.push_back(change);
        while(true)
        {
            change = parent[change];
            path.push_back(change);
            if(change==hold)
            {
                break;
            }
        }
        reverse(path.begin(),path.end());
        for(int p : path)
        {
            cout<<p<<" ";
        }
        return 0;

    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            cout<<d[i]<<" ";
        }
    }
    vector<int> path;
    int destNode;
    cin>>destNode;

    cout<<"\n";
    cout<<"Path :- ";

    while(true)
    {
        path.push_back(destNode);
        destNode = parent[destNode];
        if(destNode==1)
        {
            path.push_back(destNode);
            break;
        }
    }
    reverse(path.begin(),path.end());
    for(int p : path)
    {
        cout<<p<<" ";
    }


    return 0;
}

