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
    // t 1e5 n 1e6
    int n; cin>>n;
    int div_count = 0;
    //n*sqrt(n)-->tle
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            div_count++;
            if(i!=n/i){
                div_count++;
            }
        }
    }
    // seive nlog(n)<</n*sqrt(n) 
    // seive in main function --> pre compilation
    cout<<div_count<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::vector<int> v(1000001,0);
    for(int i=1;i<=1000000;i++){
        for(int j=i;j<=1000000;j+=i){
            v[j]++;
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        int x; cin>>x;
        cout<<v[x]<<endl;
        // solve();
    }
    return 0;
}