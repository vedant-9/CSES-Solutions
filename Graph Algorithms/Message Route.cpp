#include <bits/stdc++.h>
using namespace std;
 
const int N=1e5+5;
vector<int> adj[N];
int par[N];
int n,m,u,v; 
 
int main()
{
    cin>>n>>m; 
    for(int i=0;i<m;i++) {cin>>u>>v; adj[u].push_back(v); adj[v].push_back(u);}
    queue<int> q; q.push(1); par[1]=-1;
    while(!q.empty()) {
        auto cur=q.front(); q.pop();
        if(cur==n) break;
        for(auto next:adj[cur]) {
            if(!par[next]) {
                par[next]=cur; q.push(next);
            }
        }
    }
    if(par[n]) {
        vector<int> path; int x=n;
        for(;x!=-1;x=par[x]) path.push_back(x);
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(auto x:path) cout<<x<<" ";
    } else cout<<"IMPOSSIBLE";
    return 0;
}
