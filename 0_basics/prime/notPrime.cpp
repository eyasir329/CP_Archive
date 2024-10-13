#include <bits/stdc++.h>
using namespace std;

// within three digit we find our answer

bool isPrime(int n)
{
  // Corner cases
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;

  // This is checked so that we can skip
  // middle five numbers in below loop
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;

  return true;
}

// https://codeforces.com/contest/1562/problem/B
void notPrime()
{
  int l;
  cin >> l;
  string s;
  cin >> s;
  // Check for one non-prime digits
  for (int i = 0; i != l; i++)
  {
    if (s[i] != '2' && s[i] != '3' && s[i] != '5' && s[i] != '7')
    {
      cout << 1 << endl;
      cout << s[i] << endl;
      return;
    }
  }
  // Check for two non-prime digits
  for (int i = 1; i != l; i++)
  {
    for (int j = 0; j != i; j++)
    {
      int x = (s[j] - '0') * 10 + s[i] - '0';
      if (x != 37 && x != 23 && x != 53 && x != 73) /// not include 1 or any composite // otherwise check isPrime or not
      {
        cout << 2 << endl;
        cout << s[j] << s[i] << endl;
        return;
      }
    }
  }
  // Check for three non-prime digits
  for (int i = 2; i < l; i++)
  {
    for (int j = 1; j < i; j++)
    {
      for (int k = 0; k < j; k++)
      {
        int x = (s[k] - '0') * 100 + (s[j] - '0') * 10 + (s[i] - '0');
        if (!isPrime(x))
        {
          cout << 3 << endl;
          cout << s[k] << s[j] << s[i] << endl;
          return;
        }
      }
    }
  }
}