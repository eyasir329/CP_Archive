### <u>Factorial</u>

<pre>
n! is te number of ways to arrange n distinct objects in a line.
</pre>

![fact](https://i.ibb.co.com/K6QRB35/IMG-0232.jpg)
![fact2](https://i.ibb.co.com/Jk35g1g/IMG-0233.jpg)

<pre>
- The difference between combinations and permutations is whether or not the order you are choosing the objects matters.
</pre>

- Finding Power of Factorial Divisor

  You are given two numbers n  and  k . Find the largest power of k x such that n! is divisible by  k^x .

  https://cp-algorithms.com/algebra/factorial-divisors.html<br>
  https://artofproblemsolving.com/wiki/index.php/Factorial

  ```cpp
  //prime k
  //come from Legendre’s formula
  int fact_pow (int n, int k) {
      int res = 0;
      while (n) {
          n /= k;
          res += n;
      }
      return res;
  }
  ```

example:

- https://artofproblemsolving.com/wiki/index.php/2007_iTest_Problems/Problem_6
- https://artofproblemsolving.com/wiki/index.php/2003_AIME_I_Problems/Problem_1
- https://artofproblemsolving.com/wiki/index.php/2006_AIME_II_Problems/Problem_3

    <pre>Let P be the product of the first 100 positive odd integers. Find the largest integer k such that P is divisible by 3^k</pre>

- https://artofproblemsolving.com/wiki/index.php/1987_IMO_Problems/Problem_1

---
