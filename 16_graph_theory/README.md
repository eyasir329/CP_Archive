
![gp](gp1.png)
![gp](gp2.png)

- bipartide graph -> no odd length cycle

![gp](gp3.png)
![gp](gp4.png)
![gp](gp5.png)
![gp](gp6.png)

- dfs -> can check cycle or not

![gp](gp7.png)
![gp](gp8.png)
![gp](gp9.png)
![gp](gp10.png)


- bfs -> can find shortest path (single sources)(unweighted graph)

![gp](gp11.png)
![gp](gp12.png)
![gp](gp13.png)
![gp](gp14.png)

- for weighted graph -> dijkstra -> use priority queue (all other same)

![gp](gp15.png)
![gp](gp16.png)

ex.

- snake scales

![gp](gp17.png)
![gp](gp18.png)

> binary search, ground distance <=h,  multisources bfs... if all reacheable through that h(mid)

![gp](gp19.png)
![gp](gp20.png)

https://www.youtube.com/watch?v=yK7iTQVyiFQ

- state dijkstra (edge count even or not)














### Application of Graph


###### Application of Traversals

<pre>
- Connected Components
- Path Construction
- Cycle Detection
- Shortest Path (unweighted graph, ex. cses1193)
</pre>
<pre>Topological Sort and Strongly Connected Components are only for Directed Graph</pre>

#### Connected Components

```cpp
//connected components
void bfs(int start, vector<vector<int>>& edges, vector<bool>& vis, vector<int>& component) {
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        component.push_back(cur);

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
    vector<vector<int>> connectedComponents;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            bfs(i, edges, visited, component);
            connectedComponents.push_back(component);
        }
    }

    // Output the connected components
    cout << "Connected Components:\n";
    for (auto& component : connectedComponents) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << "\n";
    }
}
/*
1 2 3 4
5 6 7
8 9
10
*/
```

![connected_components](https://lh6.googleusercontent.com/AvJI6MEwrQF3eXS0OtWYgNtXG4H-2oMq5Fhz3Yy7VU1xAuC3uPPzGRUaKkYOKUHpRkUxDU-f5aXpehu3-K6uoGT2uHaJ4PXXh8E3BM8WkSeXpFS_zGEYrtI7ZoX7NOCThx-R4ZNl_uLKiMPCdwZ2KoE)

example:

- [cses1666_Building Roads](./2_graph_traversals/2_dfs/cses1666_Building%20Roads.cpp)

    <pre>Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
  
    Your task is to find out the minimum number of roads required, and also determine which roads should be built.
  
    no. of connected component - 1</pre>

- https://codeforces.com/problemset/problem/1534/C (SCC + Combinatorics)

#### Cycles Detecting

```cpp
//if graph is disconnected then run dfs for every node
int n;
vector<vector<int>> adj;
vector<int> color, parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic\n";
    } else {
        vector<int> cycle;
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        cycle.push_back(cycle_end); // Add cycle end for clarity

        reverse(cycle.begin(), cycle.end());
        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << "\n";
    }
}

int main() {
    cin >> n;
    adj.resize(n);
    int m;
    cin >> m; // number of edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    find_cycle();
}
//using bfs
```

---

#### Path Construction

```cpp
vector<int> find_path(int start, int end, vector<vector<int>>& adj, int n) {
    vector<int> parent(n, -1);
    queue<int> q;
    vector<bool> visited(n, false);

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == end) break;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // Reconstruct the path
    vector<int> path;
    if (!visited[end]) {
        cout << "No path found\n";
        return path;
    }

    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, m;
    cin >> n >> m; // number of nodes and edges
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int start, end;
    cin >> start >> end;

    vector<int> path = find_path(start, end, adj, n);

    if (!path.empty()) {
        cout << "Path found: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << "\n";
    }
}
```

#### Shortest Path for Unweighted Graph

example:

- [cses1193_Labyrinth](./2_graph_traversals/1_bfs/cses1193_Labyrinth.cpp)

    <pre>You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.
    
    - dfs works for the path construction (doesn't give shortest path)
    - bfs for shortest path (because it goes to level-wise)
  
    unweighted graph shortest path
    </pre>

#### Bipartite Graphs

https://cp-algorithms.com/graph/bipartite-check.html

<code>A bipartite graph is a graph whose vertices can be divided into two disjoint sets so that every edge connects two vertices from different sets (i.e. there are no edges which connect vertices from the same set).
</code>

###### Properties

<pre>You are given an undirected graph. Check whether it is bipartite, and if it is, output its sides.</pre>
<pre>
- Odd Length Cycles (can't be)
- A Tree is always bipartile
</pre>

```cpp
//bipartile check
int n;
vector<vector<int>> adj;

vector<int> side(n, -1);
bool is_bipartite = true;
queue<int> q;
for (int st = 0; st < n; ++st) {
    if (side[st] == -1) {
        q.push(st);
        side[st] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (side[u] == -1) {
                    side[u] = side[v] ^ 1;
                    q.push(u);
                } else {
                    is_bipartite &= side[u] != side[v];
                }
            }
        }
    }
}

cout << (is_bipartite ? "YES" : "NO") << endl;
```

![bipoartile_graph](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcToD16ZGa1318i444cgJQDU3J-nkmeF_rIXQw&s)

example:

#

#### Topological Sorting (for only DAG)

<pre>
- it is a linear ordering of vertices such that if there is an edge between u to v, then u should come before v.
- there can be multiple topological sort in graph.
- topological sort is valid only directed ***asylic*** graph(DAG).
</pre>

![topological_sort](https://miro.medium.com/v2/resize:fit:720/format:webp/1*0jRSNI2zo30sENk2qlqEvw.png)

https://yuminlee2.medium.com/topological-sort-cf9f8e43af6a

- DFS Method
<pre>
- if we see the last element of the topo. sort, then it must have some edges coming towards it.
- deepest node possible in the DFS.
</pre>

```cpp
//code for topological sort using DFS
void dfs(int node, vector<int>&vis, stack<int>&st, vector<int>adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (vis[it] == 0) {
            dfs(it, vis, st, adj);
        }
    }
    st.push(node);
}

void topologicalSort() {
    int n, m; //no. of vertices, edges
    cin >> n >> m;
    vector<int> adj[n + 1]; //adjacency list
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int>vis(n + 1, 0);
    stack<int>st;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(i, vis, st, adj);
        }
    }
    while (st.empty() == false) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
```

- BFS Method (**_Kahn's Algorithm_**)
<pre>
- if node has indegree zero(not coming any edges), then it has complete changes to be at the first position at topo. sort.
- calculate indegree of each nodes.
- every time go to that node that has indegree zero, and then reduced by one every connected node for that parent node.
</pre>

```cpp
//code for kahn's algorithm
void topoSort(int node, vector<int>&indeg, vector<int>&topo, vector<int>adj[], vector<int>&vis) {
    vis[node] = 1;
    queue<int>q;
    q.push(node);
    while (q.empty() == false) {
        int x = q.front();
        q.pop();
        topo.push_back(x);
        for (auto it : adj[x]) {
            indeg[it]--;
            if (indeg[it] == 0) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}

void kahns_algo() {
    int n, m; //no. of vertices, edges
    cin >> n >> m;
    vector<int> adj[n + 1]; //adjacency list
    vector<int> indeg(n + 1, 0); //indegree
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    vector<int>vis(n + 1, 0);
    vector<int>topo;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0 and vis[i] == 0) {
            topoSort(i, indeg, topo, adj, vis);
        }
    }
    for (auto x : topo) {
        cout << x << " ";
    }
    cout << endl;
}
```

example:

- [510C Fox And Names](./2_graph_traversals/3_topological_sorting/510C_Fox%20And%20Names.cpp)

<pre>
Lexicographical order is defined in following way. When we compare s and t, first we find the leftmost position with differing characters: si ≠ ti. If there is no such position (i. e. s is a prefix of t or vice versa) the shortest string is less. Otherwise, we compare characters si and ti according to their order in alphabet.

if there exists an order of letters in Latin alphabet such that the names on the paper she is submitting are following in the lexicographical order. If so, you should find out any such order as a permutation of characters 'a'-'z'

n number of name given, we have find a dictionary order according to the number given. if we not find any such then print impossible.

ex. - (r, ra , raj) no order required then ans -> a - z
    - (raj, ra ,r)  above should be smaller than lower but not in here -> impossible(-1)

- first should be lower length
- compare two same length string, above should be come first than next in dictionary order.

- (two string at a time) if same then go to next char, if not then, if we make edges between upper char to below char it must be follow topological_sort, if one is end before done, still it's bigger than other -> -1
- also we have a cycle in this graph -> -1 
</pre>

---

### Graph Connectivity

#### Strongly Connected Components (Kosaraju's Algorithm) - SCC

- **_Kosaraju's Algorithm_**
<pre>
- divide graph into some components
- each components, we can visit every node in a component from any node of the component. -> is called SCC

quetions like in SCC :
-> how many components are there?
-> what are the nodes in there in the same componet.

</pre>

![kosarajus_algorithm](https://media.dev.to/dynamic/image/width=800%2Cheight=%2Cfit=scale-down%2Cgravity=auto%2Cformat=auto/https%3A%2F%2Fdev-to-uploads.s3.amazonaws.com%2Fuploads%2Farticles%2Fw11phar5lma9ck0e5i3k.png)

Theory:

<pre>
- SCC1 -> SCC2 -> SCC3 ...
- using dfs in scc1, we can visit every nodes from that components. than scc2,scc3...
- using dfs bottom most elements are the deepest node 
- if we reverse all edges, then SCC3 -> SCC@ -> SCC1
- then if we start dfs using the top element (swallowest node) in that previous stack, we found each components separately. (each dfs traversal elements, if already visited encounter)
- looks like topo. sort, but it actually not.
</pre>

```cpp
//code for scc_kosaraju's algorithm
stack<int>st;
vector<int>temp;
vector<vector<int>>scc;

void dfs1(int node, vector<int>adj[], vector<int>&vis) {//pre dfs
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (vis[it] == 0) {
            dfs1(it, adj, vis);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int>tadj[], vector<int>&vis) {//post dfs
    vis[node] = 1;
    temp.push_back(node);
    for (auto it : tadj[node]) {
        if (vis[it] == 0) {
            dfs2(it, tadj, vis);
        }
    }
}

void kosarajus_algo() {
    int n, m; //no. of vertices, edges
    cin >> n >> m;
    vector<int> adj[n + 1], tadj[n + 1]; //adjacency list, transfer adjacency list
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        tadj[v].push_back(u);
    }
    vector<int>vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs1(i, adj, vis);
        }
    }
    fill(vis.begin(), vis.end(), 0);
    while (st.empty() == false) {
        int node = st.top();
        st.pop();
        if (vis[node] == 0) {
            dfs2(node, tadj, vis);
            scc.push_back(temp);
            temp.clear();
        }
    }
    cout << scc.size() << endl;//total components
    for (auto it : scc) {
        for (auto x : it) {//each component has
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}
```

example:

- [cses1682_Flight Routes Check](./4_graph_connectivity/1_strongly_connected_components/cses1682_Flight%20Routes%20Check.cpp)
<pre>
There are n cities and m flight connections, your task is to check if you can travel from any city to any other city using the available flights.

if possible -> YES, if not -> NO and two cities that can't be travelled.

- possible if no. of scc == 1
- if no then print two different scc members
</pre>
- [cses1683_Planets and Kingdoms](./4_graph_connectivity/1_strongly_connected_components/cses1683_Planets%20and%20Kingdoms.cpp)
<pre>
A game has n planets, connected by m teleporters, two planets a and b belong to the same kingdom if there is a route both from (a->b and b->a)

print number of kingdoms and (each planet a kingdom)

</pre>
- [cses1686_Coin Collector.cpp](./4_graph_connectivity/1_strongly_connected_components/cses1686_Coin%20Collector.cpp)
<pre>
</pre>

### Undirected Graph

---


### MST

    - mostly use krushkal's algorithms

#### Kruskal's Algorithm (application of DSU)

      - used to find minimum spanning tree (MST)
      - graph is weighted
      - we have to connect (n-1) edges
      - begin with least weighted edges
      - if already connected, then not construct anything (remove edge)

```cpp
//dsu code first then other
void krushkalAlgo() {
    int n, m; //n = size of dsu, m = node
    cin >> n >> m;
    vector<pair<int, pair<int, int>>>edges;
    for (int i = 0; i < m; i++) {
        int u, v, w; //connected node and their weight
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());//sort by weight
    dsu d(n);
    int sum = 0;
    for (auto it : edges) {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (d.findPar(u) != d.findPar(v)) {
            sum += w;
            d.unionRank(u, v);
            cout << u << " " << v << " " << w << endl;
        }
    }
    cout << sum << endl;
}
```

example:

- [25D_Roads not only in Berland](./6_mst/1_krushkals/25D_Roads%20not%20only%20in%20Berland.cpp)

  <pre>
  First of all, it was decided to build new roads so that from each city of Berland and neighboring countries it became possible to reach all the others. 
  
  There are n cities in Berland and neighboring countries in total and exactly (n - 1) two-way roads.
  
  **build a new road it has to close some of the existing ones.
  
  Every day it is possible to close one existing road and immediately build a new one.
  
  **determine how many days would be needed to rebuild roads so that from each city it became possible to reach all the others.
  </pre>

#### Prim's Algorithm

    - get the sum of edges of mst
    - get the edges as well

Theory:

    - weighted undirected graph
    - we can go each node to all other nodes
    - maintain two things
            - visited array(initialy all 0)
            - priority queue (min at top)(each - weight,node,parent)
    - in p_queue min is out first
    - initial first pq have wt-0, node-x, parent-0

![prims](https://cp-algorithms.com/graph/MST_before.png)
to
![prims_mst](https://cp-algorithms.com/graph/MST_after.png)

```cpp
//code for prim's algorithm
int n, m; cin >> n >> m; //num of nodes and edges
vector<pair<int, int>> adj[n + 1];// adjacent list -> vector of pair
//vector<vector<pair<int, int>>> adj(n + 1);
for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
priority_queue<vector<int>>pq;
vector<int>vis(n + 1, 0);
pq.push({0, 1, 0}); //wt, node, par
int sum = 0;
vector<pair<int, int>>edges;
while (pq.empty() == false) {
    int wt = -pq.top()[0];
    int node = pq.top()[1];
    int par = pq.top()[2];
    pq.pop();//pop first
    if (vis[node] == 1) continue;//if already visited
    vis[node] = 1;
    sum += wt;
    if (par != 0) {
        edges.push_back({node, par});
    }
    for (auto it : adj[node]) {
        if (vis[it.first] == 0) {
            pq.push({ -it.second, it.first, node});// neg because of min heap
        }
    }
}
cout << sum << endl;
for (auto it : edges) {
    cout << it.first << " " << it.second << endl;
}

```

example:

[1624G_MinOr Tree](./6_mst/2_prims/1624G_MinOr%20Tree.cpp)

<pre>
# find mst such that their bitwise or as minimum as possible

we have to iterate (msb to lsb) bit and check that if this bit can be unset in the answer (try to remove all edges with this bit set) and check the no. of components -> 1 can be done (more than one can't be done)
</pre>

---

### Shortest Paths

- **_Dijkstra_**'s is more common than bellman ford or floyd warshall

**_single source shortest path_**

- #### Dijkstra's Algorithm _(non-negative weight edges)_
<pre>
- it's a single source shortest path algorithm
- non-negative edge weights
- works both directed and undirected graph
- find shortest path from given node to every other nodes

</pre>
![dijkstra](https://i.ytimg.com/vi/Lfb8qkXzHY0/maxresdefault.jpg)
Steps:

<pre>
- mark distance of given node = 0, all other node distance = infinity
- push node into priority queue (small value at top)
- pop small then visit it's neighbour node and update there distance
- then update next node (using small distance)
- on every iteration the marked vertex is the one that can never have a better distance later on.
</pre>

```cpp
//code for dijkstra's algorithm
//using set
void dijkstras_algo_using_set(int src, int n, vector<vector<pair<int, ll>>> &edges, vector<ll>&dist) {
  fill(dist.begin(), dist.end(), LLONG_MAX);
  vector<bool>marked(n, false);
  dist[src] = 0;
  set<pair<ll, int>>toExplore; //weight,node
  toExplore.insert({0LL, src});
  while (toExplore.size() > 0) {
    pair<ll, int>top = *toExplore.begin();
    toExplore.erase(top);
    int poppedNode = top.second;
    ll distSoFar = top.first;
    marked[poppedNode] = true;
    for (auto i : edges[poppedNode]) {
      int node = i.first;
      ll addedDist = i.second;
      if (marked[node]) {
        continue;
      }
      if (dist[node] > distSoFar + addedDist) {
        toExplore.erase({dist[node], node});
        dist[node] = distSoFar + addedDist;
        toExplore.insert({dist[node], node});
      }
    }
  }
}
```

```cpp
//using priority queue
//recomanded O((n+m)logn)
void dijkstras_algo_using_priority_queue(int src, int n, vector<vector<pair<int, ll>>> &edges, vector<ll>&dist, vector<int>&parent) {
  dist.assign(n, LLONG_MAX);
  // parent.assign(n,-1); //Retrieving the shortest path
  dist[src] = 0;
  priority_queue<pair<ll, int>, vector<pair<int, ll>>, greater<pair<ll, int>>>q;
  q.push({0LL, src});
  while (!q.empty()) {// O(N)
    pair<ll, int>top = q.top();
    q.pop();//O(logN)
    int poppedNode = top.second;
    ll distSoFar = top.first;
    if (distSoFar != dist[poppedNode]) {
      continue;
    }
    for (auto i : edges[poppedNode]) {//O(M)
      int node = i.first;
      ll addedDist = i.second;
      if (dist[node] > distSoFar + addedDist) {
        dist[node] = distSoFar + addedDist;
        //parent[node]=poppedNode;
        q.push({dist[node], node});//O(logN)
      }
    }
  }
}
// get shortest path
void getPath(int node, vecctor<int>&parent) {
  while (node != -1) {
    cout << node << " ";
    node = parent[node];
  }
}
```

- Dijkstra's Tree

![tree](https://www.gatevidyalay.com/wp-content/uploads/2018/03/Dijkstra-Algorithm-Shortest-Path-Tree.png)

- **Number of shortest paths to every node**

##

- #### Bellman Fort Algorithm _(work with negative weight edges)_
<pre>
- single source shortest path algorithm
- works in negative edge weight(directed) but **not in negative cycles**
- using to find negative cycles
- using the principal of mathematical induction
- algorithm goes upto n-1
</pre>

![bellmanford](https://i.sstatic.net/mMC7j.png)

Theory:

<pre>
- after k iterations, all node which require <=k edges in the minimum path would have their final answeer.
- each iteration go each node and relaxed it

</pre>

```cpp
//code for bellman-ford
void BellmanFord(int n, int src, vector<pair<int, ll>> *edges, vector<ll>& dist, set<int>& negCycle) {
  fill(all(dist), INF);
  dist[src] = 0;
  vector<pair<ll, pair<int, int>>> e;
  for (int i = 0; i < n; i++) {
    for (auto j : edges[i]) {
      e.pb({j.ss, {i, j.ff}});
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (auto j : e) {
      dist[j.ss.ss] = min(dist[j.ss.ss], dist[j.ss.ff] + j.ff);
    }
  }
  //checking negative cycle
  for (int i = 0; i < n; i++) {
    for (auto j : e) {
      if (dist[j.ss.ss] > dist[j.ss.ff] + j.ff) {
        dist[j.ss.ss] = dist[j.ss.ff] + j.ff;
        negCycle.insert(j.ss.ss);
      }
    }
  }
}
```

**_all pair shortest path_**

#### Floyd Warshall Algorithm

O(N<sup>3</sup>)

    - use to find all pair shortest path
    - brute force dp algorithm in graph
    - directed or undirected weighted graph
    - cost[i][j] = min cost to travel from i to j
    - use adjacency matrix (cost matrix)
    - if no direct path i to j, then cost is infinity
    - i==j -> 0
    - negative cycle can be checked

- two types of adjacency relation
  - adjacency list
  - adjacency matrix

![floyd_warshall](https://figures.semanticscholar.org/9cb9e82f482d434cf73ec2dd747662e0dc741caf/4-Figure2-1.png)

Theory:

    - first construct direct path
    - then construct via path
    - because of via (i,j and j,i) are same
    - if column and row are intersect, then those produce same result (column == row)
    - if better result than previous then update those path

```cpp
//code for floyd warshall
int n, m; cin >> n >> m; //num of nodes and edges
int cost[n + 1][n + 1];
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (i == j) cost[i][j] = 0;
        else {
            cost[i][j] = INT_MAX;
        }
    }
}
for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    cost[u][v] = min(cost[u][v], w);
}
for (int k = 1; k <= n; k++) { //O(n*n*n)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cost[i][k] == INT_MAX || cost[k][j] == INT_MAX) continue;
            cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        }
    }
}
for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
        cout << cost[i][j] << " ";
    }
    cout << endl;
}
```

---

### LCA (Lowest Common Ancestors)

### Eulerian Path

### Satisfiability
