#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int nmax = 1e6 + 7;

int sigma[nmax + 1], parr[nmax + 1];
bool mark[(int)1e7 + 1];

void seive() {
  // prime check
  mark[0] = mark[1] = true;
  for (int i = 4; i <= 1e7; i += 2) {  // even handle fast
    mark[i] = true;
  }
  for (int i = 3; 1LL * i * i <= 1e7; i += 2) {
    if (mark[i]) continue;
    for (int m = i * i; m <= 1e7; m += i + i) {
      mark[m] = true;
    }
  }
  // sum of divisors
  for (int i = 1; i < nmax; i++) {
    for (int m = i; m < nmax; m += i) {
      sigma[m] += i;
    }
  }
  // check sum of divisors is prime or not
  for (int i = 1; i < nmax; i++) {
    if (mark[sigma[i]] == false) {
      parr[i] = 1;
    }
  }
  // prefix sum
  for (int i = 1; i < nmax; i++) {
    parr[i] = parr[i] + parr[i - 1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  seive();
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    ll ans = parr[b] - parr[a - 1];
    cout << ans << endl;
  }
  return 0;
}