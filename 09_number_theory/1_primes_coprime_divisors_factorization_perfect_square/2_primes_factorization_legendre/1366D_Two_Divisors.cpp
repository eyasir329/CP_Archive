#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int mark[50000000 + 5];
void seive(int n) {
  mark[0] = mark[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (mark[i] > 0) continue;
    for (int m = 2 * i; m <= n; m += i) {
      mark[m] = i;
    }
  }
}
vector<int> factorize(int n) {  // O(logn)
  vector<int> ret;
  if (n == 1) return ret;
  while (mark[n] != 0) {  // no wasted
    ret.push_back(mark[n]);
    n /= mark[n];
  }
  ret.push_back(n);
  return ret;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  std::vector<int> a(n), a1(n), b1(n);
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
  }
  seive(maxi);
  for (int i = 0; i < n; i++) {
    std::vector<int> fact = factorize(a[i]);
    set<int> fa;
    for (auto x : fact) {
      fa.insert(x);
    }
    if (fa.size() == 1) {
      a1[i] = -1;
      b1[i] = -1;
    } else {
      auto x1 = *fa.begin();
      fa.erase(x1);
      a1[i] = x1;
      int a3 = 1;
      for (auto x : fa) {
        a3 *= x;
      }
      b1[i] = a3;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << b1[i] << " ";
  }
  cout << endl;
  return 0;
}