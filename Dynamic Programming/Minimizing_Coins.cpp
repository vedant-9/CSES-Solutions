// Target sum in minimum number of coins
// Top-down approach giving tle (recursive)
#include <bits/stdc++.h>
using namespace std;
 
const int N=1e6+1;
int dp[N];
vector<int> coins;
 
// int rec(int rem) {
//     if(rem==0) return 0;
//     int &ans=dp[rem];
//     if(ans!=INT_MAX) return ans;
//     for(auto x:coins) {
//         if(rem-x>=0)
//             ans=min(ans,rec(rem-x));
//     }
//     if(ans==INT_MAX) return ans;
//     return ++ans;
// }
 
int main()
{
    int n,tar;
    cin>>n>>tar;
    coins.resize(n);
    for(int i=0;i<N;i++) dp[i]=INT_MAX;
    for(auto &x:coins) cin>>x;
 
    dp[0]=0;
    for(int i=1;i<=tar;i++) {
        for(auto x:coins) {
            if(i-x>=0 and dp[i-x]!=INT_MAX)
                dp[i]=min(dp[i],dp[i-x]+1);
        }
    }
 
    if(dp[tar]==INT_MAX) dp[tar]=-1;
    cout<<dp[tar];
 
    // int ans = rec(tar);
    // if(ans==INT_MAX) ans=-1; 
    // cout<<ans<<endl;
 
    return 0;
}
