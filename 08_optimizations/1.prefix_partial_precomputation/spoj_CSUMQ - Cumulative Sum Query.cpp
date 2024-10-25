#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;
  cin >> n;
  std::vector<int> nums(n), prefix(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  prefix[0] = nums[0];
  for (int i = 1; i < n; i++)
  {
    prefix[i] = nums[i] + prefix[i - 1];
  }
  int q;
  cin >> q;
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    if (l == 0)
    {
      cout << prefix[r] << endl;
    }
    else
    {
      cout << prefix[r] - prefix[l - 1] << endl;
    }
  }

  return 0;
}