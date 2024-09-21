#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string s;
  cin >> s;

  set<int> m0, m1;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '0')
    {
      m0.insert(i + 1);
    }
    else
    {
      m1.insert(i + 1);
    }
  }

  vector<string> results;

  while (!m0.empty() || !m1.empty())
  {
    int idx0 = -1, idx1 = -1, idx00 = -1;

    if (m0.empty())
    {
      cout << -1 << endl;
      return;
    }

    idx0 = *m0.begin();

    if (m1.empty())
    {
      for (auto x : m0)
      {
        string ss = to_string(1);
        ss += " " + to_string(x);
        results.push_back(ss);
      }
      break;
    }

    idx1 = *m1.begin();

    if (idx1 < idx0)
    {
      cout << -1 << endl;
      return;
    }

    auto it00 = m0.upper_bound(idx1);
    if (it00 != m0.end())
    {
      idx00 = *it00;
    }
    else
    {
      cout << -1 << endl;
      return;
    }

    int cnt = 3;
    string output = " " + to_string(idx0) + " " + to_string(idx1) + " " + to_string(idx00);

    m0.erase(m0.find(idx0));
    m1.erase(m1.find(idx1));
    m0.erase(m0.find(idx00));

    int currentLimit = idx00;

    while (true)
    {
      auto nextOne = m1.upper_bound(currentLimit);
      if (nextOne != m1.end())
      {
        auto nextZero = m0.upper_bound(*nextOne);
        if (nextZero != m0.end())
        {
          cnt += 2;
          currentLimit = *nextZero;
          output += " " + to_string(*nextOne) + " " + to_string(*nextZero);
          m1.erase(m1.find(*nextOne));
          m0.erase(m0.find(*nextZero));
        }
        else
        {
          break;
        }
      }
      else
      {
        break;
      }
    }

    string result = to_string(cnt) + output;
    results.push_back(result);
  }

  cout << results.size() << endl;
  for (const auto &res : results)
  {
    cout << res << endl;
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  while (t--)
    solve();
  return 0;
}
