#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> factorize;
  for (int i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
    {
      factorize.push_back(i);
      n /= i;
    }
  }
  if (n != 1)
    factorize.push_back(n);
  if (factorize.size() >= k)
  {
    for (int i = 0; i < k - 1; i++)
    {
      cout << factorize[i] << " ";
    }
    int extra = 1;
    for (int i = k - 1; i < factorize.size(); i++)
    {
      extra *= factorize[i];
    }
    cout << extra << endl;
  }
  else
  {
    cout << -1 << endl;
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