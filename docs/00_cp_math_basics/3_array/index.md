---
title: "3 array"
nav_order: 1
---


<pre>
- each element takes 4 bytes (on most systems).

- int a[n][n], memory required -> Memory required (bytes) = n<sup>2</sup>×4
  n = 512 (since 512<sup>2</sup>×4=1MB), n = 1000 (4MB), n = 10000 (400MB)

General Guidelines
  - Use dynamic allocation for large arrays to avoid stack overflow.
  - Ensure you have enough physical memory (RAM) to support the desired size.
  - Avoid unnecessarily large arrays; consider using sparse matrix representations if the array contains many zeros.
</pre>

```cpp
// stack allocation
int n = 500; // Works fine on most systems
int a[500][500]; // Requires 1 MB memory (approx.)

int m = 1000; // May cause stack overflow
int b[1000][1000]; // Requires 4 MB memory (approx.)
```

```cpp
//heap allocation (dynamic memory)
int main() {
    int n = 10000; // Larger sizes possible with heap
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    // Use the array (example: initialize with 0)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
```

```cpp
//std::vector
int main() {
    int n = 10000; // Works for large n if enough memory is available
    vector<vector<int>> a(n, vector<int>(n, 0)); // Initialize with 0

    // Access elements
    a[0][0] = 1;
    a[n-1][n-1] = 2;

    cout << a[0][0] << " " << a[n-1][n-1] << endl;
    return 0;
}
```

---

### Something on Pair-Wise

<pre>
- total number of pair (n*(n-1))/2

- we can fixed i or j(one), then calculate -> in pair/triple type of problems

- if all elements are distinct(pair-wise) -> they do not have common subarray whose xor are same.  
</pre>

example:

- find the total sum of a<sub>i</sub>\*a<sub>j</sub>, where 1<=i, j<=n, n=1e5

  <pre>
  # we have to do it in one loop (fixing i)
  
  for 1 to n: sum += ai * total_sum
  </pre>

- find the total sum of a<sub>i</sub>\*a<sub>j</sub>, where 1<=i<j<=n, n=1e5

  <pre>
  # we have to do it in one loop (fixing j)
  
  for 1 to n: sum += aj * preSum[j-1]
  </pre>

- https://codeforces.com/problemset/problem/1771/A

  <pre>
  If max(a) == min(a) (all numbers are the same), the difference is 0
  → Every pair satisfies |ai - aj| = 0
  → There are n * (n - 1) pairs (i ≠ j).
  </pre>

- https://codeforces.com/contest/2078/problem/C

---

### Subarray

<pre>
- total number of subarray -> n*(n+1)/2
</pre>

```cpp
const int N = 1e6 + 9;
int a[N];

void print(vector<int>&v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int32_t main() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    vector<int>v;
    for (int j = i; j <= n; j++) {
      v.push_back(a[j]);
      print(v);
    }
    cout << endl;
  }
  return 0;
}
```

_example:_

- num of subarray whose sum is divisible by k

  <pre>
  in [l,r] subarray : (p[r]-p[l-1])%k=0
                     => p[r]%k-p[l-1]%k=0
                     => p[r]%k=p[l-1]%k
  </pre>

- num of subarray whose xor = 0

  <pre>
  in [l,r] subarray : (p[r]^p[l-1]) = 0
                  => p[r] = p[l-1] (using xor property)                  
  </pre>

- https://codeforces.com/problemset/problem/1438/B

---

### Subsequence

---

### Subset

- total number of subset -> 2<sup>n</sup>-1

---
