#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

vector<ll> factorize(ll n) {
  vector<ll> ret;
  if (n == 1) {
    return ret;
  }
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
        ret.push_back(i);
      }
    }
  }
  if (n != 1) {
    ret.push_back(n);
  }
  return ret;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  while (cin >> n) {
    if (n == 0) break;
    vector<ll> fact = factorize(n);
    map<ll, int> mp;
    for (int i = 0; i < fact.size(); i++) {
      mp[fact[i]]++;
    }
    for (auto [x, i] : mp) {
      cout << x << "^" << i << " ";
    }
    cout << endl;
  }
  return 0;
}