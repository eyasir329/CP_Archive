#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

void solve1() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  while (q--) {
    int i;
    cin >> i;
    i--;
    char c;
    cin >> c;
    s[i] = c;
    int cnt = 0;
    auto it = s.find("abc");
    while (it != string::npos) {
      cnt++;
      it = s.find("abc", it + 1);
    }
    cout << cnt << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < (int)s.size() - 2; i++) {
    if (s[i] == 'a' and s[i + 1] == 'b' and s[i + 2] == 'c') {
      cnt++;
    }
  }
  while (q--) {
    int i;
    cin >> i;
    i--;
    char c;
    cin >> c;
    // pre
    for (int idx = i - 2; idx <= i; idx++) {
      if (idx >= 0 and idx + 2 < n) {
        if (s[idx] == 'a' and s[idx + 1] == 'b' and s[idx + 2] == 'c') {
          cnt--;
        }
      }
    }
    s[i] = c;
    // post
    for (int idx = i - 2; idx <= i; idx++) {
      if (idx >= 0 and idx + 2 < n) {
        if (s[idx] == 'a' and s[idx + 1] == 'b' and s[idx + 2] == 'c') {
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}