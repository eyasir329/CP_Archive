#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/find-the-sum-between-given-cells-of-a-3d-array/

// Function to calculate 3D prefix sum
void prefixSum3d(vector<vector<vector<int>>> &A, vector<vector<vector<int>>> &pre, int n)
{
  // Step 0: Initialize the base case
  pre[0][0][0] = A[0][0][0];

  // Step 1: Fill the first row, column, and depth using prefix sums
  for (int i = 1; i < n; i++)
    pre[i][0][0] = pre[i - 1][0][0] + A[i][0][0];
  for (int i = 1; i < n; i++)
    pre[0][i][0] = pre[0][i - 1][0] + A[0][i][0];
  for (int i = 1; i < n; i++)
    pre[0][0][i] = pre[0][0][i - 1] + A[0][0][i];

  // Step 2: Filling the first "faces" of the 3D array
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      pre[i][j][0] = A[i][j][0] + pre[i - 1][j][0] + pre[i][j - 1][0] - pre[i - 1][j - 1][0];
    }
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      pre[0][i][j] = A[0][i][j] + pre[0][i - 1][j] + pre[0][i][j - 1] - pre[0][i - 1][j - 1];
    }
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      pre[i][0][j] = A[i][0][j] + pre[i - 1][0][j] + pre[i][0][j - 1] - pre[i - 1][0][j - 1];
    }
  }

  // Step 3: Filling the remaining cells of the prefix sum array
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      for (int k = 1; k < n; k++)
      {
        pre[i][j][k] = A[i][j][k] + pre[i - 1][j][k] + pre[i][j - 1][k] + pre[i][j][k - 1] - pre[i - 1][j - 1][k] - pre[i - 1][j][k - 1] - pre[i][j - 1][k - 1] + pre[i - 1][j - 1][k - 1];
      }
    }
  }
}

// Function to calculate sum of elements in a subcube using prefix sum
int querySum(int lx, int rx, int ly, int ry, int lz, int rz, vector<vector<vector<int>>> &pre)
{
  int sum = pre[rx][ry][rz];

  if (lx > 0)
    sum -= pre[lx - 1][ry][rz];
  if (ly > 0)
    sum -= pre[rx][ly - 1][rz];
  if (lz > 0)
    sum -= pre[rx][ry][lz - 1];

  if (lx > 0 && ly > 0)
    sum += pre[lx - 1][ly - 1][rz];
  if (ly > 0 && lz > 0)
    sum += pre[rx][ly - 1][lz - 1];
  if (lx > 0 && lz > 0)
    sum += pre[lx - 1][ry][lz - 1];

  if (lx > 0 && ly > 0 && lz > 0)
    sum -= pre[lx - 1][ly - 1][lz - 1];

  return sum;
}

void solve()
{
  int n;
  cin >> n;

  // Input the 3D array
  vector<vector<vector<int>>> A(n, vector<vector<int>>(n, vector<int>(n)));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        cin >> A[i][j][k];
      }
    }
  }

  // Create the prefix sum array
  vector<vector<vector<int>>> prefixSum(n, vector<vector<int>>(n, vector<int>(n)));
  prefixSum3d(A, prefixSum, n);

  // Handle multiple queries
  int q;
  cin >> q;
  while (q--)
  {
    int lx, rx, ly, ry, lz, rz;
    cin >> lx >> rx >> ly >> ry >> lz >> rz;

    // Adjust for 0-based indexing
    lx--;
    rx--;
    ly--;
    ry--;
    lz--;
    rz--;

    // Query the sum of the subcube
    int result = querySum(lx, rx, ly, ry, lz, rz, prefixSum);
    cout << result << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

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
