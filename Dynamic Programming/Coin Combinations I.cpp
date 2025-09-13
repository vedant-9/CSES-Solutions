#include <bits/stdc++.h>
using namespace std;
 
const int N=1e6+1;
const int mod=1e9+7;
 
int main()
{
    int n,tar;
    cin>>n>>tar;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
 
    vector<int> dp(tar+1,0);
    dp[0]=1;
    for(int i=1;i<=tar;i++) {
        for(auto x:a) {
            if(i-x>=0) {
                dp[i]+=dp[i-x];
                dp[i]%=mod;
            }
        }   
    }
    cout<<dp[tar];
 
    return 0;
}
