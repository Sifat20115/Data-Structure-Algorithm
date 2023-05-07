#include<bits/stdc++.h>
using namespace std;

const int N = 2001;

int visited[N][N];
int maze[N][N];
int c,r;
int addx[] = {0,0,-1,1};
int addy[] = {1,-1,0,0};
int room=0,len=0,temp=0;

bool check(pair<int,int> a)
{
    int x = a.first;
    int y = a.second;
    if(maze[x][y] == -1) {
        return false;
    }
    return true;
}
bool is_inside(pair<int, int>a)
{
    int x = a.first;
    int y = a.second;

    if(x >= 0 && x < c && y >= 0 &&  y < r) {
        return true;
    }
    return false;
}


void bfs(pair<int,int> koro)
{
    queue< pair<int, int> >q;
    visited[koro.first][koro.second] = 1;
    temp++;
    q.push(koro);

    while(!q.empty())
    {
        pair<int,int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i=0; i<4; i++)
        {
            int newx = x+addx[i];
            int newy = y+addy[i];

            pair<int,int>lrud = {newx, newy};

            if(check(lrud) && is_inside(lrud) && visited[newx][newy] == 0)
            {
                visited[newx][newy] = 1;
                temp++;
                q.push(lrud);
            }
        }

    }
    if(temp>len)
    {
        len = temp;
        temp = 0;
    }

}

pair<int,int> khali()
{
    for(int i=0; i<c; i++)
    {
        for(int j=0; j<r; j++)
        {
            if(visited[i][j] == 0 && maze[i][j] == 0)
            {
                return {i,j};
            }
        }
    }
    return {-1,-1};
}
int main()
{
    cin >> c >> r;
    for(int i=0; i<c; i++)
    {
        string s;
        cin>>s;

        for(int j=0; j<r; j++)
        {
            if(s[j] == '#')
            {
                maze[i][j] = -1;
            }
        }
    }
    while(true)
    {
        pair<int,int> khaliJaga = khali();
        if(khaliJaga == pair<int,int>(-1, -1))
        {
            break;
        }
        room++;
        bfs(khaliJaga);

    }
    cout<<"\n";
    cout<<"Room - "<<room<<"\n";
    cout<<"Length of the longest room - "<<len<<"\n";

    return 0;
}

