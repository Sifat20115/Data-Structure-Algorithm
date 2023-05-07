#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int coin[N], store[N],countt[N];
int p =0;

int gono(int n)
{
    int q=0;
    for(int i=0; i<N; i++)
    {
        if(n==coin[i])
        {
            q++;
        }
    }
    return q*n;
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
    store[0] = 0;
    store[1] = gono(1);
    for(int i =2; i<=p; i++)
    {
        store[i] = max(store[i-1],store[i-2]+gono(i));
    }

    cout<<store[p];
    return 0;
}
