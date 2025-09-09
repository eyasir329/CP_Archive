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
  priority_queue<int> pq;
  for (int i = 1; i <= n; i++)
  {
    pq.push(a[i]);
    if (pq.size() > k)
    {
      pq.pop();
    }
    if (i >= k)
    {
      cout << pq.top() << " ";
    }
    else
    {
      cout << -1 << endl; // if not have enough elements
    }
  }
  return 0;
}