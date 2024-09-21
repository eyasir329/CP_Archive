#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n, q;
  cin >> n >> q;
  std::vector<int> prime;
  std::vector<bool> isActivated(n + 1);
  std::vector<int> activateFactor(n + 1);
  while (q--)
  {
    char type;
    cin >> type;
    int x;
    cin >> x;
    if (type == '+' and isActivated[x])
    {
      cout << "Already on" << endl;
      continue;
    }
    if (type == '-' and !isActivated[x])
    {
      cout << "Already off" << endl;
      continue;
    }
    prime.clear();
    int num = x;
    for (int i = 2; i * i <= num; i++)
    {
      if (num % i == 0)
      {
        prime.push_back(i);
      }
      while (num % i == 0)
      {
        num /= i;
      }
    }
    if (num > 1)
    {
      prime.push_back(num);
    }
    if (type == '+')
    {
      int j = 0;
      for (auto p : prime)
      {
        if (activateFactor[p] != 0)
        {
          j = activateFactor[p];
          break;
        }
      }
      if (j != 0)
      {
        cout << "Conflict with " << j << endl;
      }
      else
      {
        isActivated[x] = true;
        for (auto p : prime)
        {
          activateFactor[p] = x;
        }
        cout << "Success" << endl;
      }
    }
    else
    {
      isActivated[x] = false;
      for (auto p : prime)
      {
        activateFactor[p] = 0;
      }
      cout << "Success" << endl;
    }
  }
}

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}