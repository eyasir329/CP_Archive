#include <iostream>
using namespace std;

// Extended Euclidean Algorithm
// Returns gcd(a, b) and sets x and y such that a*x + b*y = gcd(a, b)
int extended_gcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int gcd = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}

int main() {
  int A, B;
  while (cin >> A >> B) {
    int X, Y, D;
    D = extended_gcd(A, B, X, Y);
    cout << X << " " << Y << " " << D << endl;
  }
  return 0;
}