#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    int duration, deadline;
    cin >> duration >> deadline;
    a[i] = duration;
    ans += deadline;
  }
  sort(a.begin() + 1, a.end());
  ll finished_time = 0;
  for (int i = 1; i <= n; i++)
  {
    finished_time += a[i];
    ans -= finished_time;
  }
  cout << ans << endl;
  return 0;
}