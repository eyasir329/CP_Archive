#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int n, x, y = 1; cin >> n;
    n-= 3;
    x = 2;
    while(gcd(n , x) != 1){
        n--; x++;
    }
    cout << n << " " << x << " " << y << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}