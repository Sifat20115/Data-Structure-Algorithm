#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int coin[N], store[N],countt[N];
int p =0;


int gono(int n)
{
    int q = 0;
    for(int i=0; i<N; i++)
    {
        if(n==coin[i])
        {
            q++;
        }
    }
    return q;
}


int solve(int n)
{
    if(n==2)
    {
        return max(solve(n-1),gono(n)*n);
    }
    if(n==1)
    {
        return gono(n)*n;
    }
    if(store[n] != -1)
    {
        return store[n];
    }
    store[n] = max(solve(n-1),solve(n-2)+gono(n)*n);
    return store[n];
}


int main()
{
    int n;
    cin >> n;
    for(int i=0; i<N; i++)
    {
        coin[i] = -1;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>coin[i];
    }
    for(int i=1; i<=n; i++)
    {
        if(p<coin[i])
        {
            p = coin[i];
        }
    }
    for(int i=1; i<=p; i++)
    {
        store[i] = -1;
    }


    cout<<solve(p);
    return 0;
}
