#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N], n, k;

bool pred(long long x)
{
  for (int i = 1; i <= n; i++)
  {
    if (a[i] > x)
    {
      return false;
    }
  }
  // min subarraysum<=x
  int subarray_cnt = 1;
  long long cur_sum = a[1];
  for (int i = 2; i <= n; i++)
  {
    if (cur_sum + a[i] <= x)
    {
      cur_sum += a[i];
    }
    else
    {
      cur_sum = a[i];
      subarray_cnt++;
    }
  }
  return subarray_cnt <= k;
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
  long long l = 0, r = 2e14, ans = 0;
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
  return 0;
}