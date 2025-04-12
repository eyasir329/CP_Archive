#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);  // not possible to make that pair
  for (int i = 0; i < m; i++) {
    cin >> edges[i].first >> edges[i].second;
  }
  set<int> s;
  for (auto [x, y] : edges) {
    s.insert(x);
    s.insert(y);
  }
  int center = -1;
  for (int i = 1; i <= n; i++) {
    if (s.find(i) == s.end()) {
      center = i;
      break;
    }
  }
  s.clear();
  for (int i = 1; i <= n; i++) {
    if (i != center) {
      s.insert(i);
    }
  }
  cout << s.size() << endl;
  for (auto x : s) {
    cout << center << " " << x << endl;
  }
  return 0;
}