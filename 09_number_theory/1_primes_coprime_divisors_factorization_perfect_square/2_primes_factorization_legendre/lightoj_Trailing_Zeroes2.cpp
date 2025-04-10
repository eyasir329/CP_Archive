#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int legendre(int n, int p) {  // how many p in n!
  int exponent = 0;
  while (n > 0) {
    n /= p;
    exponent += n;
  }
  return exponent;
}

int getPower(int x, int p) {  // how many p in x
  int ret = 0;
  while (x % p == 0) {
    x /= p;
    ret++;
  }
  return ret;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, r, p, q;
    cin >> n >> r >> p >> q;

    //(nCr×p^q)-> n!/(r!(n-r)!) * p^q
    ll cnt2 = 0, cnt5 = 0;
    cnt2 += legendre(n, 2);
    cnt2 -= legendre(r, 2);
    cnt2 -= legendre(n - r, 2);
    cnt2 += (getPower(p, 2) * q);

    cnt5 += legendre(n, 5);
    cnt5 -= legendre(r, 5);
    cnt5 -= legendre(n - r, 5);
    cnt5 += (getPower(p, 5) * q);

    cout << "Case " << i << ": " << min(cnt2, cnt5) << endl;
  }
  return 0;
}