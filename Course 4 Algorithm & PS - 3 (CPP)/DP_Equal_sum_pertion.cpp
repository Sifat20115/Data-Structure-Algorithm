#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int arr[N];///1,2,3

bool tSum(int sizee,int t)
{
    if(sizee==0)
    {
        if(t==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(t<0)
    {
        return false;
    }
    bool ans1 = tSum(sizee-1,t-arr[sizee]);
    bool ans2 = tSum(sizee-1,t);

    return ans1 or ans2;
}
int main()
{
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 1;
    arr[4] = 3;
    int target = 0;
    for(int i=1;i<=4;i++)
    {
        target = target + arr[i];
    }
    target = target/2;///5
    if(tSum(4,target))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }

    return 0;
}
