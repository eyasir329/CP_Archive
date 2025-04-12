#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int n, m;
int arr[1005][1005];
int cnt = 0;

void spiralOfMatrix()
{
  int enrow = n, encol = m;
  int i, rowind = 0, colind = 0;
  string s, temp, temp2;
  bool fl1 = true, fl2 = true;
  // Loop through the matrix elements in a spiral pattern
  while (rowind < enrow && colind < encol)
  {
    // Print elements of the first row
    for (i = colind; i < encol; ++i)
    {
      s += arr[rowind][i] + '0';
      temp += arr[rowind][i] + '0';
    }
    auto it = temp.find("1543");
    if (it != string::npos)
    {
      fl1 = false;
      // upto prev
      temp2 = temp.substr(0, it);
    }
    else
    {
      temp2 = temp;
    }

    rowind++;

    // Print elements of the last column
    for (i = rowind; i < enrow; ++i)
    {
      s += arr[i][encol - 1] + '0';
      temp += arr[i][encol - 1] + '0';
    }
    if (fl1)
    {
      it = temp.find("1543");
      if (it != string::npos)
      {
        fl2 = false;
        // upto prev
        temp2 = temp.substr(0, it);
      }
      else
      {
        temp2 = temp;
      }
    }
    encol--;

    // Print elements of the last row if it is within matrix boundaries
    if (rowind < enrow)
    {
      for (i = encol - 1; i >= colind; --i)
      {
        s += arr[enrow - 1][i] + '0';
      }
      enrow--;
    }

    // Print elements of the first column if it is within matrix boundaries
    if (colind < encol)
    {
      for (i = enrow - 1; i >= rowind; --i)
      {
        s += arr[i][colind] + '0';
      }
      colind++;
    }
    // extra
    s += temp2;

    // cout << s << endl;
    it = s.find("1543");
    while (it != string::npos)
    {
      cnt++;
      it = s.find("1543", it + 1);
    }
    s.clear();
    temp.clear();
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    cnt = 0;
    cin >> n >> m;
    ;
    for (int i = 0; i < n; i++)
    {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++)
      {
        arr[i][j] = s[j] - '0';
      }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    spiralOfMatrix();
    cout << cnt << endl;
  }

  return 0;
}