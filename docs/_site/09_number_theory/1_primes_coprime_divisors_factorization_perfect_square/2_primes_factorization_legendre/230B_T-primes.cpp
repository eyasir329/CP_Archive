#include <bits/stdc++.h>
using namespace std;
#define int long long

int prime[1000006];

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  // 1 not prime -- 0 prime
  prime[0] = prime[1] = 1;
  for (int i = 2; i * i <= 1000000; i++)
  {
    if (prime[i] == 0)
    {
      for (int j = i * i; j <= 1000000; j += i)
      {
        prime[j] = 1;
      }
    }
  }
  int t = 1;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int sq = sqrt(n);
    if (sq * sq == n)
    {
      if (prime[sq] == 1)
      {
        cout << "NO" << endl;
      }
      else
      {
        cout << "YES" << endl;
      }
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}