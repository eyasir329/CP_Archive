## Optimization Technique

### Prefix Sum

example:

[CSUMQ - Cumulative Sum Query](./1.prefix_sum/spoj_CSUMQ%20-%20Cumulative%20Sum%20Query.cpp)

<pre>
You are given a list of N numbers and Q queries. Each query is specified by two numbers i and j; the answer to each query is the sum of every number between the range [i, j] (inclusive).

Note : 0 Based Indexing
</pre>

### 2D Prefix Sum / Prefix Sum of Matrix

https://www.geeksforgeeks.org/prefix-sum-2d-array/

<pre>
- prefix[i][j] = ​prefix[i−1][j]+prefix[i][j−1] − prefix[i−1][j−1]+arr[i][j]​

- Corner Cases (First row and first column)
  If i = 0 and j = 0
    psa[i][j] = a[i][j]
  If i = 0 and j > 0
    psa[i][j] = psa[i][j-1] + a[i][j]
  If i > 0 and j = 0
    psa[i][j] = psa[i-1][j] + a[i][j]
</pre>

![2d prefix sum](https://i.sstatic.net/M8gOT.jpg)

- Given n\*m matrix (n,m<=1000), and q queries, we have to find sum of submatrix in each query

```cpp
using ll = long long;

const int N = 1e3 + 9;
int a[N][N];
ll pref[N][N];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }
    int q; cin >> q;
    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ll ans = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
        cout << ans << endl;
    }
    return 0;
}
```

### 3D Prefix Sum

---

### Two Pointer

<pre>

</pre>

example:

2033D D. Kousuke's Assignment

---

### Sliding Window

---

### Difference Array

https://codeforces.com/blog/entry/78762

<pre>
- perform multiple range update queries where we only need to find the answer after performing all the queries

- in difference array, <code>d[i] = a[i] - a[i-1]</code>
- original array is the prefix sum of difference array
</pre>

```cpp
//finding the difference array from the original array
a[0] = 0;
for(int i=1;i<=n;i++){
  d[i] = a[i] - a[i-1];
}
//finding the original array from the difference array
for(int i=1;i<=n;i++){
  a[i] = a[i-1] + d[i];
}
//prefix sum of difference array
for(int i=1;i<=n;i++){
  p[i] = p[i-1] + d[i];
}
//it's the original array
for(int i=1;i<=n;i++){
  cout<<p[i]<<" ";
}
```

- Given an array and q query, each query given l,r,x; (l->r add x), after all query find the final array

```cpp
//naive method O(nq) -> difference array O(n+q)
const int N = 1e6 + 9;
long long a[N], d[N];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {//create difference array
        d[i] = a[i] - a[i - 1];
    }
    while (q--) {//query update
        int l, r, x; cin >> l >> r >> x;
        d[l] += x;
        d[r + 1] -= x;
    }
    for (int i = 1; i <= n; i++) {//finding the main array
        a[i] = a[i - 1] + d[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
```

- Given n number of list, initially all is empty, we have q query (l,r,x)(list from l to r append x), after all query, print the number of unique element in each list (n,q<=1e6)

```cpp
//within O(nlogn)
const int N = 1e6 + 9;
vector<int> add[N], rem[N];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        add[l].push_back(x);
        rem[r + 1].push_back(x);
    }
    map<int, int>mp;
    for (int i = 1; i <= n; i++) {
        for (auto x : add[i]) {
            mp[x]++;
        }
        for (auto x : rem[i]) {
            mp[x]--;
            if (mp[x] == 0) {
                mp.erase(x);
            }
        }
        cout << mp.size() << endl;
    }
    return 0;
}
```

example:

- [295A_Greg and Array](./4_difference_array/295A_Greg%20and%20Array.cpp)

  <pre>
  n array size, m operation (each l->r, +x), then k query (x,y)<=m, that means that one should apply operations with numbers xi, xi + 1, ..., yi to the array.
  
  after all operations print the array
  </pre>

https://codeforces.com/contest/2014/problem/D

### 2D Difference Array / 2D Static Range Update

- Given n\*m matrix, q query, each given submatrix (top_left, bottom_right) add +x, after performing all query, print final array

```cpp
using ll = long long;

const int N = 1e3 + 9;
ll a[N][N], d[N][N];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int q; cin >> q;
    while (q--) {
        int x1, y1, x2, y2, x; cin >> x1 >> y1 >> x2 >> y2 >> x;
        d[x1][y1] += x;
        d[x2 + 1][y1] -= x;
        d[x1][y2 + 1] -= x;
        d[x2 + 1][y2 + 1] += x;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];//prefix sum of difference array
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] += d[i][j];//finding main array
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

---

### Circular Array

https://codeforces.com/contest/2036/problem/D

### 2D Circular Array

---
