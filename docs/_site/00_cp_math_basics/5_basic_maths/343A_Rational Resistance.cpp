#include <bits/stdc++.h>
using namespace std;

long long f(long long a, long long b)
{
  if (a < b)
    swap(a, b);
  if (b == 0)
    return 0;
  return a / b + f(b, a % b);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  long long a, b;
  cin >> a >> b;

  cout << f(a, b) << "\n";
}