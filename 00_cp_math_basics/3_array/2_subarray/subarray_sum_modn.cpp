#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int arr[n + 1], pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    pref[i] = (((pref[i - 1] + arr[i]) % n) + n) % n; // because a[i] can be negative
  }
  map<int, int> mp;
  mp[pref[0]]++;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans += mp[pref[i]];
    mp[pref[i]]++;
  }
  cout << ans << endl;
  return 0;
}

// cses1662