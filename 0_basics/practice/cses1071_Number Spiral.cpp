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
    int x,y; cin>>x>>y;
    int ans = 0;
    if(x>=y){
        ans+= (x-1)*(x-1)*1LL;
        if(x&1){
            ans += y;
        }else{
            ans += x+(x-y);
        }
    }else{
        ans += (y-1)*(y-1)*1LL;
        if(y&1){
            ans += y+(y-x);
        }else{
            ans += x;
        }
    }
    cout<<ans<<endl;
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