#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<string> gen = {"1869", "1968", "1689", "6198", "1698", "1986", "1896"};

bool check(string s)
{
  int mod = 0;
  for (auto i : s)
  {
    mod = (mod * 10 + i - '0') % 7;
  }
  return mod == 0;
}

void solve()
{
  string s;
  cin >> s;
  vector<int> digit(10);
  for (auto i : s)
  {
    digit[i - '0']++;
  }
  digit[1]--;
  digit[6]--;
  digit[8]--;
  digit[9]--;

  s = "";
  for (int i = 1; i < 10; i++)
  {
    s += (string(digit[i], i + '0'));
  }

  for (auto g : gen)
  {
    if (check(s + g + string(digit[0], '0')))
    {
      cout << s + g + string(digit[0], '0') << endl;
      return;
    }
  }
  cout << 0 << endl;
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

// optimize version
string s;
main()
{
  for (cin >> s;; next_permutation(begin(s), end(s)))
  {
    int x = 0;
    for (int i : s)
      x = (x * 10 + i - 48) % 7;
    if (!x)
      cout << s, exit(0);
  }
}
// other way
/*
string s;
cin >> s;
while (true)
{
  int n = 0;
  for (int i = 0; i < s.size(); i++)
  {
    n *= 10;
    n += (s[i] - 48);
    n %= 7;
  }
  if (n == 0)
  {
    cout << s;
    return;
  }
  next_permutation(s.begin(), s.end());
}
*/