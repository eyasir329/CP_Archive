#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  getline(cin, s); // string may have space
  stringstream ss(s);
  string word;
  map<string, int> mp;
  while (ss >> word)
  {
    mp[word]++;
  }
  for (auto [key, value] : mp)
  {
    cout << key << " " << value << endl;
  }
  return 0;
}