#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int store[N];

int fib(int n)
{
    if(n<=2)
    {
        return 1;
    }
    if(store[n] != -1)
    {
        return store[n];
    }

    store[n] = fib(n-1) + fib(n-2);
    return store[n];
}

int main()
{
    int n;
    cin>>n;

    for(int i = 1 ; i <= n ; i++)
    {
        store[i] = -1;  // mark all states as unvisited
    }
    cout << fib(n) << endl;

    return 0;
}
