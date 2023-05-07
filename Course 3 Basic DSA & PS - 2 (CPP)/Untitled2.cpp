#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    mp["sifat"] = 10;
    string s = "sifat";

    if (mp.find(s) == mp.end())
    {
        cout << "Yes";
    }
    else
    {
        cout<<"Neh";
    }

    return 0;
}
