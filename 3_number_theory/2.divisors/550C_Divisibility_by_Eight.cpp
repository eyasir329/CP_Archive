#include <bits/stdc++.h>
using namespace std;

// 100 digit long number... after remove some digit make it divisible by 8
// if at least one->three digit is divisible by this, then num is divisible by that
// 0 is divisible by all num

int main()
{
  string s;
  cin >> s;
  // one digit
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '8' or s[i] == '0')
    {
      cout << "YES" << endl;
      cout << s[i] << endl;
      return 0;
    }
  }
  // two digit
  for (int i = 0; i < s.size(); i++)
  {
    for (int j = i + 1; j < s.size(); j++)
    {
      int num = (s[i] - '0') * 10 + (s[j] - '0');
      if (num % 8 == 0)
      {
        cout << "YES" << endl;
        cout << num << endl;
        return 0;
      }
    }
  }
  // three digit
  for (int i = 0; i < s.size(); i++)
  {
    for (int j = i + 1; j < s.size(); j++)
    {
      for (int k = j + 1; k < s.size(); k++)
      {
        int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
        if (num % 8 == 0)
        {
          cout << "YES" << endl;
          cout << num << endl;
          return 0;
        }
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}