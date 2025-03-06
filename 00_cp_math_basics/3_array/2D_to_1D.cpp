#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  int arr[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  int farr[n * m];
  auto get_id = [&](int i, int j)
  {
    return i * m + j;
  };
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      farr[get_id(i, j)] = arr[i][j];
    }
  }
  for (int i = 0; i < n * m; i++)
  {
    cout << farr[i] << " ";
  }
  cout << endl;
  return 0;
}