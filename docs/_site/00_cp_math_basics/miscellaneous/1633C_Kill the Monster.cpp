#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(a) a.begin(),a.end()
#define sz(a) ((int) a.size())
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define endl '\n'
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const int MOD = 1e9 + 7;

void solve() {
    int hc,dc; cin>>hc>>dc;
    int hm,dm; cin>>hm>>dm;
    int k,w,a; cin>>k>>w>>a;
    for(int i=0;i<=k;i++){
        int newhc=hc+1LL*i*a; 
        int newdc=dc+1LL*(k-i)*w;
        if((newhc+dm-1)/dm>=(hm+newdc-1)/newdc){
            yes;
            return;
        }
    }
    no;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}