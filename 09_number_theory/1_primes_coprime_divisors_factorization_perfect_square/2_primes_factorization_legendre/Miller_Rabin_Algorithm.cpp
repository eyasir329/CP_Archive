#include <cstdint>
#include <iostream>
using namespace std;

// Compute (a * b) % mod efficiently for large numbers (prevents overflow)
uint64_t mulmod(uint64_t a, uint64_t b, uint64_t mod) {
  uint64_t res = 0;
  a %= mod;
  while (b > 0) {
    if (b % 2 == 1) res = (res + a) % mod;
    a = (a * 2) % mod;
    b /= 2;
  }
  return res % mod;
}

// Compute (base^exp) % mod using fast exponentiation
uint64_t powmod(uint64_t base, uint64_t exp, uint64_t mod) {
  uint64_t res = 1;
  base %= mod;
  while (exp > 0) {
    if (exp % 2 == 1) res = mulmod(res, base, mod);
    base = mulmod(base, base, mod);
    exp /= 2;
  }
  return res;
}

// Miller-Rabin test for a given base 'a'
bool miller_rabin(uint64_t n, uint64_t a) {
  if (n <= 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0) return false;

  uint64_t d = n - 1;
  uint64_t s = 0;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }

  uint64_t x = powmod(a, d, n);
  if (x == 1 || x == n - 1) return true;

  for (uint64_t r = 1; r < s; r++) {
    x = mulmod(x, x, n);
    if (x == n - 1) return true;
    if (x == 1) return false;
  }
  return false;
}

// Deterministic Miller-Rabin for 64-bit integers (using specific bases)
bool isPrime(uint64_t n) {
  if (n < 2) return false;
  // Bases for deterministic test for 64-bit numbers
  const uint64_t bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (uint64_t a : bases) {
    if (n == a) return true;
    if (!miller_rabin(n, a)) return false;
  }
  return true;
}

int main() {
  uint64_t n;
  cout << "Enter a number: ";
  cin >> n;
  cout << (isPrime(n) ? "Prime" : "Composite") << endl;
  return 0;
}

// for cp
// This version is deterministic for 64-bit integers and extremely fast (works
// for numbers up to 2e64)

#include <cstdint>
#include <iostream>
using namespace std;

// Fast modular multiplication (avoids overflow)
uint64_t mulmod(uint64_t a, uint64_t b, uint64_t mod) {
  uint64_t res = 0;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res + a) % mod;
    a = (a << 1) % mod;
    b >>= 1;
  }
  return res;
}

// Fast modular exponentiation (a^b % mod)
uint64_t powmod(uint64_t a, uint64_t b, uint64_t mod) {
  uint64_t res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = mulmod(res, a, mod);
    a = mulmod(a, a, mod);
    b >>= 1;
  }
  return res;
}

// Miller-Rabin test for a single base
bool miller_rabin(uint64_t n, uint64_t a) {
  if (n < 2) return false;
  if (n % 2 == 0) return n == 2;

  uint64_t d = n - 1;
  uint64_t s = 0;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }

  uint64_t x = powmod(a, d, n);
  if (x == 1 || x == n - 1) return true;

  for (uint64_t r = 1; r < s; r++) {
    x = mulmod(x, x, n);
    if (x == n - 1) return true;
    if (x == 1) return false;
  }
  return false;
}

// Deterministic Miller-Rabin for 64-bit integers
bool is_prime(uint64_t n) {
  if (n < 2) return false;
  if (n == 2 || n == 3) return true;
  if (n % 6 != 1 && n % 6 != 5) return false;

  // Bases that work for all 64-bit numbers
  const uint64_t bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  for (uint64_t a : bases) {
    if (a >= n) break;
    if (!miller_rabin(n, a)) return false;
  }
  return true;
}

int main() {
  uint64_t n;
  cin >> n;
  cout << (is_prime(n) ? "Prime" : "Composite") << endl;
  return 0;
}