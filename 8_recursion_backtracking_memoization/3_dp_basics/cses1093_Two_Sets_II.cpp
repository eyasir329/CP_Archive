#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  int total_sum = (n * (n + 1)) / 2;
  if (total_sum & 1)
  {
    cout << 0 << endl;
    return 0;
  }
  int target_sum = total_sum / 2;

  return 0;
}