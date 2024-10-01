#include <bits/stdc++.h>
using namespace std;
#define int long long

int findLengthOfShortestSubarray(vector<int> &arr)
{
  int n = arr.size();

  int left = 0;
  while (left + 1 < n && arr[left] <= arr[left + 1])
  {
    left++;
  }

  if (left == n - 1)
  {
    return 0;
  }

  int right = n - 1;
  while (right > 0 && arr[right - 1] <= arr[right])
  {
    right--;
  }

  int result = min(n - left - 1, right);

  int i = 0, j = right;
  while (i <= left && j < n)
  {
    if (arr[i] <= arr[j])
    {
      result = min(result, j - i - 1);
      i++;
    }
    else
    {
      j++;
    }
  }

  return result;
}

void solve()
{
  std::vector<int> arr = {1, 2, 3, 10, 4, 2, 3, 5};
  cout << findLengthOfShortestSubarray(arr) << endl;
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