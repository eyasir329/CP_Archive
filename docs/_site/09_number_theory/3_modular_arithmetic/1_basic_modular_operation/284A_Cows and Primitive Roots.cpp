#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int p;
  cin >> p;
  int ans = 0;
  for (int i = 1; i < p; i++) {
    std::vector<int> pw(p, i);
    for (int j = 2; j < p; j++) {
      pw[j] = (pw[j - 1] * i) % p;
    }
    int cnt = 0;
    for (int j = 1; j < p - 1; j++) {
      if (((pw[j] - 1) + p) % p == 0) {
        cnt++;
      }
    }
    if (cnt == 0 and ((pw[p - 1] - 1 + p) % p) == 0) {
      ans++;
    }
  }
  cout << ans << endl;
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