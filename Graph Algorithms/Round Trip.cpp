#include <bits/stdc++.h>
using namespace std;
 
const int N=1e5+5;
vector<int> adj[N];
int par[N],vis[N];
int n,m; 
 
void dfs(int u, int p) {
    par[u]=p; vis[u]=1;
    for(int v:adj[u]) {
        if(!vis[v]) dfs(v,u);
        else if(v!=p) {
            vector<int> cyc; int x=u; cyc.push_back(x);
            while(par[x]!=v) {
                x=par[x]; cyc.push_back(x);
            }
            cyc.push_back(v); cyc.push_back(u);
            cout<<cyc.size()<<endl;
            for(int i=0;i<cyc.size();i++) cout<<cyc[i]<<" ";
            exit(0);
        }
    }
}
 
int main()
{
    cin>>n>>m; 
    for(int i=0;i<m;i++) { int u,v; cin>>u>>v; adj[u].push_back(v); adj[v].push_back(u);}
    for(int i=1;i<=n;i++) {
        if(!vis[i])
            dfs(i,-1);
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
