#include <bits/stdc++.h>
using namespace std;

int n, k;

bool pred(long long x)
{
  return (x - x / n) >= k;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> k;
    long long l = 0, r = 2e9, ans = 0;
    while (l <= r)
    {
      long long mid = l + (r - l) / 2;
      if (pred(mid))
      {
        ans = mid;
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}