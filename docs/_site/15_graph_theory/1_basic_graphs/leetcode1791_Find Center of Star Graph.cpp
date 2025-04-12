#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int findCenter(vector<vector<int>>& edges) {
  vector<int> adj[edges.size() + 1];
  for (auto v : edges) {
    adj[v[0] - 1].push_back(v[1] - 1);
    adj[v[1] - 1].push_back(v[0] - 1);
  }
  int center = -1;
  for (int i = 0; i < edges.size() + 1; i++) {
    if (adj[i].size() == edges.size()) {
      center = i + 1;
      break;
    }
  }
  return center;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}