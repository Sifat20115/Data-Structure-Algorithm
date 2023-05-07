#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k=0;;
    cin>>n;//5
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<n;i++)//3,2,1,5,4
    {
        int idx = i;
        while(idx>=1)
        {
            if(arr[idx-1]>arr[idx])
            {
                swap(arr[idx-1],arr[idx]);
                idx--;
            }
            else{
                break;
            }

        }

        cout<<"Pass "<<i+1<<": ";
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
