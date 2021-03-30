#include<bits/stdc++.h>

using namespace std;

vector<int> ara[5001];

int vis[5001];

bool dfs(int node,int par)
{
    vis[node]=1;
    for(int child:ara[node])
    {
        if(vis[child]==0)
        {
            if(dfs(child,node)==true)
                return true;
        }
        else
        {
            if(child!=par)
                return true;
        }
    }
    return false;
}
int main()
{
    int n,i,x;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        ara[i].push_back(x);
    }
    bool flag= dfs(1,-1);
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";

}
