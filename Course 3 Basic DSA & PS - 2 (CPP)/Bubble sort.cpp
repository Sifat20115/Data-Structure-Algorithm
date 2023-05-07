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
    for(int i=0;i<n;i++)//3,2,1,5,4
    {
        //cout<<i+1<<": \n";
        for(int j=1;j<n-i;j++)
        {
            if(arr[j-1]>arr[j])
            {
                k++;
                swap(arr[j-1],arr[j]);
            }
            //for(int p=0;p<n;p++)
            //{
                //cout<<arr[p]<<" ";
            //}
            //cout<<"\n";
        }
        if(k!=0)
        {
            k=0;
        }
        else{
            break;
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
