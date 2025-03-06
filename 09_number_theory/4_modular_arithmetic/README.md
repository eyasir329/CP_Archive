## Basic Modular Arithmetic

https://youkn0wwho.academy/topic-list/?category=basics&subCategory=modular_arithmetic

#

###### Binary Exponentiation and Modular Arithmetic

### Modular Arithmetic

https://libraryguides.centennialcollege.ca/c.php?g=717548&p=5121821<br>
https://codeforces.com/blog/entry/72527<br>
https://aryansh-s.github.io/assets/pdf/The_Art_of_Modular_Arithmetic.pdf (upto Linear Congruences)

<pre>
you may have noticed that some tasks, typically combinatorial and probability tasks, have this funny habit of asking you to calculate a huge number, then tell you that "because this number can be huge, please output it modulo <b>1e9+7 or 998244353</b>".

Two integers a and b may be deemed “equal“ in this system if they both correspond to the same hour on the clock(mod 12). However, to prevent confusion when a != b in standard arithmetic, we say that a and b are <b>congruent</b> and write this as a ≡ b. For example, because 2021, 17, and −19 all correspond to the same hour 5, we can write 2021 ≡ 17 ≡ −19 ≡ 5

First, we write the notion that two integers a and b correspond to the same hour on this general m-hour clock in modular form as -> a ≡ b (mod m),
pronounced “a is congruent to b modulo m,“ where the (mod m) modular suffix helps us keep track of the modulus m. This relation as a whole is known as a <b>modular congruence</b>.
----
-> 3 and 7 are basically the same if computing modulo 4, since 3 mod 4 = 3 = 7 mod 4. This concept, where numbers with the same remainder are treated as if they are equal is called congruence.

-> If a and b have the same remainder when divided by n, we say that a and b are congruent modulo n, written a ≡ b (mod n), or equivalently, their difference a−b is a multiple of n, written n∣(a−b)

-> number a to be congruent to 0 modulo n, means n∣a, or n divides a evenly without a remainder. When a is divided by n, the remainder is 0.
----
Lastly, the hour an integer a corresponds to on a modulus m clock, equivalently the remainder of the division a ÷ m, can be written in <b>modular remainder form</b> as -> a mod m
(notice the omission of parentheses around the modular suffix) and is sometimes referred to as the <b>modular residue</b> of a (mod m).

-> when dividing a number a with a number n, you would get a quotient q and a remainder r. These numbers would satisfy the identity a = nq + r, with 0 ≤ r < b. then, gcd(a,n) = gcd(q,r)
</pre>

<pre>
- % is often called the "modulo operator", but in some instances we call it the "remainder operator"
- mod  operator to have lower precedence than addition or subtraction, it's not a constant time operation (costly than other)
- The value m after the modulo operator is known as the modulus. 
- The key identities of modular arithmetic are not only intuitive but easy to formalize through conversion from modular form to parametric form and vice versa

- Negative numbers are really powerful and often help simplify the arithmetic
part of modular arithmetic.
    89 ≡ −1 (mod 90) =⇒ 89<sup>2021</sup> ≡ (−1)<sup>2021</sup> ≡ −1 ≡ 89 (mod 90)

First off, some important identities about the modulo operator:
(a mod m) + (b mod m)  mod m = (a + b)  mod m
(a mod m) − (b mod m)  mod m = (a − b)  mod m
(a mod m) ⋅ (b mod m)  mod m = (a ⋅ b)  mod m
a<sup>b</sup> mod m = (a mod m)<sup>b</sup> mod m

- The day of the week corresponding to a certain day is given by its modular residue (mod 7) because there are 7 days in a week.
- Even or odd parity is given by the modular residue (mod 2).
- The units digit of a number is its modular residue (mod 10).
</pre>

###### Properties

<pre>
-> <b>n mod m = n - floor(n/m)*m</b> (This should be always produce an integer between 0 amd m-1 inclusive)
-> a mod m = b mod m => (a-b) mod m = 0
-> x mod m = x if m>x
-> <b>x mod m < x/2 when m <= x</b>
-> a − b = k*m; k ∈ Z (a and b differ by an integer multiple of m)//<b>parametric form</b>//by modular definitions

-> the result is always reduced to its remainder when divided by n. This is what "modulo arithmetic" means
-> The results "wrap around" n, forming a cycle. Operations like addition, multiplication, and subtraction respect this cyclical nature.
</pre>

<img src="https://prod-qna-question-images.s3.amazonaws.com/qna-images/answer/6195f099-697f-489e-94ae-c77f1a063c08/8512de78-d4fd-43ef-9f61-33fcd14fa8c9/2dm5l1.jpg" alt="modular_arithmetic" style="height:300px;">

###### Resolving the Division Anomaly

- Division is not straightforward and involves finding modular inverses, which exist only when the divisor is coprime to n.

- Division does not work as you would expect in congruences (we can’t divide both sides of the congruence)

here is a way to make division work if we’re careful. . .

<pre>
Division in modular arithmetic works under specific conditions:  
If ad ≡ bd (mod m), where a, b, d, m ∈ Z, d ≠ 0, and m > 1, then:  
    a ≡ b (mod m / gcd(m, d))  

Explanation:  
- Direct division isn’t always valid because d might share factors with m.  
- Adjusting the modulus by gcd(m, d) ensures the congruence holds.  

Example:  
6x ≡ 12 (mod 18)  
- Here, d = 6, m = 18, gcd(18, 6) = 6.  
- Divide both sides by 6 and adjust modulus:  
    x ≡ 2 (mod 3)  
</pre>

[Math Competitions Exercise](https://davidaltizio.web.illinois.edu/ModularArithmetic.pdf)

example:

- [2017 AMC 12A Problems/Problem 11](https://artofproblemsolving.com/wiki/index.php/2017_AMC_12A_Problems/Problem_11)

  <pre>
  Claire adds the degree measures of the interior angles of a convex polygon and arrives at a sum of 2017. She then discovers that she forgot to include one angle. What is the degree measure of the forgotten angle?
  
  Sol<sup>n</sup>1 -> We know that the sum of the interior angles of the polygon is a multiple of 180, Note that ceil(2017/180) = 12 and 180 * 12 = 2160, so the angle Claire forgot is 2160-2017 = 143 (mod 180).
  
  Sol<sup>n</sup>2 -> Let x be the measure of the forgotten angle. The degree sum of the measures of the interior angles of an n-gon is 180(n − 2), or 180(n − 2) − x if we forget x. We can solve for x if we note that 180(n − 2) − x ≡ −x (mod 180). 
  Claire’s sum of 2017 ≡ 37 ≡ −143 (mod 180),
        Thus, −𝑥 ≡ 37(mod 180)
        To find To find x, we multiply through by -1 
        (noting that modular arithmetic preserves equivalence): 
        x ≡ -37, Since -37 mod 180 = 143, we have: x ≡ 143 (mod 180)
  so x ≡ 143 (mod 180). In fact, since x < 180 due to the convex condition, x = 143◦.
  </pre>

- [2000 AMC 12 Problems/Problem 18](https://artofproblemsolving.com/wiki/index.php/2000_AMC_12_Problems/Problem_18)
    <pre>
  In year N, the 300th day of the year is a Tuesday. In year N + 1, the 200th day is also a Tuesday. On what day of the week did the 100th day of the year N − 1 occur?
  
  Sol<sup>n</sup>1 ->  Wednesday (if current year not leap year), If leap year then Thursday
  leap year -> approximately every four years, February has 29 days instead of 28
  condition of leap year -> <b>(y%4==0) and [(y%100=0) or (y%400==0)]</b>
    </pre>

- [2014 AMC 8 Problems/Problem 13](https://artofproblemsolving.com/wiki/index.php/2014_AMC_8_Problems/Problem_13)
  <pre>
  If n and m are integers and n<sup>2</sup> + m<sup>2</sup> is even, which of the following is impossible?
  (A) n and m are even (B) n and m are odd (C) n + m is even (D) n + m is odd
  (E) none of these are impossible
  
  -> Since n^2+m^2 is even, either both n^2 and m^2 are even, or they are both odd. Therefore, n and m are either both even or both odd, since <b>the square of an even number is even and the square of an odd number is odd.</b>
  </pre>

- [Units digit of the result]()

    <pre>
  When the sum
    (1 · 2 · 3) + (2 · 3 · 4) + (3 · 4 · 5) + · · · + (2018 · 2019 · 2020)
    is evaluated, what is the units digit4 of the result?
  
  -> The units digit is given by the residue (mod 10). Computing the residues for the first few terms reveals the repeating pattern: 6, 4, 0, 0, 0 (mod 10), with a sum of 6 + 4 + 0 + 0 + 0 ≡ 0 (mod 10). This pattern repeats k times, leaving a remainder of 2018 mod 5 = 3 terms, which are 6, 4, 0 (mod 10), with a sum of 6 + 4 + 0 ≡ 0 (mod 10). Thus, the answer is 0k + 0 ≡ 0 (mod 10). 
    </pre>

- [Sum of all possible values of the units digit of the sum]()
  <pre>Al, Bob, and Carl each have favorite numbers so that the sum of Al and Bob’s favorite numbers has a units digit of 2, the sum of Bob and Carl’s favorite numbers has a units digit of 4, and the sum of Al and Carl’s favorite numbers has a units digit of 0. If their favorite numbers are all positive integers, what is the sum of all possible values of the units digit of the sum of their three favorite numbers?
  
  -> Let their numbers be a, b, c by name. Since the units digit is the residue (mod 10), we are given the following:
  a + b ≡ 2 (mod 10)
  b + c ≡ 4 (mod 10)
  a + c ≡ 0 (mod 10)
  Adding the congruences gives us
  2(a + b + c) ≡ 6 (mod 10)
  We can divide both sides of the congruence by 2 and the modulus by gcd(2, 10) = 2 :
  a + b + c ≡ 3 (mod 5)
  Going back to (mod 10), this means we have
  a + b + c ≡ 3, 8 (mod 10).
  Therefore, our answer is 3 + 8 = 11
  
  -> The modulo 5 solution a+b+c ≡ 3 (mod 5) lifts to modulo 10 because: 10 is a multiple of 5, and Adding 5 repeatedly cycles through two equivalence classes in modulo 10: 3(mod10) and 8(mod10). This is a fundamental property of modular arithmetic.
  </pre>

- [SPOJ_LASTDIG - The last digit]()
  <pre>
  You are given two integer numbers: the base a (0 <= a <= 20) and the index b (0 <= b <= 2,147,483,000), a and b both are not 0. You have to find the last digit of a^b. (without doing any mod)
  </pre>
- [gfg_Find the maximum possible value of a[i] % a[j] over all pairs of i and j]()
  <pre>
  - 2nd maximum is the answer (other is always smaller than 2nd_mx%1st_max)
  
  reverse problem cf_484b
  </pre>

- [toph_Modulo](./4_modular_arithmetic/2_basic_modular_arithmetic/toph_modulo.cpp)
  <pre>
  Given an array A of N integers. Then there will be Q queries. In each query You will be given an integer M. For every i where 1≤i≤N you have to change A[i] to A[i] mod M. After executing all queries you have to print the array A in the order of input.
  
  - be careful to put newline in i==n
  </pre>

- [495B_Modular Equations](./5.modular_arithmetic/modular_arithmetic/495B_Modular%20Equations.cpp)

  <pre>
  # print the number of solutions of the modular equation (a mod x = b). (0<=a,b<=1e9)
  
  # (x>b, a%x <=a)by the rule of modulo
  
  *a = b => infinity (then x can be any integer larger than a)
  *a < b =>  0 (there is no such x for that)
  *a > b =>  (b < x <= a)
    a = 21, b = 5
    a-b = 16 (except a=1,(b==0)1:0)
    num of divisors of a-b(16) that are more than b
  </pre>

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

### Exponentiation

<pre>
Many of the important problems modular arithmetic solves involve finding the remainders of notoriously large exponents that cannot be computed by hand. In many cases, you’ll find that it is enough to find the first few exponents of the base to see how the modular residues cycle. You can then induct the cycle to pin down the desired residue.

ex. What is the units digit of 2<sup>2021</sup>?
-> Our residues cycle as 2, 4, 8, 6(2<sup>4</sup> mod 10), 2, 4, 8, 6, . . . . Because each cycle has length 4 (four residues are contained inside the cycle) 2021 mod 4 = 1 (first resides, which is 2)

- The units digit of a number is the last digit in its decimal representation.
</pre>

- <u>Given two integer x and n, find x^n modulo m</u>

###### Naive ->O(N)

```cpp
//we can just multiply x, n times
int power(int x, int n, int mod) {
    int ans = 1 % mod;
    for (int i = 1; i <= n; i++) {
        ans = 1LL * ans * x % mod;
    }
    return ans;
}
```

###### Circular ->O(mod+period length)

<pre>
- work only mod<=1e7
- If we print out the value of x^0 ... x^n under modulo m, we will see that they are repeating after some point. So we can just find the period of the sequence and then we find the answer. Period is always <=m
</pre>

```cpp
int power(int x, int n, int mod) {
    if (mod == 1)return 0;
    vector<int> a;//upto 1e7
    vector<bool>vis(mod, false);
    a.push_back(1);//x^0
    vis[1] = true;
    int cur = 1, st = 0;
    while (true) {
        cur = 1LL * cur * x % mod;
        if (vis[cur]) {
            st = find(a.begin(), a.end(), cur) - a.begin();
            break;
        }
        vis[cur] = true;
        a.push_back(cur);
    }
    int period = (int)a.size() - st;
    if (n < st)return a[n];
    n -= st;
    return a[st + n % period];
}
```

example:

- [2018 AMC 10A Problems/Problem 19](https://artofproblemsolving.com/wiki/index.php/2018_AMC_10A_Problems/Problem_19)

  <pre>
  A number m is randomly selected from the set {11, 13, 15, 17, 19}, and a number n is randomly selected from {1999, 2000, 2001, . . . , 2018}. What is the probability that m<sup>n</sup> has a units digit of 1?
  
  -> Given:
  - m ∈ {11, 13, 15, 17, 19}
  - n ∈ {1999, 2000, ..., 2018}
  
  Step 1: Analyze the units digits of m:
  - 11: Units digit = 1 (always 1 for m^n).
  - 13: Units digits cycle as 3, 9, 7, 1 (cycle length = 4).
  - 15: Units digit = 5 (never 1 for m^n).
  - 17: Units digits cycle as 7, 9, 3, 1 (cycle length = 4).
  - 19: Units digits cycle as 9, 1 (cycle length = 2).
  
  Step 2: Determine probabilities for each m:
  - m = 11: Always 1 → Probability = 1.
  - m = 13: n mod 4 = 0. 5 values in n, Probability = 5/20 = 1/4.
  - m = 15: Never 1 → Probability = 0.
  - m = 17: n mod 4 = 0. 5 values in n, Probability = 5/20 = 1/4.
  - m = 19: n mod 2 = 0 (even n). 10 values in n, Probability = 10/20 = 1/2.
  
  Step 3: Calculate overall probability:
  Each m is equally likely (1/5):
  - Total probability = (1/5)(1 + 1/4 + 0 + 1/4 + 1/2)
                      = (1/5)(4/4 + 1/4 + 0/4 + 1/4 + 2/4)
                      = (1/5)(8/4) = 2/5.
  
  Final Answer:
  The probability that m^n has a units digit of 1 is 2/5.
  -----
  - <b>When you multiply two numbers, the units digit of the result is determined only by the units digits of the numbers being multiplied.</b>
  - Each time we multiply, only the units digit of the intermediate result matters. The higher digits do not affect the units digit.
  
  - By focusing on the repeating patterns in the units digits of powers (like cycles of 3,9,7,1 for 13), we can predict the units digit of m<sup>n</sup> without performing full multiplication.
  </pre>

#

### Binary Exponentiation

https://cp-algorithms.com/algebra/binary-exp.html

<pre>
Binary exponentiation (also known as exponentiation by squaring) is a trick which allows to calculate a<sup>n</sup> using only O(logn) multiplications (instead of O(n) multiplications required by the naive approach).

-> Although the complexity of both approaches is identical, iterative approach is faster than recursive 
</pre>

###### Recursive ->O(logn)

<pre>
- We can use divide and conquer to solve this problem.
  {
     n = 0 -> x^n = 1
     n is even -> x^n/2*x^n/2 -> (x<sup>2</sup>)<sup>n/2</sup>
     n is odd -> x^floor(n/2)*x^floor(n/2)*x -> x*(x<sup>2</sup>)<sup>n-1/2</sup> 
  }
</pre>

```cpp
int power(int x, long long n, int mod) {
    if (n == 0) return 1 % mod;//base case
    int cur = power(x, n / 2, mod);//to compute (x^(n/2)) % mod
    if (n % 2 == 0) {
        return 1LL * cur * cur % mod;
    } else {
        return 1LL * cur * cur % mod * x % mod;
    }
}
```

###### Iterative v1 ->O(logn)

<pre>
- any integer n can be written as sum of power of two
-> x<sup>13</sup> = x<sup>2<sup>3</sup>+2<sup>2</sup>+2<sup>0</sup></sup> = x<sup>2<sup>3</sup></sup>*x<sup>2<sup>2</sup></sup>*x<sup>2<sup>0</sup></sup> 
</pre>

```cpp
int power(int x, long long n, int mod) {
    int ans = 1 % mod, cur = x % mod;
    for (int i = 0; (1LL << i) <= n; i++) {
        if (n & (1LL << i)) {
            ans = 1LL * ans * cur % mod;
        }
        cur = 1LL * cur * cur % mod;
    }
    return ans;
}
```

###### Iterative v2 ->O(logn)\*\*\*

<pre>
- same as v1 but in different way. Basically we can get the binary representation of n from LSB to MSB by dividing n by 2 each time. If the current bit is 1, then we multiply the answer by x<sup>2<sup>i</sup></sup>
</pre>

```cpp
int power(int x, long long n, int mod) {
    int ans = 1 % mod;
    while (n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % mod;
        }
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ans;
}
```

example:

- [CSES-1095_Exponentiation](./4_binary_exponentiation/cses1095_Exponentiation.cpp)

  <pre>
  Your task is to efficiently calculate values a^b modulo 10^9+7.
  Note that in this task we assume that 0^0=1.
  </pre>

- [UVA-1230_MODEX](./4_binary_exponentiation/UVA1230_MODEX.cpp)

  <pre>
  Given integers x, y and n, compute x^y mod n. In this question, you are tasked to program an efficient way to execute this calculation.
  </pre>

- [UVA-374_Big Mod](./4_binary_exponentiation/UVA374_Big%20Mod.cpp)
  <pre>
  Calculate R := B^P mod M
  for large values of B, P , and M using an efficient algorithm.
  
  The input will contain several test cases, but not given the value of t, M is an integer in the range 1 to 46340 inclusive (so it also support circular way to finding exponentiation O(mod+period length), but not support naive method O(n) because P-> 0 to 2147483647 inclusive)
  </pre>

- [913A_Modular Exponentiation](https://vjudge.net/problem/CodeForces-913A)

    <pre>
    The following problem is well-known: given integers n and m, calculate 2^n mod m
    
    You are asked to solve the "reverse" problem. Given integers n and m, calculate m mod 2^n (1<=n,m<=1e8)
    
    -> python can support large nunber, or java BigInteger
    -> n >= 31 ? m : m % (1 << n))
    </pre>

- [UVA_11029 Leading and Trailing](./4_binary_exponentiation/UVA11029_Leading%20and%20Trailing.cpp)

  <pre>
  C function pow(125456, 455) can be represented in double data
  type format, but you won’t get all the digits of the result. However we can get at least some satisfaction, if we could know few of the leading and trailing digits. This is the requirement of this problem.
  
  For each line of input there will be one line of output. It will be of the format LLL . . . T T T , where LLL represents the first three digits of nk and T T T represents the last three digits of nk. You are assured that nk will contain at least 6 digits.
  
  n and k. n will fit in 32 bit integer and k will be less than 10000001
  </pre>

  <pre>
  # for finding first three digit
  Logarithmic Identity:
  
  Formula Used: 
  log10(n^k) = k × log10(n)
  
  The idea here is to use the logarithmic identity to transform the problem of finding the first few digits of n^k into a problem of dealing with logarithms.
  In this case:
  - log10(base) computes the logarithm of base (which is n in the function).
  - Multiplying this by exp (which is k in the function) gives the logarithm of n^k, i.e., logValue = exp * log10(base).
  
  Extracting the Fractional Part:
  
  fractionalPart = logValue - floor(logValue);
  
  Logarithms produce a number in the form of an integer part and a fractional part. For example, if log10(1000) = 3.0, the integer part is 3 and the fractional part is 0.
  To get the fractional part (the part after the decimal point), the floor(logValue) function is used, which removes the integer portion.
  For instance, if logValue = 5.2356, then fractionalPart = 0.2356.
  
  Calculating the First Three Digits:
  
  pow(10, fractionalPart) gives us the number 10^fractionalPart, which is a number between 1 and 10. This is a key step for extracting the significant digits.
  For example, if fractionalPart = 0.2356, then pow(10, fractionalPart) will give something like 1.78 (the first part of the number, representing the significant digits).
  Multiplying this result by 100 scales it up to get the first three digits. For example, if pow(10, fractionalPart) = 1.78, then 1.78 * 100 = 178.
  The result is then cast to long long to obtain the integer value of the first three digits.
  
  Returning the Result:
  
  The function returns the first three digits as a long long integer.
  </pre>

  <b>Precision Handling</b> (more precision)

  <b>Logarithmic Method (calculateFirstThreeDigits):</b>

  - Relies heavily on <i>double</i> precision to handle the fractional part and <i>pow</i> function.
  - Floating-point operations, especially with large numbers, can lead to small inaccuracies due to precision limits.
  - Example issue:
    If log<sub>10</sub>(n<sup>k</sup>) = 12.999999, <i>floor(logValue)</i> might misinterpret the result, leading to incorrect digits.

  <b>Combined Logarithmic with Modular Arithmetic:</b>

  - Adjusts fractional part alignment more explicitly:
    <code>
    lg -= floor(lg) - 2;
    </code>
    This ensures a more stable computation for the leading digits by shifting the fractional part to focus on significant digits.
  - Adds a small epsilon (<i>1e-9</i>) during extraction to stabilize floating-point operations.

---

### Mulmod and Binary Exponentiation like Problems

https://cs.stackexchange.com/questions/77016/modular-multiplication

- Why use mulmod ?
<pre>
- When multiplying two large numbers where (𝑎⋅𝑏) exceeds the range of long long.
- To ensure correctness in modular arithmetic computations in languages or systems with limited integer sizes.
</pre>

- <u>Given three integers x,y and m, find x\*y modulo m. (1<=x,y<=1e18, mod<=1e18+7)</u>
<pre>
a * b % mod is overflowing because of a,b,mod are very large.
x * y = x+x+...x (upto y times)
</pre>

```cpp
long long mulmod(long long x, long long y, long long mod) {//O(logy)
    long long ans = 0;
    while (y > 0) {
        if (y & 1) {
            ans = (ans + x) % mod;//do addition, instead of multiplication
        }
        x = (x + x) % mod;
        y >>= 1;
    }
    return ans;
}
```

<pre>
- we can also use 128 bit integer for this purpose
</pre>

```cpp
long long mulmod(long long x, long long y, long long mod) {
    return (long long)((__int128)x * y % mod);
}
```

<pre>
x mod 2<sup>k</sup> = x&(2<sup>k</sup>-1) -> equal to the last k bits of x 
</pre>

- <u>Given two integers x,n, find x<sup>n</sup> modulo 2<sup>64</sup></u>
<pre>
unsigned integers are represented modulo 2^k, where k is the number of bits of the data type. unsigned int are represented modulo 2^32
</pre>

```cpp
//benefit of data type ranges
#define ull unsigned long long

ull power(ull x, ull n) {
    ull ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans *= x;//ull always do mod by 2^64
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}
```

example:

- [codechef_Chef and Riffles](./1_basic_modular_operation/codechef_JAN221B_RIFFLES_Chef%20and%20Riffles.cpp)

  <pre>
  Let f be a permutation of length N, where N is even. The riffle of f is defined to be the permutation g=(f(1),f(3),…,f(N−1),f(2),f(4),…,f(N))
  
  You are given two integers N and K. Output the resultant permutation when you riffle the identity permutation of length N, K times.
  1≤T≤100, 1≤N≤3⋅1e5, 1≤K≤1e9, N is even
  The sum of N across test cases does not exceed 3⋅1e5
  </pre>

- [spoj_ZSUM - Just Add It](./4_mulmod_and_binExpLike/spoj_ZSUM_Just%20Add%20It.cpp)

  <pre>
  For two given integers n and k find (Zn + Z(n-1) - 2Z(n-2)) mod 10000007, where Zn = Sn + Pn and Sn = 1^k + 2^k + 3^k + … + n^k and Pn = 1^1 + 2^2 + 3^3 + … + n^n. (1 < n < 200000000, 0 < k < 1000000 )
  </pre>

- [spoj_LOCKER - Magic of the locker](./4_mulmod_and_binExpLike/spoj_LOCKER_Magic%20of%20the%20locker.cpp)

  <pre>
  you are given a number n , and break it into parts such that product of all parts is maximum.
  </pre>

---

###### Fermat's Little Theorem and Modular Inverse

### Fermat's Little Theorem

https://en.wikipedia.org/wiki/Fermat's_little_theorem

<pre>
In number theory, Fermat's little theorem states that if p is a prime number, then <b>for any integer a, the number a<sup>p</sup> − a is an integer multiple of p</b>. In the notation of modular arithmetic, this is expressed as a^p ≡ a (mod p)
For example, if a = 2 and p = 7, then 2^7 = 128, and 128 − 2 = 126 = 7 × 18 is an integer multiple of 7. 

- Let p be a prime which does not divide the integer a(a is coprime to p), then <b>a<sup>p-1</sup> ≡ 1 (mod p)</b>.
For example, if a = 2 and p = 7, then 2^6 = 64, and 64 − 1 = 63 = 7 × 9 is a multiple of 7. 

Fermat's(Pierre de Fermat) little theorem says that as long as the modulus m is a prime number (1e9+7 is prime, and so is 998 244 353, then a<sup>m</sup> mod m = a mod m. Working backwards, a<sup>m−1</sup> mod m = 1 = a⋅a<sup>m−2</sup>  mod m

Note that this only works for a mod m≠0, because there is no number x such that 0⋅x  mod m=1. In other words, you still can't divide by 0.

Fermat’s theorem states that, x<sup>m−1</sup> mod m = 1, when m is prime and x and m are coprime. This also yields x<sup>k</sup> mod m = x<sup>k mod (m−1)</sup> mod m.
</pre>

- [<u>Proof of Fermat's Little Theorem</u>](https://t5k.org/notes/proofs/FermatsLittleTheorem.html)

<pre>
x<sup>n</sup> ≡ x<sup>n mod (p-1)</sup> (mod p), if p is prime 
- because x^0, x^1, x^2 ... cycles after p-1 terms

More generally, Euler’s theorem states that, x<sup>ϕ(m)</sup> mod m = 1, when x and m are coprime. Fermat’s theorem follows from Euler’s theorem, because if m is a prime, then ϕ(m) = m − 1.
</pre>

- [<u>Fermat's theorem (more)</u>](https://en.wikipedia.org/wiki/Fermat%27s_theorem)
<pre>
- Fermat's Last Theorem, about integer solutions to a^n + b^n = c^n
- <b>Fermat's little theorem, a property of prime numbers</b>
- Fermat's theorem on sums of two squares, about <b>primes expressible</b> as a sum of squares
- Fermat's theorem (stationary points), about local maxima and minima of differentiable functions
- Fermat's principle, about the path taken by a ray of light
- Fermat polygonal number theorem, about <b>expressing integers as a sum of polygonal numbers</b>
- Fermat's right triangle theorem, about squares not being expressible as the difference of two fourth powers
</pre>

example:

- [CSES-1712_Exponentiation II](./4_modular_arithmetic/3_fermats_little_theorem_and_modular_inverse/cses1712_Exponentiation2.cpp)

  <pre>
  we have to find a<sup>b<sup>c</sup></sup> modulo 1e9+7
  - not working in normal way, we have to use euler's totient theorem
  
  - To find the multiplicative order of a modulo m, first find φ(m), i.e. Euler's totient of m. Then brute force over the divisors of the totient; the multiplicative order must be one of the divisors.
  </pre>

#

### Euler's Totient Theorem

<pre>
- Euler's theorem is a generalization of Fermat's little theorem

For m ∈ Z>1, Euler’s totient function φ(m) counts the number of positive integers not exceeding m relatively prime to m. It turns out this is a very useful function for us in modular arithmetic.

<b>Euler’s totient function ϕ(n) gives the number of coprime numbers to n between 1 and n.</b>

- φ(12) -> The prime factorization of 12 is 2^2 · 3, so φ(12) = 12 · 1/2 · 2/3 = 4. However, φ(12) also counts thenumber of positive integers not exceeding 12 relatively prime to 12. There are also four of these,1, 5, 7, and 11, as expected. <i>Because 1, 5, 7 and 11 are coprime to 12.</i>

- What is φ(p) for prime p? -> All positive integers less than p are relatively prime to p. Therefore, φ(p) = p − 1 .

- For m ∈ Z>1, prove that a<sup>φ(m)</sup> ≡ 1 (mod m) for all integers a such that gcd(a, m) = 1. This is known as Euler’s totient theorem.

- For m, b ∈ Z>1, show that a<sup>b</sup> ≡ a<sup>b mod φ(m)</sup> (mod m) for all integers a such that (a, m) = 1.
</pre>

```cpp
int eulerTotient(int m) {
    int ans = m;
    for (int p = 2; p * p <= m; ++p) {
        if (m % p == 0) {
            while (m % p == 0) {
                m /= p;
            }
            ans -= ans / p;
        }
    }
    if (m > 1) {
        ans -= ans / m;
    }
    return ans;
}
```

<img src="https://media.geeksforgeeks.org/wp-content/uploads/20240424121512/Euler's-Product-Formula.webp" alt="Euler's Product Formula" width="400">

example:

- <u>Find the Last Two Digits of 7<sup>81</sup> - 3<sup>81</sup></u>
  <pre>
  Step 1: What are the last two digits?
  The last two digits of a number are the remainder when the number is divided by 100.
  We need to compute:
      7^81 - 3^81 (mod 100)
  
  Step 2: Apply Euler's Totient Theorem
  Euler's Totient Theorem states:
      a^φ(n) ≡ 1 (mod n), if gcd(a, n) = 1.
  Here:
      n = 100
      φ(100) = 40 (calculated as φ(100) = 100 × (1 - 1/2) × (1 - 1/5) = 40).
  
  Since both 7 and 3 are coprime to 100:
      7^40 ≡ 1 (mod 100)
      3^40 ≡ 1 (mod 100)
  
  Step 3: Reduce the exponents modulo φ(100)
  Since 81 mod 40 = 1:
      7^81 ≡ 7^1 (mod 100)
      3^81 ≡ 3^1 (mod 100)
  
  Step 4: Compute the difference
  Substitute the simplified results:
      7^81 - 3^81 ≡ 7 - 3 ≡ 4 (mod 100)
  
  Final Answer:
  The last two digits of 7^81 - 3^81 are 04.
  </pre>

- <u>What is the remainder when 69<sup>354</sup> is divided by 89?</u>
  <pre>
  89 is prime, so φ(89) = 88. Then,
  69^354 ≡ 69^354 mod 88 ≡ 69^2 ≡ (−20)^2 ≡ 400 ≡ 44 (mod 89).
  </pre>

- [2017 AMC 10B Problems/Problem 14](https://artofproblemsolving.com/wiki/index.php/2017_AMC_10B_Problems/Problem_14)

  <pre>
  An integer N is selected at random in the range 1 ≤ N ≤ 2020. What is the probability that the remainder when N<sup>16</sup> is divided by 5 is 1? 
  
  -> Step 1: Restate the Problem
  We want to determine the probability that N^16 ≡ 1 (mod 5) for integers N in the range 1 ≤ N ≤ 2020.
  
  Step 2: Apply Fermat’s Little Theorem
  Fermat’s Little Theorem states:
      N^(p-1) ≡ 1 (mod p),
  where p is a prime number and N ≢ 0 (mod p).
  
  Here, p = 5, so for N ≢ 0 (mod 5):
      N^4 ≡ 1 (mod 5).
  
  Step 3: Extend the Result to N^16
  Using the property of exponents:
      N^16 = (N^4)^4.
  Since N^4 ≡ 1 (mod 5), we have:
      N^16 ≡ 1^4 ≡ 1 (mod 5).
  
  Thus, for all N ≢ 0 (mod 5), N^16 ≡ 1 (mod 5).
  
  Step 4: Count N ≢ 0 (mod 5)
  Among the integers 1 ≤ N ≤ 2020, exactly 1/5 of them are divisible by 5.
  This is because the sequence of multiples of 5 is 5, 10, 15, ..., 2020, and there are:
      2020 ÷ 5 = 404
  multiples of 5.
  
  Thus, the remaining 2020 - 404 = 1616 values of N satisfy N ≢ 0 (mod 5),
  for which N^16 ≡ 1 (mod 5).
  
  Step 5: Compute the Probability
  The probability that N^16 ≡ 1 (mod 5) is the fraction of N values
  for which N ≢ 0 (mod 5):
      Probability = (Count of N ≢ 0 (mod 5)) / (Total Count of N)
                = 1616 / 2020
                = 1 - (404 / 2020)
                = 1 - 1/5
                = 4/5.
  
  Final Answer: The probability is: 4/5
  </pre>

- <u>What are the last two digits in the decimal representation of 2011<sup>2012<sup>2013</sup></sup>?</u>

  <pre>
  1. Simplify Base Modulo 100:
    2011 ≡ 11 (mod 100), so the problem becomes 11<sup>2012<sup>2013</sup></sup> mod 100.
  
  2. Apply Euler's Totient Theorem:
    φ(100) = 40, so 11<sup>40</sup> ≡ 1 (mod 100). Reduce the exponent 2012<sup>2013</sup> mod 40.
  
  3. Simplify Exponent Modulo 40:
    2012 ≡ 12 (mod 40), and 12<sup>k</sup> mod 40 cycles with length 4. 
    Since 2013 ≡ 1 (mod 4), 2012<sup>2013</sup> ≡ 12 (mod 40).
  
  4. Compute 11<sup>12</sup> mod 100:
    - 11<sup>2</sup> ≡ 21 (mod 100),
    - 11<sup>4</sup> ≡ 41 (mod 100),
    - 11<sup>8</sup> ≡ 81 (mod 100),
    - 11<sup>12</sup> ≡ 81 * 41 ≡ 21 (mod 100).
  
  Final Answer: 21.
  </pre>

---

### Modular Multiplicative Inverse

https://cp-algorithms.com/algebra/module-inverse.html<br>
https://forthright48.com/modular-multiplicative-inverse/

<pre>
First we have to determine whether Modular Inverse even exists for given A and M before we jump to finding the solution.
- <b>Modular Inverse of A with respect to M, that is, X=A<sup>−1</sup>(mod M) exists, if and only if A and M are coprime.</b>

- Division and fractions(more complicated) are different in modular arithmetic than other operator. It's requires a concept called "modular multiplicative inverse". 
- The modular multiplicative inverse of a number a is the number a<sup>−1</sup> such that a⋅a<sup>−1</sup> mod m = 1.

Bruteforcing all numbers to a prime number close to a billion will usually cause you to exceed the time limit. There are two faster ways to calculate the inverse: the extended GCD algorithm, and Fermat's little theorem. Though the extended GCD algorithm is more versatile and sometimes slightly faster, the Fermat's little theorem method is more popular, 

a.a<sup>m−1</sup> mod m = 1 = a⋅a<sup>m−2</sup>  mod m, therefore the number we need is a<sup>-1</sup> = a<sup>m−2</sup>  mod m (m!=0)

This also extends the  mod  operator to rational numbers (i.e. fractions), as long as the denominator is coprime to m. (Thus the reason for choosing a fairly large prime; that way puzzle writers can avoid denominators with m as a factor).

If a and m aren't coprime, there is no multiplicative inverse of a modulo m, i.e., there is no integer x where a⋅x  mod m=1. This is because all a⋅x  mod m is divisible by gcd(a,m)≠1.

- Z/pZ is just a fancy term meaning the set of integers from 0 to p−1 treated as residues modulo p.
</pre>

<pre>
# Something to know

- divisions through modular multiplicative inverse would be slower than the other operations (O(logm) instead of O(1)), so you may want to cache/memoize the inverses you use frequently in your program.
- comparisons are generally meaningless.
- exponentiation (when evaluating x<sup>n</sup> mod m, you can't store n as n mod m. If n turns out to be really huge, you need to calculate it modulo φ(m) instead, where φ stands for Euler's totient function. If m is prime, φ(m) = m−1. 

Do be careful about the special case 0<sup>0</sup>, which should typically be defined as 1, while 0<sup>φ(m)</sup> would still be 0.

- A modular multiplicative inverse a<sup>−1</sup> mod m is always unique within the range 0≤a<sup>−1</sup> mod m <=m if it exists (and it exists as long as gcd(a,m)=1, a and m are coprime)
</pre>

Properties:

###### 1. **Existence**

- Not all numbers have a modular multiplicative inverse.
- The modular inverse of `a mod m` exists **if and only if** `a` and `m` are **coprime**, i.e., `gcd(a, m) = 1`.
- If `gcd(a, m) ≠ 1`, `a` has no inverse modulo `m`.

###### 2. **Uniqueness**

- If `a` has an inverse modulo `m`, it is **unique modulo `m`**.
- There is only one `x` in the range `0 ≤ x < m`
  such that: a \* x ≡ 1 (mod m)
- if a has a modular multiplicative inverse modulo m, then all a\*i mod m are distinct for i [1,m]

###### 3. **Multiplicative Property**

- If `a` and `b` both have inverses modulo `m`,
  then: (a \* b)<sup>-1</sup> ≡ a<sup>-1</sup> \* b<sup>-1</sup> (mod m)

###### 4. **Inverse of 1**

- The modular inverse of `1` is always `1`:
  1 \* 1 ≡ 1 (mod m)

###### 5. **Inverse of -a**

- The modular inverse of `-a` is `-a<sup>-1</sup>` modulo `m`:
  (-a) \* (-a<sup>-1</sup>) ≡ 1 (mod m)

###### 6. **Relation with Modular Exponentiation**

- For prime `m`, the modular inverse of `a` can be computed using **Fermat's Little Theorem**:
  a<sup>-1</sup> ≡ a<sup>(m-2)</sup> (mod m)

<pre>
Naive Method
- A number a has a modular multiplicative inverse modulo m if there exists a number b such that a*b ≡ 1 (mod m) -> xx<sup>−1</sup> mod m = 1.
- If a has a modular multiplicative inverse modulo m, then we can write a<sup>-1</sup> for the modular multiplicative inverse of a modulo m.

<b>a modular inverse does not always exist, x<sup>−1</sup> mod m can be calculated
exactly when x and m are coprime.</b>
</pre>

```cpp
//naive O(mod)
int inverse(int a, int m) {
    for (int i = 1; i < m; i++) {
        if (1LL * a * i % m == 1) {
            return i;
        }
    }
    return -1;//inverse doesn't exist
}
```

<pre>
If a modular inverse exists, it can be calculated using the formula 
x<sup>−1</sup> = x<sup>ϕ(m)−1</sup>. If m is prime, the formula becomes x<sup>−1</sup> = x<sup>m−2</sup>.

Optimize Approach
  -> a<sup>p-1</sup> ≡ 1 (mod p). (from little fermat's theorem)
  -> a<sup>p-2</sup> ≡ a<sup>-1</sup> (mod p)
</pre>

```cpp
//faster O(logm)
int power(int x, int n, int mod) {
    int ans = 1 % mod;
    while (n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % mod;
        }
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ans;
}

// mod must be prime
int inverse(int a, int mod) {
    return power(a, mod - 2, mod);
}
```

- <u>Using Euler’s Theorem</u>

<pre>
It is possible to use Euler’s Theorem to find the modular inverse. We know that:

      A<sup>ϕ(M)</sup> ≡ 1(mod M)
      A<sup>ϕ(M)−1</sup> ≡ A<sup>−1</sup>(mod M)

This process works for any M as long as it’s coprime to A, but it is rarely used since we have to calculate Euler Phi value of M which requires more processing.
</pre>

- <u>Using Extended Euclidean Algorithm</u>
<pre>
We are trying to solve the congruence, AX ≡ 1(mod M). We can convert this to an equation.
      AX ≡ 1(mod M)
      AX + MY = 1
Here, both X and Y are unknown. This is a linear equation and we want to find integer solution for it. Which means, this is a Linear Diophantine Equation.
</pre>

```cpp
int ext_gcd(int A, int B, int *X, int *Y) {
    int x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2;
    *Y = y2;
    return r2;
}

int modInv(int a, int m) {
    int x, y;
    ext_gcd(a, m, &x, &y);

    // Process x so that it is between 0 and m-1
    x %= m;
    if (x < 0) x += m;
    return x;
}
```

example:

- [hackerearth_modular inverse](https://www.hackerearth.com/problem/algorithm/modulo-inverse-problem/)
  <pre>
  You have been a number A. You need to output the inverse of number A modulo 1e9+7
  </pre>

- [eolymp9606_modular division](./4_modular_arithmetic/3_fermats_little_theorem_and_modular_inverse/eolymp9606_modular_division.cpp)
  <pre>
  Three positive integers a,b, and n are given. Compute the value of a / b mod n. In other words, find a value x such that b⋅x = a mod n.
  
  n<=2e9, 1 < a,b < n
  -> (a*inverse(b))%n
  </pre>

#
