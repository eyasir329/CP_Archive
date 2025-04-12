// smallest possible value of (a⊕x) + (b⊕x) for any given x

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
    int a, b;
    cin >> a >> b;
    string s1 = bitset<32>(a).to_string();
    string s2 = bitset<32>(b).to_string();
    string s(32, '0');
    for (int i = 0; i < 32; i++) {
      if ((s1[i] == '0' and s2[i] != '0') or (s1[i] != '0' and s2[i] == '0')) {
        s[i] = '1';
      }
    }
    cout << (bitset<32>(s)).to_ullong() << endl;
  }
  return 0;
}