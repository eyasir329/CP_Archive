### Prefix Sum

example:

- https://codeforces.com/problemset/problem/1504/B

- [CSUMQ - Cumulative Sum Query](./1.prefix_sum/spoj_CSUMQ%20-%20Cumulative%20Sum%20Query.cpp)

<pre>
You are given a list of N numbers and Q queries. Each query is specified by two numbers i and j; the answer to each query is the sum of every number between the range [i, j] (inclusive).

Note : 0 Based Indexing
</pre>

- https://codeforces.com/contest/2075/problem/C

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

- * https://codeforces.com/problemset/problem/1487/B

    1. Adhoc Two Pointer
    2. Good Segment Category*

https://usaco.guide/silver/two-pointers?lang=cpp

- Iterating two monotonic pointers across an array to search for a pair of indices satisfying some condition in linear time.

- _Each variable moves in a single direction_, and they only traverse the array a single time.
  Therefore, time complexity will be O(N+M)

##### Optimization_Technique

    Binary Search on Array O(NlogN)-> using two pointer O(N)
    Binary Search <-> Two Pointer

https://www.geeksforgeeks.org/two-pointers-technique/

#### Variable Size Sliding Window (Also known as two pointer)

The general steps to solve these questions by following below steps:

    In this type of sliding window problem, we increase our right pointer one by one till our condition is true.
    At any step if our condition does not match, we shrink the size of our window by increasing left pointer.
    Again, when our condition satisfies, we start increasing the right pointer and follow step 1.
    We follow these steps until we reach to the end of the array.

#### Good Segment Technique Tricks

    *If segment within [L,R] is good, segment enclosed within will be good.
        -> Increasing, Decreasing Technique
    *Do not use binary search in that problem
    *Good segment-> multiple of (j-i+1) for every i in (longest_subarray_length_sum<=k)

#### Some Technique

- Given two sorted array, we have to merge it within O(N+M) and makes array sorted.

```cpp
vector<int> merge(vector<int>&l, vector<int>&r) {
  int n = l.size(), m = r.size();
  vector<int>ans;
  int i = 0, j = 0;
  while (i < n and j < m) {
    if (l[i] < r[j]) {
      ans.push_back(l[i++]);
    } else {
      ans.push_back(r[j++]);
    }
  }
  while (i < n) ans.push_back(l[i++]);
  while (j < m) ans.push_back(r[j++]);
  return ans;
}
```

- [Given two sorted array, we have to find a[i] + b[i] = x](./2_two_pointer/ai_bi_x_where_a_b_sorted.cpp)

```cpp
//using two pointer O(N+M)... using bs it's go to O(NlogN)
for (int i = 0, j = m - 1; i < n; i++) // O(N){
  int rem = x - a[i];
  while (j >= 0 and b[j] > rem){ // O(M) in total
    j--;
  }
  if (j >= 0 and b[j] == rem){
    cout << i << " " << j << endl;
    return;
  }
}
```

https://usaco.guide/CPH.pdf#page=87

- [Subarray sum ->(Given an array of N (1<=N<=1e5 ) positive elements, find a contiguous subarray that sums to X.)](./2_two_pointer/gfg_find-subarray-with-given-sum.cpp)

<pre>A[] ={1 3 2 5 1 1 2 3} , x = 8 
Naive Method : Find all subarray and compare to x, but that give O(N\*N). 
This problem can be solved in O(n) time by using the two pointers method</pre>

![subarray sum](https://i.ibb.co.com/VTCc0hw/Screenshot-from-2024-10-01-12-49-20.png)

<pre>The running time of the algorithm depends on the number of steps the right pointer moves. we know that the pointer moves a total of O(n) steps during the algorithm, because it only moves to the right.
  
Pros and Cons:
      f(A[i]<0) then it will give WRONG ANSWER
      The above solution does not work for arrays with negative numbers.
      Then, We use [Hashing + Prefix Sum] O(N) time and O(N) Space
</pre>

https://darrenyao.com/usacobook/cpp.pdf#page=70

- **2SUM problem** (Given an array of N elements (1<=N<=1e5 ), find two elements that sum to X)

<pre>We can solve this problem using two pointers; sort the array, then set one pointer at the beginning and one pointer at the end of the array. </pre>

```cpp
int left = 0; int right = n - 1;
while (left < right) {
    if (arr[left] + arr[right] == x) {
        break;
    } else if (arr[left] + arr[right] < x) {
        left++;
    } else {
        right--;
    }
}
// if left >= right after the loop ends, no answer exists.
```

- **Maximum subarray sum** (Given an array of N integers (1<=N<=1e5 ), which can be positive or negative, find the maximum sum of a contiguous subarray)
<pre>It is not solved by two pointers, but it similar to that kind of problem.We can solve this problem using Kadane’s algorithm.</pre>

```cpp
//kadane's algorithm
int best = 0, current = 0;
for (int i = 0; i < n; i++) {
  current = max(0, current + arr[i]);
  best = max(best, current);
}
```

- Largest Subarray with sum <=s

```cpp
//bruteforce solution O(N*N)
int ans = 0;
for (int l = 1; l <= n; l++) {
  int sum = 0;
  for (int r = l; r <= n; r++) {
    sum += a[r];
    if (sum <= s) {
      ans = max(ans, r - l + 1);
    }else{
      break;
    }
  }
}
cout << ans << endl;

//two pointer solution O(2N)-> O(N) -> everytime l is increament by 1 and r is increament by 1
//all value is positive
// if [l,r] is good then [l,r-1] or [l+1,r]  is also good
int ans = 0, r = 1;
ll sum = 0;
for (int l = 1; l <= n; l++) {
  while (r <= n and a[r] + sum <= s) {
    sum += a[r];
    r++;
  }
  ans = max(ans, r - l); //[l,r-1] is the largest subarray with sum<=s {r-l+1-1}
  sum -= a[l];
}
cout << ans << endl;
```

- Number of Subarray with sum <=s

```cpp
int r = 1;
ll sum = 0, ans = 0;
for (int l = 1; l <= n; l++) {
  while (r <= n and a[r] + sum <= s) {
    sum += a[r];
    r++;
  }
  ans += r - l; //[l,r-1] is the largest subarray with sum<=s {r-l+1-1}
  sum -= a[l];
}
cout << ans << endl;
```

- Number of Subarray with sum >=s

```cpp
int r = 1;
ll sum = 0, ans = 0;
for (int l = 1; l <= n; l++) {
  while (r <= n and a[r] + sum < s) {
    sum += a[r];
    r++;
  }
  ans += n - r + 1; //r is the smallest index in which sum of [l,r-1]<s
  sum -= a[l];
}
cout << ans << endl;
```

- Number of good segment where, in each segment abs(max-min) at most k (<=k)

```cpp
//always increase difference
//if [l,r] good then [l,r+1] also good
using ll = long long;

const int N = 1e5 + 9;
ll a[N];

struct DS {
  multiset<ll>ms;
  DS() {}
  void insert(ll x) {
    ms.insert(x);
  }
  void erase(ll x) {
    ms.erase(ms.find(x));
  }
  ll get_max() {
    return *(--ms.end());
  }
  ll get_min() {
    return *ms.begin();
  }
  ll get() {
    return get_max() - get_min();
  }
} ds;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  ll k; cin >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int r = 1;
  ll  ans = 0;
  for (int l = 1; l <= n; l++) {
    while (r <= n) {
      ds.insert(a[r]);
      if (ds.get() > k) {
        ds.erase(a[r]);
        break;
      }
      r++;
    }
    ans += r - l; //r - 1 is the maximum index i, such that max(a[l...i])-min(a[l...i])<=k
    ds.erase(a[l]);
  }
  cout << ans << endl;
  return 0;
}
```

example:

2033D D. Kousuke's Assignment

---

### Sliding Window

https://usaco.guide/gold/sliding-window?lang=cpp

<pre>
- A sliding window is a constant-size subarray that moves from left to right through the array.
- For each position of the window, we want to compute some information.
</pre>

- Sum of every k length subarray

```cpp
int sum = 0;
for(int i=1;i<=n;i++){
  sum+=a[i];
  if(i>=k){
    cout<<sum<<" ";
    sum-=a[i-k+1];
  }
}
```

- Maximum sum subarray of length k

```cpp
struct DS {
  multiset<ll>ms;
  DS() {}
  void insert(ll x) {
    ms.insert(x);
  }
  void erase(ll x) {
    ms.erase(ms.find(x));
  }
  ll get_max() {
    return *(--ms.end());
  }
} ds;
for(int i=1;i<=n;i++){
  ds.insert(a[i]);
  if(i>=k){
    cout<<ds.get_max()<<" ";
    ds.erase(a[i-k+1]);
  }
}
```

- Maximum of all subarray of length k

- Number of unique elements in all subarrays of length k

>example

---

### Difference Array / Static Range Update

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
