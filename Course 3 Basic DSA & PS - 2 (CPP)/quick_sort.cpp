#include <bits/stdc++.h>
using namespace std;
vector<int> quick_sort(vector<int>&arr)//2,3,1
{
    if(arr.size()<=1)
    {
        return arr;
    }
    int pivot = rand()%(arr.size());//2//1

    vector<int>a;
    vector<int>b;
    for(int i=0;i<arr.size();i++)
    {
        if(i==pivot)
        {
            continue;
        }
        if(arr[i]<=arr[pivot])
        {
            a.push_back(arr[i]);
        }
        else
        {
            b.push_back(arr[i]);
        }
    }
    vector<int>a1 = quick_sort(a);//faka
    vector<int>b1 = quick_sort(b);//3,2
    vector<int>final_arr;
    for(int i=0;i<a1.size();i++)
    {
        final_arr.push_back(a1[i]);
    }
    final_arr.push_back(arr[pivot]);
    for(int i=0;i<b1.size();i++)
    {
        final_arr.push_back(b1[i]);
    }
    return final_arr;
}
int main()
{
    vector<int>a={2,3,1,7,42,9,10,33,1};
    vector<int>ans=quick_sort(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
