#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>> &edges, vector<bool> &vis, vector<int> &component)
{
  queue<int> q;
  q.push(start);
  vis[start] = true;

  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    component.push_back(cur);

    for (auto e : edges[cur])
    {
      if (!vis[e])
      {
        vis[e] = true;
        q.push(e);
      }
    }
  }
}

void solve()
{
  int n, m;
  cin >> n >> m; // number of nodes and edges
  vector<vector<int>> edges(n);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v; // 0-based indexing
    u--;
    v--;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  vector<bool> visited(n, false);
  vector<vector<int>> connectedComponents;

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      vector<int> component;
      bfs(i, edges, visited, component);
      connectedComponents.push_back(component);
    }
  }

  // Output the connected components
  int cnt = connectedComponents.size() - 1;
  cout << cnt << endl;
  if (cnt)
  {
    vector<int> path;
    for (auto &component : connectedComponents)
    {
      for (int node : component)
      {
        path.push_back(node + 1);
        break;
      }
    }
    for (int i = 0; i < (int)path.size() - 1; i++)
    {
      cout << path[i] << " " << path[i + 1] << endl;
    }
  }
}

int main()
{
  solve();
  return 0;
}