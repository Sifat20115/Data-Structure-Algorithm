//https://www.spoj.com/problems/FARIDA/en/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int store[N],diamond[N];

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
    store[1] = diamond[1];
    store[2] = max(store[1],diamond[2]);

    for(int i=3; i<=p; i++)
    {
        store[i] = max(store[i-1],store[i-2]+diamond[i]);
    }

    cout<<store[p];
    return 0;
}

