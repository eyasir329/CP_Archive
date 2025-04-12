#include <bits/stdc++.h>
using namespace std;
#define int long long

int maxMeetings(int n, vector<int> start, vector<int> end)
{
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++)
  {
    p.push_back({end[i], start[i]});
  }
  sort(p.begin(), p.end());
  int cnt = 0;
  int prevEnd = 0;
  for (int i = 0; i < n; i++)
  {
    if (p[i].second >= prevEnd)
    {
      cnt++;
      prevEnd = p[i].first + 1;
    }
  }
  return cnt;
}

void solve()
{
  int n = 8;
  vector<int> start = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924},
              end = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252};
  cout << maxMeetings(n, start, end) << endl;
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