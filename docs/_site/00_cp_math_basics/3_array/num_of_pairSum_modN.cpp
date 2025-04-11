// number of pair whose sum %n ==0

/*
a[i]+b[j] %n = 0
b[j] = - a[i]%n
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n >> x;
  int arr[n + 1];
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  map<int, int> mp;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    int need = ((arr[i] % n) + n) % n;
    ans += mp[need];

    int cur = ((-arr[i] % n) + n) % n;
    mp[cur]++;
  }
  cout << ans << endl;
  return 0;
}