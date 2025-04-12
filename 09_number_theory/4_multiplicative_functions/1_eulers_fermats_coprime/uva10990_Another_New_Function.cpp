#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int maxn = 2000000 + 7;

int phi[maxn], dphi[maxn];
ll psum[maxn];
bool mark[maxn];

void seive() {
  for (int i = 1; i < maxn; i++) {
    phi[i] = i;
  }
  for (int i = 2; i < maxn; i++) {
    if (mark[i]) continue;
    phi[i] = i - 1;  // for i which is prime
    for (int j = i + i; j < maxn; j += i) {
      mark[j] = true;
      phi[j] = phi[j] - phi[j] / i;
    }
  }
  dphi[1] = 0;
  for (int i = 2; i < maxn; i++) {
    int phitemp = phi[i];
    dphi[i] = dphi[phitemp] + 1;
  }
  for (int i = 2; i < maxn; i++) {
    psum[i] = psum[i - 1] + dphi[i];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  seive();
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    ll ans = psum[m];
    ans -= psum[n - 1];
    cout << ans << endl;
  }
  return 0;
}