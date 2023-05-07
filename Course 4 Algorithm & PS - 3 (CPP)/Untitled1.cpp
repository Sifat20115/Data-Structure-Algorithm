#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int main()
{
    int n,p=0;
    cin >> n;

    while(n!=1)
    {
        n = n-1;
        p++;
    }

    cout<<store[n];
    return 0;
}
