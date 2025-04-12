/*
n binary string, each len upto n
how many pair of strings such that (difference beteen two strings(index same))<=k

distance in binary string <-> how many digit are different from each other
*/

// bruteforce O(n*n*n)
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
string s[N];

int dist(string &a, string &b)
{
  int n = a.size();
  int diff = 0;
  for (int i = 0; i < n; i++)
  {
    diff += a[i] != b[i];
  }
  return diff;
}

int main()
{
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (dist(s[i], s[j]) <= k)
      {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

// optimize solution O(n*n*n/64)
const int N = 1005;

int func()
{
  int n, k;
  cin >> n >> k;
  vector<string> vs(n);
  for (int i = 0; i < n; i++)
  {
    cin >> vs[i];
  }
  bitset<N> bs[n];
  for (int i = 0; i < n; i++)
  {
    bs[i] = bitset<N>(vs[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if ((bs[i] ^ bs[j]).count() <= k)
      {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
