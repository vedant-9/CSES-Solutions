// Author - Vedant Valsangkar
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
typedef long long    ll;
typedef long double  ld;
#define int          long long
#define rep(i,s,e)   for(int i=s;i<e;i++)
#define repr(i,s,e)  for(int i=s;i>=e;i--)
#define in(a)        for(auto &i:a) cin>>i
#define out(a)       for(auto &i:a) cout<<i<<" "; cout<<endl
#define uniq(a)      a.erase(unique(all(a)),a.end())
#define all(a)       a.begin(),a.end()
#define allr(a)      a.rbegin(),a.rend()
#define endl         '\n'
 
bool per_square(ld x){if(x<0) return 0; ll sr=sqrt(x); return (sr*sr==x);}
bool is_prime(ll x){for(int i=2;i*i<=x;i++) if(x%i==0) return 0; return 1;}
 
// generic segment tree
template<typename T>
class segtree{
public:
    int size;
    vector<T> sums;
    T NEUTRAL_ELEMENT = 0;
    T merge(T a, T b){
        return a+b;
    }
    T single(int v){
        return v;
    }
    void init(int n){
        size = 1;
        while(size<n) size*=2;
        sums.assign(2*size,0LL);
    }
    void build(vector<T> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()) sums[x] = single(a[lx]);
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x] = merge(sums[2*x+1],sums[2*x+2]);
    }
    void build(vector<T> &a){
        build(a,0,0,size);
    }
    void set(int i, T v, int x, int lx, int rx){
        if(rx-lx==1){
            sums[x] = single(v);
            return;
        }
        int m = (lx+rx)/2;
        if(i<m) set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        sums[x] = merge(sums[2*x+1],sums[2*x+2]);
    }
    void set(int i, T v){
        set(i,v,0,0,size);
    }
    T calc(int l, int r, int x, int lx, int rx){
        if(lx>=r || l>=rx) return NEUTRAL_ELEMENT;
        if(lx>=l && rx<=r) return sums[x];
        int m = (lx+rx)/2;
        T s1 = calc(l,r,2*x+1,lx,m);
        T s2 = calc(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }
    T calc(int l, int r){
        return calc(l,r,0,0,size);
    }
};
 
void solve()
{
    int n,q; cin>>n>>q;
    vector<int> a(n); in(a);
 
    segtree<int> st;
    st.init(n);
    st.build(a);
 
    while(q--) {
        int t; cin>>t;
        if(t==1) {
            int i,v; cin>>i>>v; i--;
            st.set(i,v);
        } else {
            int l,r; cin>>l>>r; l--; r--;
            cout<<st.calc(l,r+1)<<endl;
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int tc = 1;
    // cin>>tc;
    for(int t=1;t<=tc;t++) {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
