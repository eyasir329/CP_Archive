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
  ll n, m, k;
  cin >> n >> m >> k;
  ll ans = 0;
  while (k--)
  {
    ll x, y, p;
    cin >> x >> y >> p;
    // c1
    // ll nn1 = x-1 + y-1;//total n+r row+col
    ll nn1 = x + y - 2; // total n+r row+col
    ll rr1 = x - 1;     // n row
    ll c1 = ncr(nn1, rr1);
    // c2
    // ll nn2 = (n-x+1)-1+(m-y+1)-1;
    ll nn2 = n + m - x - y;
    ll rr2 = n - x;
    ll c2 = ncr(nn2, rr2);

    p = (p * c1) % mod;
    p = (p * c2) % mod;
    ans = (ans + p) % mod;
  }
  cout << ans << endl;
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