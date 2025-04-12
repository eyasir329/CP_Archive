#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;
  if (n & 1 or n < 4) {
    cout << -1 << endl;
  } else {
    int mn = n / 6;
    if (n % 6) {
      mn++;
    }
    int mx = n / 4;
    cout << mn << " " << mx << endl;
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}