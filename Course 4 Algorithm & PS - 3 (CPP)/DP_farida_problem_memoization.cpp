//https://www.spoj.com/problems/FARIDA/en/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int store[N],diamond[N];

int solve(int n)///4 | 10,5,2,1000
{
    if(store[n] != -1)
    {
        return store[n];
    }
    if(n==2)
    {
        store[n] = max(solve(n-1),diamond[n]);
        return store[n];
    }
    if(n==1)
    {
        store[n] = diamond[n];
        return store[n];
    }

    store[n] = max(solve(n-1),solve(n-2) + diamond[n]);

    return store[n];
}
int main()
{
    int p;
    cin>>p;

    for(int i=1; i<=p; i++)
    {
        store[i] = -1;
    }
    for(int i=1; i<=p; i++)
    {
        cin>>diamond[i];///10,5,2,1000
    }

    cout<<solve(p);
    return 0;
}

