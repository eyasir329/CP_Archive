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
    string s; cin >> s;
    // print(s);
    for(int i=1;i<sz(s);i++){
        if(s[i]=='B' and i-1>=0){
            // cout<<s[i-1]<<i-1<<s[i]<<i<<" ";
            s.erase(s.begin()+i);
            s.erase(s.begin()+i-1);
            i-=2;
        }
    }
    // print(s);
    cout << sz(s) << endl;
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