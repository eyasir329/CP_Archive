#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 7, mod = 1e9 + 7;  // N must be less than mod

int fact[N], ifact[N], iSum[N];

int power(int x, int n) {  // O(logn)
  int ans = 1;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int inverse(int a) {  // O(logmod)
  return power(a, mod - 2);
}

void prec() {  // O(n)
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
  }
  ifact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;  // 1/i! = (1/(i+1)!)*(i+1)
  }
}

bool check(int a, int b, int sum) {
  string s = to_string(sum);
  for (int i = 0; i < s.size(); i++) {
    if (!(s[i] == a + '0' or s[i] == b + '0')) {
      return 0;
    }
  }
  return 1;
}

int32_t main() {  // O(N + q)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  prec();
  int a, b, n;
  cin >> a >> b >> n;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int sum = a * i + b * (n - i);
    if (check(a, b, sum)) {
      cnt = (((fact[n] * ifact[i]) % mod * ifact[n - i]) % mod + cnt) % mod;
    }
  }
  string s = to_string(n);
  bool ok = true;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != 1 + '0') {
      ok = false;
      break;
    }
  }
  if (ok) {
    cnt++;
  }
  cout << cnt << endl;

  return 0;
}