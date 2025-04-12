#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int b, d;
    cin >> b >> d;
    mp[b]++;
    mp[d]--;
  }
  for (auto [x, i] : mp) {
    auto it = mp.find(x);
    if (it != mp.begin()) {
      it--;
      mp[x] += mp[it->first];
    }
  }
  int maxi = INT_MIN;  // max cnt
  for (auto [x, i] : mp) {
    maxi = max(maxi, i);
  }
  int ly = 0;  // min yr
  for (auto [x, i] : mp) {
    if (i == maxi) {
      ly = x;
      break;
    }
  }
  cout << ly << " " << maxi << endl;
  return 0;
}