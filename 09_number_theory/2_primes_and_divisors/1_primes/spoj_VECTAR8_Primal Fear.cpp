#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

int expo(int x, long long n)
{
  int ans = 1;
  while (n > 0)
  {
    if (n & 1)
    {
      ans = 1LL * ans * x;
    }
    x = 1LL * x * x;
    n >>= 1;
  }
  return ans;
}

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

int cnt[MAXN + 7];

bool toBeAfraid(int num)
{
  int dig = 0;
  int tmpNum = num;
  while (num > 0)
  {
    if (num % 10 == 0)
      return false;
    dig++;
    num /= 10;
  }
  int div = expo(10, dig - 1);
  num = tmpNum;
  while (num > 0)
  {
    num %= div;
    div /= 10;
    if (num != 0 and isPrime[num] == 1)
    {
      return false;
    }
  }
  return true;
}

void preCal()
{
  for (int i = 2; i <= MAXN; i++)
  {
    cnt[i] = cnt[i - 1];
    if (isPrime[i] == 0)
    {
      if (toBeAfraid(i))
      {
        cnt[i]++;
      }
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  cout << cnt[n] << endl;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  seive();
  preCal();
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}