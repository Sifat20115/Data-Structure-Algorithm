#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p;
    cin >> p;

    map<string, int> mp;

    for (int i = 0; i < p; i++)
    {
        string key;//sifat
        cin>>key;

        if (mp.find(key) == mp.end())
        {
            cout<<"-1";
            cout<<"/n";
        }
        else
        {
            cout<<mp[key] << " ";
        }
        mp[key] = i;
    }

    return 0;
}

