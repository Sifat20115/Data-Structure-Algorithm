#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int store[N];

int main()
{
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
    {
        store[i] = -1;  // mark all states as unvisited
    }
    store[1] = 1;
    store[2] = 1;
    for(int i=3; i<=n; i++)
    {
        store[i] = store[i-1]+store[i-2];
    }
    cout<<store[n];

    return 0;
}


