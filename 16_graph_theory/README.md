## Graph Theory

### Basic Graphs

### Graph Traversals

### LCA

### Graph Connectivity

#

### DSU - Disjoint Set Union

[cp algorithm](https://cp-algorithms.com/data_structures/disjoint_set_union.html)

- When is DSU required?

      we are solving some node and edges problems using dsu.

      ex. node a and b in same components?

      # bruteforces (O(N))- single query
      travers(bfs) in component 1 which have node a, if we find b in that component also - yes.

      # multiple query -O(NQ)-using bruteforces-give TLE
      that time dsu come to play.

      - consider we are not constructing graph over here.
      - there is no disconnect query in dsu.

![connecting components](https://cp-algorithms.com/data_structures/DSU_example.png)

- How to find parent? (Path Compression Technique)

        every time connect node to the ultimate parrent (not in immidiate parent) - is called path compression.

  - find parent (DP kind of approach O(4x)->O(1))

            int find_parent(int node) {
              if (node == parent[node])
                return node;
              return parent[node] = find_parent(parent[node]);
            }

To optimize(<O(N)) union set(that will store each parrent) operation, we have two method,

    # connecting smaller to bigger (reduce dept of the tree)
    # don't relay on height because height is changing everytime.

https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/

Both of them perform similarly

- Union by rank (not always increase)

        The rank of a node generally refers to the distance (the number of nodes
        including the leaf node) between the furthest leaf node and the current node.
        Basically rank includes all the nodes beneath the current node.

- Union by size (always increasing, so we have to maintain size array)

        This is as same as the Union by rank method except this method uses the size to
        compare the components while connecting. That is why we need a ‘size’ array of
        size N(no. of nodes) instead of a rank array. The size array will be storing
        the size for each particular node i.e. size[i] will be the size of the
        component starting from node i.

        Typically, the size of a node refers to the number of nodes that are connected to it.

- Code Template of DSU

  ```cpp
  // code for DSU
  class dsu {
    vector<int> parent, size, rank;
  public:
    dsu(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        //path compression
        return parent[node] = findPar(parent[node]);
    }

    void unionSize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv) {
            return;
        }
        //attach smaller to bigger
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    void unionRank(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv) {
            return;
        }
        if (rank[pu] == rank[pv]) {
            parent[pu] = pv;
            rank[pu]++;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
        }
    }
  };
  ```

- Kruskal's Algorithm (application of DSU)

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

#### Practice questions

- [25D_Roads not only in Berland](./5_dsu/25D_Roads%20not%20only%20in%20Berland.cpp)

  <pre>
  First of all, it was decided to build new roads so that from each city of Berland and neighboring countries it became possible to reach all the others. 
  
  There are n cities in Berland and neighboring countries in total and exactly (n - 1) two-way roads.
  
  **build a new road it has to close some of the existing ones.
  
  Every day it is possible to close one existing road and immediately build a new one.
  
  **determine how many days would be needed to rebuild roads so that from each city it became possible to reach all the others.
  </pre>

- [spoj_CLFLARR - COLORFUL ARRAY](./5_dsu/spoj_CLFLARR%20-%20COLORFUL%20ARRAY.cpp)

  <pre>
  given n unpainted elements(initialy have 0). 
  q query, each (l r c) index l to r color it with c (each new color overrides it's previous color)
  output the color of all elements after all query processed.
  </pre>

#

### MST

### Shortest Paths

### Cycles

### Eulerian Path

### Satisfiability
