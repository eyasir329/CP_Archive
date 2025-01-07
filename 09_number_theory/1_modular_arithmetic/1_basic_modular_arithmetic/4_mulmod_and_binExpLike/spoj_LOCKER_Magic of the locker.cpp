#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int mod = 1e9 + 7;

int binpow(ll x, ll y) {
  ll ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (ans * x) % mod;
    }
    x = (x * x) % mod;
    y >>= 1;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    if (n <= 3) {
      cout << n << endl;
    } else {
      int d = n % 3;
      ll ans = 1, x = 3, y = n / 3;
      if (d == 1) {
        ans = binpow(x, y - 1);
        ans = (ans * 4) % mod;
      } else if (d == 2) {
        ans = binpow(x, y);
        ans = (ans * 2) % mod;
      } else {
        ans = binpow(x, y);
      }
      cout << ans << endl;
    }
  }
  return 0;
}