#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int store[N];
int stone_weight[N];

int stone(int n)
{
    if(n<=1)
    {
        return 0;
    }

    if(store[n] != -1)
    {
        return store[n];
    }
    int ans1 = stone(n-1) + abs(stone_weight[n-1] - stone_weight[n]);
    if(n==2)
    {
        store[n] = ans1;
        return store[n];
    }
    int ans2 = stone(n-2) + abs(stone_weight[n-2] - stone_weight[n]);

    int finalAns = min(ans1,ans2);

    store[n] = finalAns;

    return store[n];
}

int main()
{
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>stone_weight[i];  // mark all states as unvisited
    }
    for(int i = 1 ; i <= n ; i++)
    {
        store[i] = -1;  // mark all states as unvisited
    }

    cout<<stone(n);

    return 0;
}


