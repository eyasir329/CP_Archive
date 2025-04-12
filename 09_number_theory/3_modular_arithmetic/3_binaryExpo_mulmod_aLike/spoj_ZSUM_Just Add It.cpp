#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int mod = 1e7 + 7;

int binpow(int x, int y) {
  int ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1LL * ans * x) % mod;
    }
    x = (1LL * x * x) % mod;
    y >>= 1;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  while (cin >> n >> k) {
    if (n == 0 and k == 0) break;
    cout << (((binpow(n, k) + 2 * binpow(n - 1, k)) % mod + binpow(n, n)) %
                 mod +
             2 * binpow(n - 1, n - 1)) %
                mod
         << endl;
  }
  return 0;
}