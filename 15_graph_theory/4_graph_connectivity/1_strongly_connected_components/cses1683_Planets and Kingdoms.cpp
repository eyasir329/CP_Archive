#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

stack<int> st;
vector<int> temp;
vector<vector<int>> scc;

void dfs1(int node, vector<int> adj[], vector<int> &vis)
{ // pre dfs
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (vis[it] == 0)
    {
      dfs1(it, adj, vis);
    }
  }
  st.push(node);
}

void dfs2(int node, vector<int> tadj[], vector<int> &vis)
{ // post dfs
  vis[node] = 1;
  temp.push_back(node);
  for (auto it : tadj[node])
  {
    if (vis[it] == 0)
    {
      dfs2(it, tadj, vis);
    }
  }
}

void kosarajus_algo()
{
  int n, m; // no. of vertices, edges
  cin >> n >> m;
  vector<int> adj[n + 1], tadj[n + 1]; // adjacency list, transfer adjacency list
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    tadj[v].push_back(u);
  }
  vector<int> vis(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    if (vis[i] == 0)
    {
      dfs1(i, adj, vis);
    }
  }
  fill(vis.begin(), vis.end(), 0);
  while (st.empty() == false)
  {
    int node = st.top();
    st.pop();
    if (vis[node] == 0)
    {
      dfs2(node, tadj, vis);
      scc.push_back(temp);
      temp.clear();
    }
  }

  cout << scc.size() << endl;
  vector<int> ans(n + 1);
  int cnt = 1;
  for (auto it : scc)
  {
    for (auto x : it)
    {
      ans[x] = cnt;
    }
    cnt++;
  }
  for (int i = 1; i <= n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // int t; cin >> t;
  while (t--)
  {
    kosarajus_algo();
  }

  return 0;
}