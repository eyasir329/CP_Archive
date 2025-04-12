#include <bits/stdc++.h>
using namespace std;

/*
n<=1e6
1<=k<=1e9
oeach k occurances
find k*ck sum for 1 to 1e9
*/

// if(k<=1e6)
const int N = 1e6 + 9;
int cnt[N];

int main()
{
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++)
  {
    cnt[a[i]]++;
  }
  long long ans = 0;
  for (int k = 1; k <= 1e6; k++)
  {
    ans += 1LL * k * cnt[k];
  }
  cout << ans << endl;
  return 0;
}

// if(k<=1e9)
// cnt upto 1e9
map<int, int> cnt1;

int func2()
{
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) // nlogn
  {
    cnt1[a[i]]++;
  }
  long long ans = 0;
  for (auto [key, value] : cnt1) // if not in map, whose cnt =0 (1LL*key*0==0)
  {
    ans += 1LL * key * value;
  }
  cout << ans << endl;
  return 0;
}

// we need better solution which in O(n)
struct custom_hash
{
  static uint64_t splitmix64(uint64_t x)
  {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const
  {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
unordered_map<int, int, custom_hash> cnt2;

int func3()
{
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) // nlogn
  {
    cnt2[a[i]]++;
  }
  long long ans = 0;
  for (auto [key, value] : cnt2) // if not in map, whose cnt =0 (1LL*key*0==0)
  {
    ans += 1LL * key * value;
  }
  cout << ans << endl;
  return 0;
}