#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int store[N];
int stone_weight[N];

int main()
{
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>stone_weight[i];  // mark all states as unvisited
    }
    store[1] = 0;

    for(int i = 2 ; i <= n ; i++)
    {
        if(i==2)
        {
            store[i] = abs(stone_weight[i-1] - stone_weight[i]);
            continue;
        }
        int ans1 = store[i-1] + abs(stone_weight[i-1] - stone_weight[i]);
        int ans2 = store[i-2] + abs(stone_weight[i-2] - stone_weight[i]);
        store[i] = min(ans1,ans2);
    }

    cout<<store[n];

    return 0;
}


