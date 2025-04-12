#include <bits/stdc++.h>
using namespace std;

int n, a[20];
int targetSum, cnt;

void countSubsequence(int index, int currentSum)
{
  if (index == n)
  {
    if (targetSum == currentSum)
    {
      cnt++;
    }
    return;
  }

  countSubsequence(index + 1, currentSum + a[index]); // include
  countSubsequence(index + 1, currentSum);            // exclude
}

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  targetSum = 5;
  cnt = 0;
  countSubsequence(0, 0);
  cout << "number of sub-sequence with sum " << targetSum << ": " << cnt << endl;
  return 0;
}