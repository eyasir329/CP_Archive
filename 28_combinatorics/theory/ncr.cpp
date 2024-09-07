#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1000000007;
const ll N = 1000003;
ll fact[N];
ll modinv[N];

ll power(ll base, ll x)
{
  if (x < 0)
    return 0;
  ll ans = 1;
  while (x)
  {
    if (x % 2 == 0)
    {
      base = (base * base) % mod;
      x = x / 2;
    }
    else
    {
      ans = (ans * base) % mod;
      x--;
    }
  }
  return ans;
}

void precomp()
{
  fact[0] = 1;
  modinv[0] = 1;
  for (ll i = 1; i < 200000; i++)
  {
    fact[i] = (fact[i - 1] * i) % mod;
    modinv[i] = power(fact[i], mod - 2);
  }
}

ll ncr(ll n, ll r)
{
  if (r > n or n < 0 or r < 0)
    return 0;
  ll numo = fact[n];
  ll invdeno = (modinv[r] * modinv[n - r]) % mod;
  ll ans = (numo * invdeno) % mod;
  return ans;
}

void solve()
{
  // do ncr here
}

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  precomp();
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}