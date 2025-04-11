#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {  // O(N + q)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    int total_combination = i * i * (i * i - 1) / 2;
    int ans = total_combination;
    if (i == 3) {
      int total_way_then_can_attack = ((1LL * 2 * 2) * 2);
      ans -= total_way_then_can_attack;
    } else if (i > 3) {
      int exist23 = (1LL * (i - 1) * (i - 2));
      int exist32 = (1LL * (i - 2) * (i - 1));
      int total_way_then_can_attack = exist23 * 2 + exist32 * 2;
      ans -= total_way_then_can_attack;
    }
    cout << ans << endl;
  }
  return 0;
}