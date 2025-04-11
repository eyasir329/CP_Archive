#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> weight(1000100);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    weight[x]++;
  }
  int cnt = 0;
  for (int i = 0; i < weight.size(); i++)
  {
    weight[i + 1] += weight[i] / 2;
    weight[i] %= 2;
    cnt += weight[i];
  }
  cout << cnt << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}