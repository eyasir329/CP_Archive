#include <iostream>
#include <string>

// adhoc/implementation

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string ch;
    cin >> ch;
    int sl = ch.size();
    if (sl > 10)
    {
      cout << ch.at(0) << sl - 2 << ch.back() << endl;
    }
    else
    {
      cout << ch << endl;
    }
  }

  return 0;
}