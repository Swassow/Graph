#include<bits/stdc++.h>
#define pb push_back
#define vi vector<int>
using namespace std;
vi ara[2001];
int vis[2001],col[2001];
bool dfs(int node,int c)
{
    vis[node]=1;
    col[node]=c;
    for(int i:ara[node])
    {
        if(vis[i]==0)
        {
            bool res= dfs(i,c^1);
            if(res==false)
            {
                return false;
            }
        }
        else
        {
            if(col[i]==col[node])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int t,n,m,i,j,tc,a,b;
    while(1)
    {
        cin>>n;
        if(n!=0)
        {
            cin>>m;
        for(i=1; i<=n; i++)
        {
            ara[i].clear();
            vis[i]=0;
        }
        for(i=1; i<=m; i++)
        {
            cin>>a>>b;
            ara[a].pb(b);
            ara[b].pb(a);

        }
        bool flag =true;
        for(i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                bool res = dfs(i,0);
                if(res==false)
                {
                    flag=false;
                    break;
                }
            }

        }
        if(flag)
        {
            cout<<"BICOLORABLE."<<endl;
        }
        else
        {
            cout<<"NOT BICOLORABLE."<<endl;
        }
        }
        else
            break;
    }
}


