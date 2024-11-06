#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  sort(s, s + n, [](string a, string b)
       { return a + b < b + a; });
  for (int i = 0; i < n; i++)
  {
    cout << s[i];
  }
  cout << endl;
  return 0;
}