#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

//{0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99};

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    int n = 0, two = 0, three = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '2')
      {
        two++;
      }
      else if (s[i] == '3')
      {
        three++;
      }
      n += s[i] - '0';
      n %= 9;
    }
    // 2 -> 2, 4(2^2 | 2*2), 6(3*2), 8(4*2 | 2^2*2)
    // 3 -> 0, 3, 6(3*2), 9(3*3, 3^2)
    bool fl = false;
    if (n % 9 == 0)
      fl = true;
    for (int i = 0; i <= min(9, two); i++)
    {
      for (int j = 0; j <= min(9, three); j++)
      {
        if ((n + 2 * i + 6 * j) % 9 == 0)
        {
          fl = true;
          continue;
        }
      }
    }
    if (fl)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}