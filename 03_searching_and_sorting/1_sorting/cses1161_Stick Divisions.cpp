#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x, n;
  cin >> x >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  while (n--)
  {
    int d;
    cin >> d;
    pq.push(d);
  }
  ll ans = 0;
  while (pq.size() > 1)
  {
    int d1 = pq.top();
    pq.pop();
    int d2 = pq.top();
    pq.pop();
    pq.push(d1 + d2);
    ans += (d1 + d2);
  }
  cout << ans << endl;
  return 0;
}