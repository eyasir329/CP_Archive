#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int a[n + 1];
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  multiset<int> ms;
  for (int i = 1; i <= n; i++)
  {
    ms.insert(a[i]);
  }
  for (int i = 1; i <= m; i++)
  {
    int x;
    cin >> x;
    auto it = ms.find(x);
    if (it != ms.end())
    {
      ms.erase(it);
    }
  }
  cout << ms.size() << endl;
  return 0;
}