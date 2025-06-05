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
    int n; cin>>n;
    std::vector<int> v(n);
    for(auto &x:v) cin>>x;
    map<int,int>m;
    for(int i=0;i<n;i++){
        m[v[i]]++;
    }
    int max_cnt = 0;
    for(auto x:m){
        if(x.ss>=max_cnt){
            max_cnt = x.ss;
        }
    }
    int ot_cnt = sz(m);
    if(ot_cnt==max_cnt){
        cout<<max_cnt-1<<endl;
    }else if(ot_cnt>max_cnt){
        cout<<min(ot_cnt-1,max_cnt)<<endl;
    }else{
        cout<<min(ot_cnt,max_cnt-1)<<endl;
    }
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