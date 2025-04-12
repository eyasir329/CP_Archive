#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e7;

std::vector<int> isPrime(MAXN + 7, 0);

void seive()
{
  isPrime[0] = isPrime[1] = 1;
  for (int i = 2; i * i <= MAXN; i++)
  {
    if (isPrime[i] == 0)
    {
      if (1LL * i * i <= MAXN)
      {
        for (int j = i * i; j <= MAXN; j += i)
        {
          isPrime[j] = 1;
        }
      }
    }
  }
}

int val[MAXN + 7];

void preCal()
{
  for (int x = 1; x * x <= MAXN; x++)
  {
    for (int y = 1; x * x + y * y * y * y <= MAXN; y++)
    {
      if (isPrime[x * x + y * y * y * y] == 0)
      {
        val[x * x + y * y * y * y] = 1;
      }
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  cout << val[n] << endl;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  seive();
  preCal();
  for (int i = 2; i <= MAXN; i++)
  {
    val[i] += val[i - 1];
  }
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}