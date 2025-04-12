#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
  // directed acyclic graph,
  vector<int> adj[n];
  set<int> s;
  vector<int> node0;  // initial node sequence
  map<int, int> indeg, outd;
  for (auto v : edges) {
    adj[v[0]].push_back(v[1]);
    indeg[v[1]]++;
    outd[v[0]]++;
    if (s.find(v[0]) == s.end()) {
      node0.push_back(v[0]);  // for removing duplicate
      s.insert(v[0]);
    }
  }
  vector<int> node;  // result node
  vector<bool> visited(n, false);
  queue<int> q;
  // min indegree first
  sort(node0.begin(), node0.end(), [&indeg, &outd](int a, int b) {
    if (indeg[a] == indeg[b]) {
      return outd[a] > outd[b];
    }
    return indeg[a] < indeg[b];
  });
  for (auto n1 : node0) {
    if (!visited[n1]) {
      node.push_back(n1);
      visited[n1] = true;
      q.push(n1);
      while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto x : adj[now]) {
          if (!visited[x]) {
            visited[x] = true;
            q.push(x);
          }
        }
      }
    }
  }
  return node;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}