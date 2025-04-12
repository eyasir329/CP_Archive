#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
// using recursive technique
int power(int x, long long n) {
  if (n == 0) return 1 % mod;  // base case
  int cur = power(x, n / 2);   // to compute (x^(n/2)) % mod
  if (n % 2 == 0) {
    return 1LL * cur * cur % mod;
  } else {
    return 1LL * cur * cur % mod * x % mod;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;
  }
  return 0;
}
