#include <bits/stdc++.h>
using namespace std;

long long power(long long x, long long n, long long mod)
{
  long long ans = 1 % mod;
  while (n > 0)
  {
    if (n & 1)
    {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

// m is prime
long long inverse(long long a, long long mod)
{
  return power(a, mod - 2, mod);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long a, b, n;
  cin >> a >> b >> n;
  long long ans = a * inverse(b, n) % n;
  cout << ans << endl;
  return 0;
}