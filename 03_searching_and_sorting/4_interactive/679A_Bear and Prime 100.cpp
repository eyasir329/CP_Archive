#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}

bool query(int i)
{
  cout << i << endl;
  string s;
  cin >> s;
  return s == "yes";
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  int prime_div = 0;
  if (query(2 * 2) or query(3 * 3) or query(5 * 5) or query(7 * 7))
  { // edge case 11*11>100
    cout << "composite" << endl;
    return 0;
  }
  for (int i = 2; i <= 50; i++)
  {
    if (is_prime(i))
    {
      prime_div += query(i);
    }
  }
  if (prime_div <= 1)
  {
    cout << "prime" << endl;
  }
  else
  {
    cout << "composite" << endl;
  }
  return 0;
}
