### Graph Traversals

- DFS
<pre>
- graph can have cycle (unlike tree), so we need a visited[] array
</pre>

```cpp
void dfs(int cur, vector<vector<int>>&edges, vector<bool>&vis) {
    vis[cur] = true;
    cout << cur << " ";
    for (auto e : edges[cur]) {
        if (!vis[e]) {
            dfs(e, edges, vis);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m; // no. of nodes, edges
    vector<vector<int>>edges(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; //0 based indexing
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<bool>visited(n, false);
    dfs(0, edges, visited);
}
```

![dfs_traversal](https://miro.medium.com/v2/resize:fit:502/1*eyqACQAziXkSuMNmMeTa6A.png)

- BFS (Single source and Multi source)
<pre>
- Uses a queue to explore nodes level by level.
</pre>

```cpp
void bfs(int start, vector<vector<int>>& edges, vector<bool>& vis) {
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (auto e : edges[cur]) {
            if (!vis[e]) {
                vis[e] = true;
                q.push(e);
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m; // number of nodes and edges
    vector<vector<int>> edges(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // 0-based indexing
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, edges, visited);
        }
    }
}
```
