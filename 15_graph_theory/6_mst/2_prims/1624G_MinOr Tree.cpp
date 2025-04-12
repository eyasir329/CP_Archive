#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int cnt = 0;

void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis)
{
  vis[node] = 1;
  cnt++;
  for (auto it : adj[node])
  {
    if (vis[it.first])
    {
      continue;
    }
    dfs(it.first, adj, vis);
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;                             // num of nodes(vertices) and edges
    vector<vector<pair<int, int>>> adj(n + 1); // adjacent list -> vector of pair
    for (int i = 0; i < m; i++)
    {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    int ans = (1 << 30) - 1; // max ans can have - all 0000
    vector<int> vis(n + 1);
    vector<vector<pair<int, int>>> temp(n + 1);
    for (int bit = 29; bit >= 0; bit--)
    {
      for (int i = 1; i <= n; i++)
      {
        temp[i].clear();
        for (auto it : adj[i])
        {
          if (((it.second >> bit) & 1) == 0)
          { // check bitTH digit of wt is zero or not
            temp[i].push_back(it);
          }
        }
      }
      ans -= (1 << bit);
      fill(vis.begin(), vis.end(), 0);
      cnt = 0;
      dfs(1, temp, vis); // check if it possible to vis all node using this combination
      if (cnt < n)
      {
        ans += (1 << bit); // if not vis all node-> it can't possible
      }
      if (((ans >> bit) & 1) == 0)
      {
        adj = temp; // changing adjacent to temp
      }
    }
    cout << ans << endl;
  }

  return 0;
}