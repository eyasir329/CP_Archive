#include <bits/stdc++.h>
using namespace std;
#define int long long

// at least k prime numbers, that follow (prime = 1+x+y) two neighbouring prime +1 is also a prime number

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> prime;
  for (int i = 2; i <= n; i++)
  {
    bool fl = true;
    for (int j = 2; j * j <= i; j++)
    {
      if (i % j == 0)
      {
        fl = false;
      }
    }
    if (fl)
    {
      prime.push_back(i);
    }
  }
  int cnt = 0;
  for (int i = 0; i < prime.size() - 1; i++)
  {
    int num = 1 + prime[i] + prime[i + 1];
    bool fl = true;
    for (int j = 2; j * j <= num; j++)
    {
      if (num % j == 0)
      {
        fl = false;
        break;
      }
    }
    if (fl and num <= n)
      cnt++;
  }
  if (cnt >= k)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}