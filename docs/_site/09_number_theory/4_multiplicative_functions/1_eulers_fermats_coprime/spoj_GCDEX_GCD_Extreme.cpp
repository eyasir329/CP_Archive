#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int maxn = 1000000;
ll phi[maxn + 1], S[maxn + 1], A[maxn + 1];
bool mark[maxn + 1];

void seive() {
  for (int i = 1; i <= maxn; i++) {
    phi[i] = i;
  }
  for (int i = 2; i <= maxn; i++) {
    if (mark[i]) continue;
    phi[i] = i - 1;  // for i which is prime
    for (int j = i + i; j <= maxn; j += i) {
      mark[j] = true;
      phi[j] = phi[j] - phi[j] / i;
    }
  }
  for (int i = 1; i <= maxn; i++) {
    for (int j = i; j <= maxn; j += i) {
      S[j] += 1LL * i * phi[j / i];
    }
  }
  for (int i = 1; i <= maxn; i++) {
    A[i] = S[i] + A[i - 1] - i;  // subtract gcd(n,n)
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  seive();
  int n;
  while (cin >> n) {
    if (n == 0) break;
    cout << A[n] << endl;
  }
  return 0;
}