#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

vector<ll> factorize(ll n) {
  vector<ll> ret;
  if (n == 1) {
    return ret;
  }
  for (ll i = 2; i * i <= n; i++) {  // can go upto prime list
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      ret.push_back(i);
    }
  }
  if (n != 1) {  //>1
    ret.push_back(n);
  }
  return ret;
}

ll phi(ll n) {
  vector<ll> primes = factorize(n);  // unique primes
  for (ll p : primes) {
    n = n - n / p;
  }
  return n;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  while (cin >> n) {
    if (n == 0) break;
    cout << phi(n) << endl;
  }
  return 0;
}