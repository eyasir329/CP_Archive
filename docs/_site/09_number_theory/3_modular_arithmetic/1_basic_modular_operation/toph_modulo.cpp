#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    priority_queue<pair<ll, int>> pq;
    for (int i = 1; i <= n; i++) {
      ll x;
      cin >> x;
      a[i] = x;
      pq.push({x, i});
    }
    int q;
    cin >> q;
    while (q--) {
      ll m;
      cin >> m;
      while (pq.size() and pq.top().first >= m) {
        ll tp = pq.top().first;
        int index = pq.top().second;
        tp %= m;
        pq.pop();
        pq.push({tp, index});
      }
    }
    while (!pq.empty()) {
      auto [x, i] = pq.top();
      a[i] = x;
      pq.pop();
    }
    cout << "Case " << t << ":" << endl;
    for (int i = 1; i <= n; i++) {
      if (i == n) {
        cout << a[i] << endl;
      } else {
        cout << a[i] << " ";
      }
    }
  }
  return 0;
}