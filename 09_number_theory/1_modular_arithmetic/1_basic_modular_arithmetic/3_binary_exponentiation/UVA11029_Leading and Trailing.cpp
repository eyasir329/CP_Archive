#include <cmath>
#include <iostream>
using namespace std;

long long modExp(long long base, long long exp, long long mod) {
  long long result = 1;
  base = base % mod;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp = exp / 2;
  }
  return result;
}

long long calculateFirstThreeDigits(long long base, long long exp) {
  double logValue = exp * log10(base);  // log(n^k) = k * log10(n)
  double fractionalPart = logValue - floor(logValue);  // Get fractional part
  long long firstThree =
      (long long)(pow(10, fractionalPart) * 100);  // Get first 3 digits

  /*more precious for finding first three digit
  ld lg=(ld)m*log10((ld)n); //ld = long double
                lg -= floor(lg) - 2;
                lg = pow((ld)10,lg);
                cout<<floor(lg+1e-9)<<"..."<<l<<endl;
  */
  return firstThree;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long lastThree = modExp(n, k, 1000);
    long long firstThree = calculateFirstThreeDigits(n, k);
    cout << firstThree << "..." << lastThree << endl;
  }
  return 0;
}

// 2nd type

#define ld long double

long long calculateFirstThreeDigits(long long n, long long m) {
  ld lg = (ld)m * log10((ld)n);
  lg -= floor(lg) - 2;
  ld firstDigits = pow((ld)10, lg);
  return (long long)firstDigits + 1e-9;
}

string formatLastThreeDigits(long long digits) {
  string result = to_string(digits);
  while (result.length() < 3) {
    result = "0" + result;  // Pad with leading zeros if necessary
  }
  return result;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long lastThree = modExp(n, k, 1000);
    long long firstThree = calculateFirstThreeDigits(n, k);
    cout << firstThree << "..." << formatLastThreeDigits(lastThree) << endl;
  }
  return 0;
}