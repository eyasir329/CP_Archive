#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7, mod = 1e9 + 7;

int fact[N], ifact[N];

int power(int x, int n)
{ // O(logn)
  int ans = 1;
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

int inverse(int a)
{ // O(logmod)
  return power(a, mod - 2);
}

void prec()
{ // O(n)
  fact[0] = 1;
  for (int i = 1; i < N; i++)
  {
    fact[i] = 1LL * fact[i - 1] * i % mod;
  }
  ifact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--)
  {
    ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod; // 1/i! = (1/(i+1)!)*(i+1)
  }
}

int32_t main()
{ // O(N + q)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  prec();
  string s;
  cin >> s;
  map<char, int> mp;
  for (auto x : s)
  {
    mp[x]++;
  }
  int n = s.size();
  int ans = fact[n];
  for (auto [_, a] : mp)
  {
    ans = 1LL * ans * ifact[a] % mod;
  }
  cout << ans << endl;
  return 0;
}