#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int MAX = 1000007;  // Main sieve limit
bitset<MAX + 1> is_prime;
int primes[78499];  // Stores primes up to MAX
int primecnt = 0;

// Optimized sieve that populates both is_prime and primes[]
void optimized_sieve(int n) {
  is_prime.set();
  is_prime[0] = is_prime[1] = false;

  // Handle evens
  for (int i = 4; i <= n; i += 2) is_prime[i] = false;
  primes[primecnt++] = 2;

  // Sieve odd numbers
  for (int64_t i = 3; i <= n; i += 2) {
    if (is_prime[i]) {
      primes[primecnt++] = i;
      for (int64_t j = i * i; j <= n; j += 2 * i) is_prime[j] = false;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  optimized_sieve(1000005);
  set<int> stPrimes;
  for (auto x : primes) {
    if (x > 0) stPrimes.insert(x);
  }
  int n;
  while (cin >> n) {
    if (n == 0) break;
    for (auto x : stPrimes) {
      int other = n - x;
      auto it = stPrimes.lower_bound(other);
      if (it != stPrimes.end() and *it == other) {
        cout << n << " = " << x << " + " << other << endl;
        break;
      }
    }
  }
  return 0;
}