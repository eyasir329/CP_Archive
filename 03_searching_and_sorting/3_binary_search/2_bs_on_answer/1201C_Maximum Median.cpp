#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N], n, k;

bool pred(int x)
{
  long long min_operations = 0;
  for (int i = (n + 1) / 2; i <= n; i++)
  {
    if (a[i] < x)
    {
      min_operations += (x - a[i]);
    }
  }
  return min_operations <= k;
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
  sort(a + 1, a + n + 1);
  int l = 0, r = 2e9, ans = 0;
  while (l <= r)
  {
    int mid = l + (r - l) / 2;
    if (pred(mid))
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}