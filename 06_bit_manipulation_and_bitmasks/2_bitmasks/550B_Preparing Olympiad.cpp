#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, l, r, x;
  cin >> n >> l >> r >> x;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int cnt = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    multiset<int> s;
    int dif = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        s.insert(v[i]);
        dif += v[i];
      }
    }
    if (s.size() >= 2 and dif >= l and dif <= r) {
      if (abs(*s.begin() - *s.rbegin()) >= x) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
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