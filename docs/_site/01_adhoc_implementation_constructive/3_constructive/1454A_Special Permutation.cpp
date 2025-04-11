#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if (n & 1)
    {
      int sp = (n + 2 - 1) / 2;
      while (n > 1)
      {
        if (n != sp)
        {
          cout << n-- << " ";
        }
        else
        {
          n--;
        }
      }
      cout << 1 << " " << sp << endl;
    }
    else
    {
      while (n)
      {
        cout << n-- << " ";
      }
      cout << endl;
    }
  }

  return 0;
}