#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N], n, k;

bool func(long long x)
{
  __int128_t work = 0;
  for (int i = 1; i <= n; i++)
  {
    work += x / a[i];
  }
  return work >= k;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  sort(a, a + n);
  long long ans = -1, l = 1LL, r = 1e18;
  while (l <= r)
  {
    long long mid = (l + r) / 2;
    if (func(mid))
    {
      ans = mid;
      r = mid - 1; // for more less value
    }
    else
    {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}