#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/blog/entry/73490

string to_binary(int x)
{
  string s;
  while (x > 0)
  {
    s += (x % 2 ? '1' : '0');
    x /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}

int main()
{
  cout << "13 = " << to_binary(13) << endl; // 1101
  // cout << bitset<8>(x);

  int x = 53;
  int y = 28;
  cout << "x = " << to_binary(x) << ", y = " << to_binary(y) << endl;

  cout << "AND, OR, XOR:" << endl;
  cout << to_binary(x & y) << " " << to_binary(x | y) << " " << to_binary(x ^ y) << endl;

  // xor - if one bit is one then one otherwise 0
}