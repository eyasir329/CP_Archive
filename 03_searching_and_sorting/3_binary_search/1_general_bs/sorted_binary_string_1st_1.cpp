#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], x;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i <= n; i++)
  {
    a[i] = s[i - 1] - '0';
  }
  int ans = -1, l = 1, r = n;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (a[mid] == 1)
    {
      ans = mid;
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  cout << ans << endl;
}
