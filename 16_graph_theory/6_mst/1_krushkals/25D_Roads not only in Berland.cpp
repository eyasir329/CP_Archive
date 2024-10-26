#include <bits/stdc++.h>
using namespace std;

class dsu
{
  vector<int> parent, size, rank;

public:
  dsu(int n)
  {
    for (int i = 0; i <= n; i++)
    {
      parent.push_back(i);
      size.push_back(1);
      rank.push_back(0);
    }
  }

  int findPar(int node)
  {
    if (parent[node] == node)
    {
      return node;
    }
    // path compression
    return parent[node] = findPar(parent[node]);
  }

  void unionSize(int u, int v)
  {
    int pu = findPar(u);
    int pv = findPar(v);
    if (pu == pv)
    {
      return;
    }
    // attach smaller to bigger
    if (size[pu] < size[pv])
    {
      parent[pu] = pv;
      size[pv] += size[pu];
    }
    else
    {
      parent[pv] = pu;
      size[pu] += size[pv];
    }
  }

  void unionRank(int u, int v)
  {
    int pu = findPar(u);
    int pv = findPar(v);
    if (pu == pv)
    {
      return;
    }
    if (rank[pu] == rank[pv])
    {
      parent[pu] = pv;
      rank[pu]++;
    }
    else if (rank[pu] < rank[pv])
    {
      parent[pu] = pv;
    }
    else
    {
      parent[pv] = pu;
    }
  }
};

void solve()
{
  int n;
  cin >> n;

  dsu d(n);
  vector<pair<int, int>> oldRoad;

  for (int i = 0; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    int pu = d.findPar(u);
    int pv = d.findPar(v);
    if (pu != pv)
    {
      d.unionRank(u, v);
    }
    else
    {
      oldRoad.push_back({u, v});
    }
  }

  set<int> root;
  for (int i = 1; i <= n; i++)
  {
    int parNode = d.findPar(i);
    if (root.find(parNode) == root.end())
    {
      root.insert(parNode);
    }
  }
  cout << oldRoad.size() - 1 << endl;
  if (oldRoad.size() - 1)
  {
    for (int i = 0; i < oldRoad.size() - 1; i++)
    {
      auto it = root.begin();
      int p1 = *it;
      it++;
      int p2 = *it;
      cout << oldRoad[i].first << " " << oldRoad[i].second << " " << p1 << " " << p2 << endl;
      root.erase(root.begin());
    }
  }
}

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}