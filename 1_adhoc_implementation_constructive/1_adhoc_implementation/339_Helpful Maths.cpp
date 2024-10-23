#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin >> s;
  vector<int> arr;

  for (char c : s)
  {
    if (c >= '0' && c <= '9')
    {
      int a = static_cast<int>(c) - 48;
      arr.push_back(a);
    }
  }

  sort(arr.begin(), arr.end());

  for (int j = 0; j < arr.size(); j++)
  {
    if (j == arr.size() - 1)
    {
      cout << arr[j];
    }
    else
    {
      cout << arr[j] << "+";
    }
  }
  cout << endl;

  return 0;
}

/*
{
  int n, i, j = 0, a[110];
  string s;
  cin >> s;
  for (i = 0; i < s.length(); i += 2)
  {
    a[j] = s[i] - '0';
    j++;
  }
  sort(a, a + j);
  for (i = 0; i < j - 1; i++)
    cout << a[i] << '+';
  cout << a[j - 1] << endl;
}
*/