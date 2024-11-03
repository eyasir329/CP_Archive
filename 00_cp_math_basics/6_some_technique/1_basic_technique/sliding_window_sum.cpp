#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  queue<int> q;
  int sum = 0;
  for (int i = 1; i <= k; i++)
  {
    q.push(a[i]);
    sum += a[i];
  }
  for (int i = k; i <= n; i++)
  {
    cout << sum << " ";
    sum -= q.front();
    q.pop();
    if (i + 1 <= n)
    {
      q.push(a[i + 1]);
      sum += a[i + 1];
    }
  }
  return 0;
}