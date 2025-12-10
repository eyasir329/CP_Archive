


Why dp?

- to optimized brute force
- overlapping subproblems
  -> calculate no. of days b/w date1 & date2
- maximize/minimize some value -> (dp/greedy)
- finding number of ways
  -> find out number of way to go node A to node B and taking modulo 1e9+7
- covering all cases (DP vs Greedy)
- check for possibility

When to need DP?
Let's understand from a problem

- <b>find nth fibonacci number</b>
- f(n) = f(n-1)+f(n-2)
- f(1) = f(2) = 1

<b>Memoization</b>

- Why calculate f(x) again and again when we can calculate it once and use it every time when it is required?
  -> Check if f(x) has been calculated - if no, then calculate it and store it somewhere - if yes, then return the value without calculating again

![fibo](https://miro.medium.com/v2/resize:fit:617/1*EmGt1nAA3PNd0dcgE24wAw.png)

- without DP -> O(2^N)

```cpp
//  for n=30 -> functionEntered=1664079
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10; // Change as needed
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}

```

- with DP -> O(N) -> top down approach
  -> memoization

```cpp
//  for n=30 -> functionEntered=57
vector<int> dp(100, -1);

int fibonacci(int n) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10; // Change as needed
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}

```

![pb2](https://i.ibb.co.com/chQRvTcB/Screenshot-from-2025-03-05-14-41-40.png)

only go down and right

```cpp
#include <bits/stdc++.h>
using namespace std;

// Naive recursive approach
int minPathSumNaive(vector<vector<int>>& grid, int i, int j) {
    if (i == grid.size() - 1 && j == grid[0].size() - 1) {
        return grid[i][j];
    }
    int down = INT_MAX, right = INT_MAX;
    if (i < grid.size() - 1) {
        down = minPathSumNaive(grid, i + 1, j);
    }
    if (j < grid[0].size() - 1) {
        right = minPathSumNaive(grid, i, j + 1);
    }
    return grid[i][j] + min(down, right);
}

// Dynamic Programming approach
int minPathSumDP(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[n - 1][m - 1] = grid[n - 1][m - 1];

    // Fill last row from right to left
    for (int j = m - 2; j >= 0; --j) {
        dp[n - 1][j] = grid[n - 1][j] + dp[n - 1][j + 1];
    }

    // Fill last column from bottom to top
    for (int i = n - 2; i >= 0; --i) {
        dp[i][m - 1] = grid[i][m - 1] + dp[i + 1][m - 1];
    }

    // Fill remaining cells
    for (int i = n - 2; i >= 0; --i) {
        for (int j = m - 2; j >= 0; --j) {
            dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    return dp[0][0];
}

int main() {
    vector<vector<int>> grid = {
        {1, 5, 8},
        {6, 2, 7},
        {9, 3, 4}
    };

    cout << "Naive approach result: " << minPathSumNaive(grid, 0, 0) << endl;
    cout << "DP approach result: " << minPathSumDP(grid) << endl;

    return 0;
}
```

Important Terminology

- State: A subproblem defined by parameters (e.g., dp[i][j]).
- Transition: A rule that connects states (e.g., dp[i][j] = ...).
- Core Principle: States and transitions work together to solve complex problems efficiently by breaking them into overlapping subproblems and reusing solutions.

---
![pic](https://i.ibb.co.com/9kVgjd4p/Screenshot-from-2025-03-23-16-16-13.png)

### Two types of DP

- Buttom Up
- Top Down


![ex2](https://i.ibb.co.com/0ymVTXGh/Screenshot-from-2025-04-29-08-12-07.png)

<pre>
- dp[i][0] = you are picking elements from left to right, skipped the last element
- what is the maximum score you can get from (i to n-1)

dp[i][0] = max(arr[i]+dp[i+1][1], dp[i+1][0])
dp[i][1] = dp[i+1][0]
</pre>

```cpp
//without dp
int maxSubsequenceSum(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    
    int prev2 = 0;          // Represents dp[i-2] -> tracks the maximum sum up to i-2
    int prev1 = nums[0];    // Represents dp[i-1] -> tracks the maximum sum up to i-1
    
    for (size_t i = 1; i < nums.size(); i++) {
        int current = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
```
```cpp
//with dp (left to right)
int maxSubsequenceSum(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for (size_t i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);//0-i
    }
    return dp.back();
}
//right to left
int maxSubsequenceSum(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    vector<int> dp(n + 2, 0);  // Extra space to handle i+2 at the end
    
    // Start from the end and move left
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    }
    
    return dp[0];
}
```
```cpp
//Alternative DP Approach
int maxSubsequenceSum(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    
    // dp[i][0] = max sum not picking i-th element
    // dp[i][1] = max sum picking i-th element
    vector<vector<int>> dp(n, vector<int>(2));
    
    // Base case
    dp[0][0] = 0;          // Not picking first element
    dp[0][1] = nums[0];    // Picking first element
    
    for (int i = 1; i < n; i++) {
        // If we don't pick current element, take max of previous states
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        
        // If we pick current element, must not have picked previous
        dp[i][1] = nums[i] + dp[i-1][0];
    }
    return max(dp[n-1][0], dp[n-1][1]);
}
```