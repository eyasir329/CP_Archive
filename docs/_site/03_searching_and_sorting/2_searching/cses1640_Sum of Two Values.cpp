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
  for (int i = 1; i <= n; i++)
  {
    int need = x - arr[i];
    if (mp.find(need) != mp.end())
    {
      cout << mp[need] << " " << i << endl;
      return 0;
    }
    mp[arr[i]] = i;
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}