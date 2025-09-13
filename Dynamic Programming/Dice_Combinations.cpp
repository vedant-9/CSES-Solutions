// Count the number of ways to construct sum n by throwing a dice one or more times.
// Each throw produces an outcome between 1 and 6.
// 3 -> 111 , 12, 21, 3  -> 4
 
#include <bits/stdc++.h>
using namespace std;
 
const int N=1e6+5;
const int mod=1e9+7;
int dp[N];
 
// int rec(int rem) {
//     if(rem==0) return 1;
//     int &ans=dp[rem];
//     if(ans!=-1) return ans;
//     ans=0;
//     for(int i=1;i<=6;i++) {
//         if(rem-i>=0) ans=(ans%mod+rec(rem-i)%mod)%mod;
//     }
//     return ans;
// }
 
int main()
{
    int n;
    cin>>n;
    // memset(dp,-1,sizeof(dp));
    // cout<<rec(n);
 
    dp[1]=1; dp[2]=2; dp[3]=4; dp[4]=8; dp[5]=16; dp[6]=32;
    if(n<=6) {
        cout<<dp[n]; return 0;
    }
 
    for(int i=7;i<=n;i++) {
        for(int j=1;j<=6;j++) {
            dp[i]=(dp[i]%mod+dp[i-j]%mod)%mod;
        }
    }
    cout<<dp[n];
 
    return 0;
