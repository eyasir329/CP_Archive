# Arrays, Subarrays, Subsets and More

## 📚 Table of Contents

- [Array Basics](#array-basics)
- [N-Dimensional Arrays](#n-dimensional-arrays-in-c)
- [STL Vectors](#vector)
- [1D to 2D and Vice Versa](#2d-vector-or-array)
- [Pair-Wise Computations](#something-on-pair-wise)
- [Subarray Concepts](#subarray)
- [Subsequence Concepts](#subsequence)
- [Subset Concepts](#subset)

---

## Array Basics

- Each element takes 4 bytes (on most systems).
- If `arr[0]` is in location 1000 in memory then `arr[1]` is at 1004, `arr[k]` is at (1000 + k \* 4).

Memory required:

```cpp
int a[n][n]; // Memory = n^2 * 4 bytes
```

| n     | Memory  |
| ----- | ------- |
| 512   | \~1MB   |
| 1000  | \~4MB   |
| 10000 | \~400MB |

### General Guidelines

- Use dynamic allocation for large arrays to avoid stack overflow.
- Ensure you have enough physical memory (RAM).
- Use sparse matrix representation if many zeros.

```cpp
// Stack allocation
int n = 500;
int a[500][500]; // OK

int m = 1000;
int b[1000][1000]; // May overflow stack
```

```cpp
// Heap allocation
int main() {
    int n = 10000;
    int** a = new int*[n];
    for (int i = 0; i < n; i++) a[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;

    for (int i = 0; i < n; i++) delete[] a[i];
    delete[] a;
    return 0;
}
```

---

## N-Dimensional Arrays

### 1. Raw Arrays (Static)

```cpp
int arr2d[3][4];
int arr3d[2][3][4];
```

**Pros:** Simple, fast.
**Cons:** Fixed size.

### 2. Using std::vector (Dynamic)

```cpp
vector<vector<int>> vec2d(3, vector<int>(4));
vector<vector<vector<int>>> vec3d(2, vector<vector<int>>(3, vector<int>(4)));
```

**Pros:** Dynamic.
**Cons:** Non-contiguous.

### 3. Single Vector with Index Calculation

```cpp
class NDArray {
    vector<int> data;
    vector<size_t> dimensions;
public:
    NDArray(vector<size_t> dims) : dimensions(dims) {
        size_t total = 1;
        for (auto d : dimensions) total *= d;
        data.resize(total);
    }
    int& at(vector<size_t> indices) {
        size_t index = 0, stride = 1;
        for (int i = dimensions.size()-1; i >= 0; --i) {
            index += indices[i] * stride;
            stride *= dimensions[i];
        }
        return data[index];
    }
};

NDArray arr({2, 3, 4});
arr.at({1, 2, 3}) = 42;
```

**Pros:** Fast, contiguous memory.
**Cons:** Complex indexing.

### 4. Boost.MultiArray

```cpp
#include <boost/multi_array.hpp>
boost::multi_array<int, 3> arr(boost::extents[2][3][4]);
arr[1][2][3] = 42;
```

**Pros:** Clean, powerful.
**Cons:** Needs Boost.

example:

- 2033B_Sakurako and Water
  https://www.spoj.com/problems/MAX_NUM/en/



---

## Vector

- C-style array passed by reference.
- std::vector passed by value unless using `&`.

```cpp
v.clear(); // O(N)
v.assign(10,1);
sort(v.begin()+1,v.end()-1);
v.insert(v.begin()+i,x);
v.erase(v.begin()+i);
reverse(v.begin(),v.end());
swap(u,v);

auto it = find(v.begin(),v.end(),x);
int index = it - v.begin();

count(v.begin(),v.end(),x);
accumulate(v.begin(),v.end(),0LL);
*min_element(v.begin(),v.end());
*max_element(v.begin(),v.end());
partial_sum(v.begin(),v.end(),pre.begin());
```

```cpp
int n = 10000;
vector<vector<int>> a(n, vector<int>(n, 0));
a[0][0] = 1; a[n-1][n-1] = 2;
```

![vector_cheetsheet](https://hackingcpp.com/cpp/std/vector_crop.png)

---

## 2D Vector or Array

### 1D to 2D

```cpp
vector<int> oneD = {1, 2, 3, 4, 5, 6};
int rows = 2, cols = 3;
vector<vector<int>> twoD(rows, vector<int>(cols));
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        twoD[i][j] = oneD[i * cols + j];
```

### 2D to 1D

```cpp
vector<vector<int>> twoD = {{1,2,3},{4,5,6}};
int rows = twoD.size(), cols = twoD[0].size();
vector<int> oneD(rows * cols);
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        oneD[i * cols + j] = twoD[i][j];
```

- Problem: [Codeforces 1517B](https://codeforces.com/contest/1517/problem/B)

---

## Something on Pair-Wise

- Total pairs: $n(n-1)/2$
- Fix `i` or `j` and compute

### Example: $\sum a_i \cdot a_j$

#### All pairs:

```cpp
for 1 to n: sum += ai * total_sum
```

#### i < j:

```cpp
for 1 to n: sum += aj * preSum[j-1];
```

### Key Problems

- [1771A](https://codeforces.com/problemset/problem/1771/A)
- [2078C](https://codeforces.com/contest/2078/problem/C)
- [1592B](https://codeforces.com/problemset/problem/1592/B)
- [1399C](https://codeforces.com/problemset/problem/1399/C)
- [1420B](https://codeforces.com/problemset/problem/1420/B)

---

## Subarray

- Total subarrays: $n(n+1)/2$

```cpp
for (int i = 1; i <= n; i++) {
  vector<int>v;
  for (int j = i; j <= n; j++) {
    v.push_back(a[j]);
    print(v);
  }
}
```

### Divisible by k

```cpp
(p[r] - p[l-1]) % k == 0 ⇨ p[r]%k == p[l-1]%k
```

### XOR = 0

```cpp
(p[r] ^ p[l-1]) == 0 ⇨ p[r] == p[l-1]
```


---
- <u>Given an array `A` of `n` integers (can be positive, negative, or zero), find the **maximum possible sum** of a **non-empty subarray**.</u>


## ✅ Brute Force Approach (O(n³) or O(n²))

### 🔸 Method 1: Triple Loop (O(n³))

* Try **all possible subarrays**.
* For each subarray, compute the sum.

```cpp
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += nums[k];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
```

### 🔸 Method 2: Double Loop with Running Sum (O(n²))

```cpp
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
```

---

## 🚀 Optimal Solution: Kadane's Algorithm (O(n))

* Iterate once.
* Keep track of current subarray sum and max so far.

```cpp
int maxSubArray(vector<int>& nums) {
    int maxSoFar = nums[0], currSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSoFar = max(maxSoFar, currSum);
    }
    return maxSoFar;
}
```

---

### 🧠 Intuition Behind Kadane’s

At each step:

* Either extend the previous subarray (`currSum + nums[i]`),
* Or start a new one from current element `nums[i]`,
* Keep the best overall sum.

---

### 🕒 Time and Space Complexity

| Approach     | Time     | Space |
| ------------ | -------- | ----- |
| Brute O(n³)  | O(n³)    | O(1)  |
| Brute O(n²)  | O(n²)    | O(1)  |
| **Kadane’s** | **O(n)** | O(1)  |

---

- [1438B](https://codeforces.com/problemset/problem/1438/B)

---

## Subsequence

```cpp
void printPowerSet(string &s) {
    int n = pow(2, s.size());
    for (int counter = 0; counter < n; counter++) {
        for (int j = 0; j < s.size(); j++)
            if (counter & (1 << j)) cout << s[j];
        cout << endl;
    }
}
```

- [1560D](https://codeforces.com/problemset/problem/1560/D)

---

## Subset

> Total subsets of a set of size `n`:
>
> $$
> 2^n \text{ (including empty set) \quad or \quad } 2^n - 1 \text{ (excluding empty set)}
> $$

### 🔢 Bitmasking

Efficient method to generate all subsets.

```cpp
vector<int> nums = {1, 2, 3};
int n = nums.size();

for (int mask = 0; mask < (1 << n); mask++) {
  vector<int> subset;
  for (int i = 0; i < n; i++)
    if (mask & (1 << i)) subset.push_back(nums[i]);

  // print subset
  for (int x : subset) cout << x << " ";
  cout << endl;
}
```

**Output:**

```
(empty)
1
2
1 2
3
1 3
2 3
1 2 3
```

---

### 🔁 Recursion (Backtracking)

Build subsets using recursive DFS.

```cpp
vector<vector<int>> result;

void backtrack(vector<int>& nums, vector<int>& subset, int index) {
  result.push_back(subset);
  for (int i = index; i < nums.size(); i++) {
    subset.push_back(nums[i]);
    backtrack(nums, subset, i + 1);
    subset.pop_back();
  }
}

int main() {
  vector<int> nums = {1, 2, 3}, temp;
  backtrack(nums, temp, 0);

  for (auto& subset : result) {
    for (int x : subset) cout << x << " ";
    cout << endl;
  }
}
```

---

### ⚙️ STL Algorithms

Use built-in `std::includes()` to **check subset relationship**.

```cpp
vector<int> a = {1, 2, 3, 4};
vector<int> b = {2, 3};

// Must be sorted
sort(a.begin(), a.end());
sort(b.begin(), b.end());

if (includes(a.begin(), a.end(), b.begin(), b.end()))
  cout << "b is a subset of a\n";
else
  cout << "b is NOT a subset of a\n";
```

🧠 `std::includes(A, B)` returns true if **every element of B exists in A**. Both ranges must be sorted.

---

### Subset Sum

```cpp
vector<vector<bool>> dp(n+1, vector<bool>(target+1));
dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
```

- [2123D](https://codeforces.com/contest/2123/problem/D)
