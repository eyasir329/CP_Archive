#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  stack<char> st;
  for (auto c : s)
  {
    if (c == '(')
    {
      st.push(c);
    }
    else
    {
      if (s.empty())
      {
        cout << "NO" << endl;
        return 0;
      }
      else
      {
        st.pop();
      }
    }
  }
  if (st.empty())
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}