#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

//{0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99};

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = 0, two = 0, three = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '2') {
        two++;
      } else if (s[i] == '3') {
        three++;
      }
      n += s[i] - '0';
      n %= 9;
    }
    bool fl = false;
    if (n % 9 == 0) fl = true;
    // all possible transformation
    for (int i = 0; i <= min(9, two); i++) {      // one extra
      for (int j = 0; j <= min(9, three); j++) {  // every ten it repeat
        if ((n + 2 * i + 6 * j) % 9 ==
            0) {  // everytime sum increase 2 for 2, 6 for 3
          fl = true;
          continue;
        }
      }
    }
    if (fl) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}