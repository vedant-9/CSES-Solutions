#include <bits/stdc++.h>
using namespace std;
 
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
 
int main()
{
    int n,m; cin>>n>>m;
    char a[n][m]; for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j]=='.') {
                queue<pair<int,int>> q; q.push({i,j});
                while(!q.empty()) {
                    auto cur=q.front(); q.pop();
                    int x=cur.first,y=cur.second;
                    for(int d=0;d<4;d++) {
                        int nx=x+dx[d],ny=y+dy[d];
                        if(nx>=0 and nx<n and ny>=0 and ny<m and a[nx][ny]=='.') {
                            a[nx][ny]='#';
                            q.push({nx,ny});
                        }
                    }
                }
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
