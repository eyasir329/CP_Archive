#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];  //->0/1
    }
    // edge case
    if (n == 1 and v[0] == 0) {
      cout << 1 << " " << 2 << endl;
    } else if (n == 1 and v[0] == 1) {
      cout << 2 << " " << 1 << endl;
    }
    // 1 0 or 1 1
    else if (v[0] == 1) {
      cout << n + 1 << " " << 1 << " ";
      for (int i = 2; i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
    }
    // other
    else {
      bool ok = false;
      int pre = -1;
      for (int i = 0; i < n - 1; i++) {
        if (v[i] == 0 and v[i + 1] == 1) {
          ok = true;
          pre = i + 1;
          break;
        }
      }
      if (ok) {
        for (int i = 1; i <= n; i++) {
          if (i == pre) {
            cout << i << " " << n + 1 << " " << i + 1 << " ";
            i++;
          } else {
            cout << i << " ";
          }
        }
        cout << endl;
      } else {
        if (v[n - 1] == 0) {
          for (int i = 1; i <= n; i++) {
            cout << i << " ";
          }
          cout << n + 1 << endl;
        } else {
          cout << -1 << endl;
        }
      }
    }
  }
  return 0;
}