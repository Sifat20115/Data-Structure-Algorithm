#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int p = 0;
int arr[N];

int solve(int n)///3
{
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i=1;i<=3;i++)
    {
        int ans = solve(n-arr[i]);
        if(ans != INT_MAX)
        {
            mini = min(mini,1+ans);
        }
    }
    return mini;
}
int main()
{
    int n;
    cin>>n;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    cout<<solve(n);///3

    return 0;
}
