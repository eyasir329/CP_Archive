### Divisibility Rules

<pre>
- The divisibility rule for 3 is based on the <b>canonical sum of the digits</b>
-> <i>A number is divisible by 3 if and only if the sum of its digits is divisible by 3</i>

<b>N = a<sup>k</sup>⋅10<sup>k</sup> + a<sup>k−1</sup>⋅10<sup>k−1</sup> + ⋯ + a<sup>1</sup>⋅10<sup>1</sup> + a<sup>0</sup>.10<sup>0</sup></b> - decimal representation of a number

10 ≡ 1 (mod 3)
10<sup>n</sup> ≡ 1 (mod 3),for any n≥0. (Raising 10 to any power preserves this property)
then, N = a<sup>k</sup>⋅1 + a<sup>k−1</sup>⋅1 + ⋯ + a<sup>1</sup>⋅1
thus, N ≡ (sum of digits of N) (mod 3).

- Divisivility Rule of 6 (2, 3 both to be divisible), 12 (3, 4 both)
- Divisivility Rule of 7 (it suffices to remove its final digit and then subtract twice this digit from whatever remains. For example, we can say 434 is divisible by 7 because 43 − 2(4) = 35)
</pre>

https://unacademy.com/content/clat/study-material/quantitative-techniques/divisibility-rule/<br>
https://www.cuemath.com/numbers/divisibility-rules/

source:- Introduction to Number Theory by Mathew Crawford
![divisibility rule](https://i.ibb.co.com/sgwxRDp/IMG-0046.jpg)

example:

- [2014 AMC 8 Problems/Problem 8](https://artofproblemsolving.com/wiki/index.php/2014_AMC_8_Problems/Problem_8)

    <pre>Eleven members of the Middle School Math Club each paid the same amount for a guest speaker to talk about problem solving at their math club meeting. They paid their guest speaker $1A2. What is the missing digit A of this 3-digit number? 
    
  -> it must be <b>divisible by 11</b>
  We know that a number is divisible by 11 if the odd digits added together minus the even digits added together (or vice versa) is a multiple of 11. Thus, we have $1+2-A = a multiple of 11. The only multiple that works here is 0, as 11 . 0 = 0. Thus, A = 3
    </pre>

- [2018 AMC 8 Problems/Problem 7](https://artofproblemsolving.com/wiki/index.php/2018_AMC_8_Problems/Problem_7)

  <pre>
  The 5-digit number 2 0 1 8 U is divisible by 9. What is the remainder when this number is divided by 8?
  
  -> By the <b>divisibility rule for 9</b>,
  2 + 0 + 1 + 8 + U ≡ 2 + U ≡ 0 (mod 9) =⇒ U ≡ 7 (mod 9).
  By the <b>divisibility rule of 2<sup>k</sup></b>, since 8 = 2<sup>3</sup>, the answer is 187(last m digit) mod 8 = 3
  </pre>

- [2016 AMC 8 Problems/Problem 24](https://artofproblemsolving.com/wiki/index.php/2016_AMC_8_Problems/Problem_24)

    <pre>The digits 1, 2, 3, 4, and 5 are each used once to write a five-digit number PQRST. The three-digit number PQR is divisible by 4, the three-digit number QRS is divisible by 5, and the three-digit number RST is divisible by 3. What is P?
  
  -> Since QRS is divisible by 5, S must be 5 (it can't be 0 because all digits are unique).
  PQR must be even, so R is 2 or 4.
  If R = 2, T would repeat a digit, which is not allowed. So, R = 4.
  With R = 4, T must be 3.
  Q can be 1 or 2.
  24 (from QR) is divisible by 4, but 14 is not. So, Q = 2.
  The only remaining digit is P = 1.
  </pre>

- [2017 AMC 10A Problems/Problem 20](https://artofproblemsolving.com/wiki/index.php/2017_AMC_10A_Problems/Problem_20)

  <pre>Let S(n) equal the <b>sum of the digits of positive integer n</b>. For example, S(1507) = 13. For a particular positive integer n, S(n) = 1274. Which of the following could be the value of S(n + 1)? (A) 1 (B) 3 (C) 12 (D) 1239 (E) 1265
  
  -> Note that n ≡ S(n) (mod 9). 
  This follows from the fact that:
      ∑(k=0 to n) 10^k * a_k ≡ ∑(k=0 to n) a_k (mod 9).
  If S(n) = 1274, then:
      n ≡ 5 (mod 9).
  Thus:
      n+1 ≡ S(n+1) ≡ 6 (mod 9).
  The only answer choice satisfying n+1 ≡ 6 (mod 9) is: (D) 1239.
  </pre>

- [375A_Divisible By Seven](./2.divisors/375A_Divisible%20by%20Seven.cpp)

  <pre>
  # we need (num % 7 == 0)
  
  Rearrange the digits in its decimal representation so that the resulting number will be divisible by 7.
  It doesn't contain any leading zeroes and always contains digits 1, 6, 8, 9
  {"1869", "1968", "1689", "6198", "1698", "1986", "1896"}%7={0,1,2,3,4,5,6}, find it using next_permutation.
  
  #({... Other num mod + (7-other num mod) mod from list }%7=0 + zero at last)%7=0
  
  ex. (5+2+0)%7=0, (4+3+0)%7=0
  </pre>

- [2050C_Uninteresting Number](./1_primes_and_divisors/2_divisors/2050C_Uninteresting%20Number.cpp)
  <pre>
  Given a number n with length(1e5), perform operation any number of times (choose one of its digits, square it, and replace the original digit with the result)
  Is it possible to obtain a number that is (divisible by 9) through these operations?
  -> divisibility test of 9 -> sum of it's digit is divisible by 9
  
  It states that a number is divisible by 9 if and only if the sum of its digits is divisible by 9. Let's see how the sum of the digits will change with the possible transformations. If we square 2, the sum of the digits increases by 2^2−2=2, and if we square 3, the sum of the digits increases by 3^2−3=6
  
  We will count the number of digits 2 in the number and the number of digits 3 in the number. We can choose how many of the available digits 2 and 3 we will transform. Transforming more than 8 twos and more than 8 threes is pointless because remainders modulo 9 their transformation adds to the sum will repeat.
  
  Thus, the final solution looks like this: we calculate the sum of the digits in the number, count the number of digits 2
  and 3. We will iterate over how many digits 2 we change (possibly 0, but no more than 8), and how many digits 3 we change (possibly 0, but also no more than 8). Let's say we changed x digits 2 and y digits 3, then the sum of the digits in the number increased by x∗2+y∗6. If new sum is divisible by 9, the answer is "YES". If such a situation was never reached during the iteration, then the answer is "NO".
  </pre>

---
