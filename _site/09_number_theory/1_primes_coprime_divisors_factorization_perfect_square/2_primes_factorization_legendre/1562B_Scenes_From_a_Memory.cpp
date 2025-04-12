#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPrime(int n) {
  if (n <= 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}

void solve() {
  int l;
  string s;
  cin >> l >> s;

  // Check for single-digit non-primes (1, 4, 6, 8, 9)
  for (char c : s) {
    int digit = c - '0';
    if (digit == 1 || digit == 4 || digit == 6 || digit == 8 || digit == 9) {
      cout << "1\n" << digit << "\n";
      return;
    }
  }

  // Check for two-digit non-primes (excluding primes like 23, 37, etc.)
  for (int i = 0; i < l; i++) {
    for (int j = i + 1; j < l; j++) {
      int num = (s[i] - '0') * 10 + (s[j] - '0');
      if (!isPrime(num)) {
        cout << "2\n" << s[i] << s[j] << "\n";
        return;
      }
    }
  }

  // If all 2-digit combinations are prime, take the first 3 digits (guaranteed
  // non-prime)
  cout << "3\n" << s[0] << s[1] << s[2] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}