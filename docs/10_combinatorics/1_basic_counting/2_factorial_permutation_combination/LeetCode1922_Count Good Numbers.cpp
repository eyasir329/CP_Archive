#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int mod = 1e9 + 7;

int power(int x, ll n) {  // O(logn)
  int ans = 1;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int countGoodNumbers(long long n) {
  ll numberOfeven = n / 2, numberOfodd = n / 2;
  if (n & 1) {
    numberOfeven++;
  }
  int evenCnt = 5, primeCnt = 4;
  int ans = power(evenCnt, numberOfeven);
  ans = (1LL * ans * power(primeCnt, numberOfodd)) % mod;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << countGoodNumbers(50) << endl;
  return 0;
}