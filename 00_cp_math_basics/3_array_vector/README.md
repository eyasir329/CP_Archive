### Array

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

### STL Array

- c_type array(not stl array) pass by referrence by default.
- pass by value need more time than pass by reference

### Vector

```cpp
//some functions in vector
v.clear()->O(N)
v.assign(10,1) //upto 10th element assign by 1
v.sort(v.begin()+1,v.end()-1)//{8, 1, 2, 3, 1}//right exclusive
v.insert(v.begin()+i,x);//immediade pos go to next
v.erase(v.begin()+i);//next go this pos
// range always right exclusive
reverse(range) or sort(v.rbegin(),v.rend());

swap(u,v) or u.swap(v)//swap two vectors element
auto it = find(v.begin(),v.end(),x);//first occurance
if(it==v.end())//not occur x
index = it - v.begin();
auto it = find(v.rbegin(),v.rend(),x);//last occurance
if(it==v.rend())//not occur x

count(v.begin(),v.end(),x);
accumulate(v.begin(),v.end(),0LL);//0LL initial sum
*min_element(v.begin(),v.end());
*max_element(v.begin(),v.end());

partial_sum(v.begin(),v.end(),pre.begin());

```

<code>right exclusive -> (v.begin(),v.end())</code>
<br>

- std::vector< ValueType >

## ![vector_cheetsheet](https://hackingcpp.com/cpp/std/vector_crop.png)

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

- 1D to 2D
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> oneD = {1, 2, 3, 4, 5, 6};
    int rows = 2, cols = 3; // 2 rows × 3 columns = 6 elements

    vector<vector<int>> twoD(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            twoD[i][j] = oneD[i * cols + j];

    // Print 2D vector
    for (const auto &row : twoD) {
        for (int val : row) cout << val << " ";
        cout << '\n';
    }

    return 0;
}
```
- 2D to 1D
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> twoD = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int rows = twoD.size();
    int cols = twoD[0].size();
    vector<int> oneD(rows * cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            oneD[i * cols + j] = twoD[i][j];

    for (int val : oneD)
        cout << val << " ";
    cout << '\n';

    return 0;
}

```

### 2D Vector or Array

- https://codeforces.com/contest/1517/problem/B

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
- https://codeforces.com/problemset/problem/1592/B
- https://codeforces.com/problemset/problem/1399/C
- https://codeforces.com/problemset/problem/1420/B

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
https://www.geeksforgeeks.org/dsa/print-subsequences-string/
```cpp
void printPowerSet(string &s) {
    int n = pow(2, s.size());
    
    for (int counter = 0; counter < n; counter++) {
        for (int j = 0; j < s.size(); j++) {
          
            // Check if jth bit in the counter is set
            if (counter & (1 << j))
                cout << s[j];
        }
        cout << endl;
    }
}
```

- https://codeforces.com/problemset/problem/1560/D
(optimise subsequence)
---

### Subset

- total number of subset -> 2<sup>n</sup>-1

---

- https://codeforces.com/contest/2123/problem/D
