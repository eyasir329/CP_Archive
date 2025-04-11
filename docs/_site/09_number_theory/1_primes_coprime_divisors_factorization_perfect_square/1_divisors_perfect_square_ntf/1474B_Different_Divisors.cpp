#include <bits/stdc++.h>
using namespace std;
#define int long long

// x have at lest 4 divisors and difference of any two of them at lest d
// 1,p,q,pq -- 1,p,p*p,p*p*p

void solve()
{
  int d;
  cin >> d;
  int a, b;
  for (int i = 1 + d;; i++)
  {
    int cnt = 0;
    for (int j = 2; j * j <= i; j++)
    {
      if (i % j == 0)
        cnt++;
    }
    if (cnt == 0)
    {
      a = i;
      break;
    }
  }
  for (int i = a + d;; i++)
  {
    int cnt = 0;
    for (int j = 2; j * j <= i; j++)
    {
      if (i % j == 0)
        cnt++;
    }
    if (cnt == 0)
    {
      b = i;
      break;
    }
  }
  cout << min(a * b, a * a * a) << endl;
}

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}