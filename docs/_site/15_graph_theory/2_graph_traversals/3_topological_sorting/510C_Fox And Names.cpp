#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int getIndex(char c)
{
  return c - 'a';
}

bool cycleDetect(int node, vector<int> vis, vector<int> adj[])
{
  vis[node] = 2;
  for (auto it : adj[node])
  {
    if (vis[it] == 0)
    {
      if (cycleDetect(it, vis, adj))
      {
        return true;
      }
    }
    else if (vis[it] == 2)
    {
      return true;
    }
  }
  vis[node] = 1;
  return false;
}

// code for kahn's algorithm
void topoSort(int node, vector<int> adj[], vector<int> &indeg, vector<int> &vis)
{
  vis[node] = 1;
  queue<int> q;
  q.push(node);
  cout << char('a' + node);
  while (q.empty() == false)
  {
    int x = q.front();
    q.pop();
    for (auto it : adj[x])
    {
      indeg[it]--;
      if (indeg[it] == 0)
      {
        q.push(it);
        cout << char('a' + it);
        vis[it] = 1;
      }
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<string> names(n);
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    names[i] = s;
  }

  vector<int> adj[26];
  vector<int> indeg(26, 0);

  for (int i = 0; i < n - 1; i++)
  {
    string s1 = names[i];
    string s2 = names[i + 1];

    for (int j = 0; j < s1.size(); j++)
    {
      if (j >= s2.size())
      {
        cout << "Impossible" << endl;
        return;
      }
      if (s1[j] != s2[j])
      {
        adj[getIndex(s1[j])].push_back(getIndex(s2[j]));
        indeg[getIndex(s2[j])]++;
        break;
      }
    }
  }
  vector<int> vis(26, 0);
  for (int i = 0; i < 26; i++)
  {
    if (vis[i] == 0)
    {
      if (cycleDetect(i, vis, adj))
      {
        cout << "Impossible" << endl;
        return;
      }
    }
  }
  for (int i = 0; i < 26; i++)
  {
    vis[i] = 0;
  }

  for (int i = 0; i < 26; i++)
  {
    if (indeg[i] == 0 and vis[i] == 0)
    {
      topoSort(i, adj, indeg, vis);
    }
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
    solve();
  }

  return 0;
}