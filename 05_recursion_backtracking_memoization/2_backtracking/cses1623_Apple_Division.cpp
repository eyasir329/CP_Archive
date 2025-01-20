#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int a[21];
int total_sum =0;

int solve(int i = 0, int current_sum = 0)
{
  if(i==n){
    int other_sum = total_sum-current_sum;
    return abs(current_sum-other_sum);
  }
  int pick = solve(i+1,current_sum+a[i]);
  int not_pick = solve(i+1,current_sum);
  return min(pick,not_pick);
}

int32_t main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    total_sum+=a[i];
  }
  cout << solve() << endl;
  return 0;
}