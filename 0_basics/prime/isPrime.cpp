#include <bits/stdc++.h>
using namespace std;

// generat way to find prime or not
bool isPrime(int n)
{
  // If number is less than/equal to 1,
  // it is not prime
  int cnt = 0;
  if (n <= 1)
    return false;
  else
  {

    // Check for divisors from 1 to n
    for (int i = 1; i <= n; i++)
    {

      // Check how many number is divisible
      // by n
      if (n % i == 0)
        cnt++;
    }

    // If n is divisible by more than 2 numbers
    // then it is not prime
    if (cnt > 2)
      return false;

    // else it is prime
    else
      return true;
  }
}

// optimum way
//  Function that returns true if n
//  is prime else returns false
bool isPrime(int n)
{
  // Corner cases
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;

  // This is checked so that we can skip
  // middle five numbers in below loop
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;

  return true;
}
