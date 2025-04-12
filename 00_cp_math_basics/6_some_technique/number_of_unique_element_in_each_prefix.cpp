#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  set<int> st;
  for (int i = 1; i <= n; i++)
  {
    st.insert(a[i]);
    cout << st.size() << endl;
  }
  return 0;
}