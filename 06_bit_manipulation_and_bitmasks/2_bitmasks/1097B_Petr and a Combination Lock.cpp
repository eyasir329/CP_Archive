#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;
  std::vector<int> v(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    int deg = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        deg += v[i];
      } else {
        deg -= v[i];
      }
    }
    if (deg % 360 == 0) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}