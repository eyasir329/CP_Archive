

### Memoization / DP

<pre>
- memoization is a technique used to optimize
</pre>

O(2^N)->O(N)

called only number of unique state.

- Power of two
  <details>
  <summary>Show Solution</summary>

  ```cpp
  vector<int> memo(100, -1);

  int power_of_two(int n) {
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = power_of_two(n - 1) + power_of_two(n - 1);
    return memo[n];
  }
  ```
  </details>

- Nth fibonacci number
  <details> <summary>Show Solution</summary>

  ```cpp
  int memo[100];

  int fibo(int n) {
    if (n <= 1) {
      return n;
    }
    if (memo[n] != -1) {
      return memo[n];
    }
    memo[n] = fibo(n - 1) + fibo(n - 2);
    return memo[n];
  }

  int32_t main() {
    fill(memo, memo + 100, -1);
    cout << fibo(20) << endl;
    return 0;
  }
  ```
  </details>

### Basic DP

- cses1623
- cf474d
- cses1093
- cf1703g
- cf1714d


### BackTracking

- count subsequence with given sum
- count paths in a matrix
- rat in a maze (print one ans, print all ans)
- N Queens

- https://codeforces.com/problemset/problem/1553/B

