#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int x, y, n;
    cin >> x >> y >> n;
    cout << power(x, y, n) << endl;
  }
  return 0;
}