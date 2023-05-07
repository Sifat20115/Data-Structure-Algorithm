#include<bits/stdc++.h>
using namespace std;
vector<int> merge_sort(vector<int> &arr)
{
    if(arr.size()<=1)
    {
        return arr;
    }
    int mid = arr.size()/2;
    vector<int>a;
    vector<int>b;
    for(int i=0;i<mid;i++)
    {
        a.push_back(arr[i]);//2
    }
    for(int i=mid;i<arr.size();i++)
    {
        b.push_back(arr[i]);//1
    }
    vector<int>a1 = merge_sort(a);
    vector<int>b1 = merge_sort(b);
    vector<int>sort_arr;
    int idxa=0;
    int idxb=0;
    for(int i=0;i<arr.size();i++)//2,1
    {
        if(idxb==b1.size())
        {
            sort_arr.push_back(a1[idxa]);
            idxa++;
        }
        else if(idxa==a1.size())
        {
            sort_arr.push_back(b1[idxb]);
            idxb++;
        }
        else if(a1[idxa]>=b1[idxb])
        {
            sort_arr.push_back(b1[idxb]);
            idxb++;
        }
        else
        {
            sort_arr.push_back(a1[idxa]);
            idxa++;
        }
    }
    return sort_arr;
}
int main()
{
    vector<int> a = {2,3,1,7,42,9,10,33,1};
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    vector<int> ans = merge_sort(a);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
