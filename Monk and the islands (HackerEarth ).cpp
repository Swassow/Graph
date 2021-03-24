#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

vi ara[100001];

int vis[100001],dis[100001];

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    vis[n]=1;
    dis[n]=0;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int child : ara[curr])
        {
            if(vis[child]==0)
            {
                q.push(child);
                dis[child]=dis[curr]+1;
                vis[child]=1;
            }
        }
    }
}



int main()
{
    int t,n,m,x,y,i;

    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            ara[i].clear();
            vis[i]=0;
            dis[0]=0;
        }
        while(m--)
        {
            cin>>x>>y;
            ara[x].pb(y);
            ara[y].pb(x);

        }
        bfs(1);
        cout<<dis[n]<<endl;
    }


}
