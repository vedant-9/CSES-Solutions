#include <bits/stdc++.h>
using namespace std;
 
const int N=1e5+5;
vector<int> adj[N];
int color[N];
int n,m,u,v; 
 
int main()
{
    cin>>n>>m; 
    for(int i=0;i<m;i++) {cin>>u>>v; adj[u].push_back(v); adj[v].push_back(u);}
    for(int i=1;i<=n;i++) {
        if(color[i]) continue;
        queue<int> q; q.push(i); color[i]=-1;
        while(!q.empty()) {
            auto cur=q.front(); q.pop();
            for(auto next:adj[cur]) {
                if(!color[next]) {
                    color[next]=-color[cur]; q.push(next);
                } else if(color[next]==color[cur]) return cout<<"IMPOSSIBLE",0;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<color[i]+1+(color[i]<0)<<" ";
    return 0;
}
