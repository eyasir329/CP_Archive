#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, a[N], b[N];
long long k;
// pair of sums the k-th in ascending order.

int bs(int x)
{
  int l = 1, r = n, ans = 0;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (b[mid] <= x)
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  return ans;
}

bool pred(int x)
{
  long long cnt = 0;
  // using bs n*(logn*logn)
  for (int i = 1; i <= n; i++)
  {
    int need = x - a[i];
    cnt += bs(need);
  }
  return cnt >= k;
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
  for (int i = 1; i <= n; i++)
  {
    cin >> b[i];
  }
  sort(b + 1, b + n + 1);
  int l = 0, r = 2e9, ans = 0;
  while (l <= r)
  {
    int mid = l + (r - l) / 2;
    if (pred(mid))
    {
      ans = mid;
      r = mid - 1; // because of cnt>=k //we have to make smaller
    }
    else
    {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}