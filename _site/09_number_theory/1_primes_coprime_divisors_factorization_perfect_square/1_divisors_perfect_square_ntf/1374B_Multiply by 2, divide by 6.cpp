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
    int n; cin >> n;
    int mb2 = 0 , mb3 = 0;
    while (1) {
        if (n % 2 == 0) {
            n /= 2;
            mb2++;
        } else {
            break;
        }
    }
    while (1) {
        if (n % 3 == 0) {
            n /= 3;
            mb3++;
        } else {
            break;
        }
    }
    if (n > 1 || mb2 > mb3) {
        cout << -1 << endl;
    } else {
        cout << mb3 - mb2 + mb3 << endl;
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