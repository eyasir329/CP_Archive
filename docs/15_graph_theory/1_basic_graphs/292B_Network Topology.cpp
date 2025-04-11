#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<int> adj[n];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);  // non directed graph
    adj[v].push_back(u);
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[adj[i].size()]++;
  }

  if (mp[1] == 2 and mp[2] == n - 2) {
    cout << "bus topology" << endl;
  } else if (mp[2] == n) {
    cout << "ring topology" << endl;
  } else if (mp[1] == n - 1 and mp[n - 1] == 1) {
    cout << "star topology" << endl;
  } else {
    cout << "unknown topology" << endl;
  }
  return 0;
}