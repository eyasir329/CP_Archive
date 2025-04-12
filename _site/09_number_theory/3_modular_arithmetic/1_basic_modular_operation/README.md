### Modular Arithmetic

https://libraryguides.centennialcollege.ca/c.php?g=717548&p=5121821<br>
https://codeforces.com/blog/entry/72527<br>
https://aryansh-s.github.io/assets/pdf/The_Art_of_Modular_Arithmetic.pdf (upto Linear Congruences)

### Basics

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
-> a=b, b=c => a=c
-> a≡b (mod m) <=> m divides (a-b) //formal defination
-> a≡b (mod m) => a%m = b%m

-> 7+0 (mod 4) -> 7 means (3,7,11,15...), 0 means (0,4,8,12...) 

 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8
  0  1  2  3 0 1 2 3 0 1 2 3 0 -> (-x+m)%m

in cpp -x%m = -y (gives also a negative number) so (-x+m)%m is always same

- Negative numbers are really powerful and often help simplify the arithmetic
part of modular arithmetic.
    89 ≡ −1 (mod 90) =⇒ 89<sup>2021</sup> ≡ (−1)<sup>2021</sup> ≡ −1 ≡ 89 (mod 90)
</pre>

```cpp
//function call and mod operation is costly
//it does not call untill we know x>=0
int safeMod(int x,int m){
  int y = x%m;
  if(y<0)y+=m;
  return y;
}
```

<pre>
- % is often called the "modulo operator", but in some instances we call it the "remainder operator"
- mod  operator to have lower precedence than addition or subtraction, it's not a constant time operation (costly than other)
- The value m after the modulo operator is known as the modulus. 
- The key identities of modular arithmetic are not only intuitive but easy to formalize through conversion from modular form to parametric form and vice versa
</pre>

<pre>
-> in MODULAR arithmetic it is not gurranted that previous arithmatic rule is work or not.

First off, some important identities about the modulo operator:
# (a mod m) + (b mod m)  mod m = (a + b)  mod m

# (a mod m) − (b mod m)  mod m = (a − b)  mod m//it has risk->check negative or not if (-ve) then +m

# (a mod m) ⋅ (b mod m)  mod m = (a ⋅ b)  mod m//it may have overflow-> be careful -> <b>use 1LL or long long int</b>

# we can not divide in modular arithmetic in general way
-> it works when remainder 1 like... 3 ≡ 33(mod 10)->1 ≡ 11(mod 10)//when divide by 3, we can not have 3 in 10
-> a ≡ b(mod m) -> we can do a/c≡b/c (mod m) when m and c not have common prime divisors -> means m,c are co-prime // and not allow to divide when a/c or b/c have fraction
->Special Divide (has effect-because we also have to divide m by that) 
-> a/c≡b/c (mod m/c) => <b>a/c≡b/c (mod m/gcd(m,c))</b>
8 ≡ 18(mod 10) => 4 ≡ 9(mod 5)

# <b>Why divide(/) is important in modular arithmetic?</b>
# a/b = x => a = b*x
3/7 = 9(mod 10) (exists/meaningful)
because -> 3 = 7*x (mod 10) => 3 = 63(mod 10) = 3 (mod 10)
3/7=? (mod 10) x can be 3,13,23,33,43,53,63... all is represented by 3 (we can try all) where 63 is valid

-> 31/2 = 36 (mod 41) -> a/b = x (mod m)
-> 2*36 = 31 (mod 41) -> b*x = a (mod m)

# a<sup>b</sup> mod m = (a mod m)<sup>b</sup> mod m
</pre>

```cpp
//1+2+3+4+5+6+7+8
int mod = 41;
int n = 8;
int sum = n*(n+1);//we have to also divide by 2
sum%=mod;
while(sum%2!=0){//untill we found a representation of sum that is divisible by 2 >>it is not gurranted when this loop stop - can be infinite loop
  sum+=mod;
}
sum/=2;
cout<<sum%mod<<endl;
//better solution is modular inverse
```

<pre>
->modular inverse =>x*x<sup>-1</sup> = 1 =>  a*b = 1 (mod m)(where b is a modular inverse of a and b is always less than m) 
-> a/b = x (mod m) => b*x = a (mod m)
->  7*y = 1 (mod 10)
    7*3 = 1 (mod 10) -> 3 is equivalent to 1/7
then a*3 = 3*3 = 9
-> all the time inverse(a) not possible only possible when gcd(a,m)=1//co-prime a and m

1 2 3 4 5 6 7 8 9 (mod 10)
only inverse has -> 1->1,3->7,7->3,9->9

mod value can have -> (1e9+7 or 998244353->FFT) for that (1 to m-1) everyone is co-prime for that number so always have inverse

mod = 81;//odd
inverse(2) = ((mod+1)/2)%mod
</pre>

```cpp
//modular inverse - naive O(mod)
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
# Equation solve
-> 3x + 5 = 7 (mod 10) => 3x = 7-5 = 2
   7*3x = 2*7 (7*3 = 1 (mod 10))
   x = 14 (mod 10) = 4 (mod 10)

a*b = 0 (mod 10 composite) => maybe (a!=0 and b!=0) like 2*5 = 10 = 0
if mod = prime then either (a = 0, b!=0) or (b = 0, a!=0)

-> if mod(composite) = it's a number theory problem = more complex
-> if mod(prime) = it's not a number theory problem
</pre>

<pre>
- The day of the week corresponding to a certain day is given by its modular residue (mod 7) because there are 7 days in a week.
- Even or odd parity is given by the modular residue (mod 2).
- The units digit of a number is its modular residue (mod 10).
</pre>

### Properties

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

### Resolving the Division Anomaly

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

### Final Thoughts

<pre>
- fixed mod -> use const (some optimisation in cpp)
- make sure after each operation, the result is between 0 and m-1
- keep eyes in overflow (multiplication -> always use long long).
- do not work in division in general ways(division -> modular inverse).
- bitwise operation do not work with modular arithmetic.
- subtraction -> use if-else
</pre>

<pre>
  (x + y) mod m = (x mod m + y mod m) mod m
  (a - b) mod m = (a mod m - b mod m + m) mod m
  (x · y) mod m = (x mod m · y mod m) mod m
  x^n mod m = (x mod m)^(n mod m-1)
</pre>

[Math Competitions Exercise](https://davidaltizio.web.illinois.edu/ModularArithmetic.pdf)

example:

- Find a closed form for the remainder of a ÷ m, where a, m ∈ Z+

  <pre>
  Because finding the remainder directly does not seem like an easy task, we first look for the quotient q. Because the quotient is the greatest number of times m goes into a, it is the integer part of a/m . But how do we truncate the fractional part? Apply the floor function! 
  
  q =⌊a/m⌋
  Our remainder becomes a − mq = <b>a − m⌊a/m⌋</b> <-- a % m
  </pre>

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
