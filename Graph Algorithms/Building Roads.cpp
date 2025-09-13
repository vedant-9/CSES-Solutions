#include <bits/stdc++.h>
using namespace std;
 
const int N=1e5+5;
vector<int> adj[N],ans;
int vis[N];
int n,m,u,v,x; 
 
void dfs(int cur) {
    vis[cur]=1;
    for(auto next:adj[cur]) {
        if(!vis[next]) 
            dfs(next);
    }
}
 
int main()
{
    cin>>n>>m; for(int i=0;i<m;i++){cin>>u>>v; adj[u].push_back(v); adj[v].push_back(u);}
    dfs(1);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<1<<" "<<i<<" ";
    return 0;
}
