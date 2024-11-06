/*
given array where 1<=ai<=1e9 of n<=1e5 and a number<=1e14
find the largest integer x for which floor(sum(ai/x)upto n)>=s
if no such then -1
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], n;
long long s;

bool f(int x)
{
  long long sum = 0;
  for (int i = 1; i <= n; i++)
  {
    sum += a[i] / x;
  }
  return sum >= x;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> s;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  int ans = -1, l = 1, r = 1e9;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (f(mid))
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
