# Number Theory

## Primes

- [spoj_VECTAR8 - Primal Fear](./1.primes/spoj_VECTAR8_Primal%20Fear.cpp)

<pre>
They are afraid of the prime numbers (without the digit zero), that remain prime no matter how many of the leading digits are omitted.

For example, they are afraid of 4632647 because it doesn't have the digit 0 and each of its truncations (632647, 32647, 2647, 647, 47, and 7) are primes. 

#given a number of N, find out the number of primes not greater that N, that changu and mangu are afraid of.

T ≤ 10^5, 1 ≤ N < 10^6

if(num has digit 0)return false;
if(it's truncations not prime)return false;
otherwise true;
</pre>

- [spoj_HS08PAUL_A conjecture of Paul Erdős](./1.primes/spoj_HS08PAUL_A%20conjecture%20of%20Paul%20Erdős.cpp)

<pre>
#find the number of (positive) primes not larger than n which are of the form x2+y4 (where x and y are integers).
</pre>

## Divisors

- [375A_Divisible By Seven](./2.divisors/375A_Divisible%20by%20Seven.cpp)
<pre>

# we need (num % 7 == 0)

Rearrange the digits in its decimal representation so that the resulting number will be divisible by 7.
It doesn't contain any leading zeroes and always contains digits 1, 6, 8, 9
{"1869", "1968", "1689", "6198", "1698", "1986", "1896"}%7={0,1,2,3,4,5,6}, find it using next_permutation.

#({... Other num mod + (7-other num mod) mod from list }%7=0 + zero at last)%7=0

ex. (5+2+0)%7=0, (4+3+0)%7=0

</pre>

## Factorization

- [576A_Vasya and Petya's Game](./2.divisors/576A_Vasya%20and%20Petya's%20Game.cpp)

<pre>
# thought of number x between 1 and n, another tries to guess the number
# another can ask, is the unknown number divisible by number y?
# find the minimum number of questions he should ask to make a guaranteed guess number.

n factorize = (2,2,2,3,5...y)
if(n is divisible y) y*y until find n.. then next y

</pre>

## Euclidean Algorithms

- [343A_Rational Resistance](./4.euclidean_algorithms/343A_Rational%20Resistance.cpp)
<pre>

# needs to assemble an element with a resistance(1 ohm) equal to the fraction of a/b.

# determine the smallest possible number of resistors needs to make such an element.

has lots of identical resistors with unit (1 ohm) resistance. our need resistance value can be constructed with these.

e = x/y (resistance of a element, can be fraction because of parallelism)
series: (x/y)+1 => (x+y)/y >1; (1<=a,b<=1e18)
parallel: 1/((1/(x/y))+1/1) => x/(x+y) <1; (1<=a,b<=1e18)

# If a fraction a/b can be obtained with k resistors, then it is simple to calculate that we can obtain fractions (a+b)/b and a/(a+b) with k + 1 resistors.

So adding one resistor means performing one operation backwards in Euclidean algorithm. That means that the answer is equal to the number of steps in standard Euclidean algorithm.

a/b = 1 + f(x/y)
a > b => ((x+y)/y ~ a/b) =>x/y = a-b/a
---a/b = 1 + f(b,a-b)
a < b => (x/(x+y) ~ a/b) =>x/y = a/b-a
---a/b = 1 + f(a,b-a)

TLE-if use gcd(a,b-a)//O(N)~1e18

1+gcd(a%b,b) return lower value, we need upper value like 1+gcd(a-b,b)
ex. 1+gcd(100%1,1)=2 , 1+gcd(100-1,1)=100 ~because we need num of resister(total num of time it called)
but a/b + gcd(a%b,b) = 1+gcd(a-b,b) => produce same result

</pre>

## Modular Arithmetic

https://libraryguides.centennialcollege.ca/c.php?g=717548&p=5121821
https://codeforces.com/blog/entry/72527

### Properties

- a mod m = b mod m => (a-b) mod m = 0

![](https://prod-qna-question-images.s3.amazonaws.com/qna-images/answer/6195f099-697f-489e-94ae-c77f1a063c08/8512de78-d4fd-43ef-9f61-33fcd14fa8c9/2dm5l1.jpg)

- [495_Modular Equations](./5.modular_arithmetic/modular_arithmetic/495B_Modular%20Equations.cpp)

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

## Binary Exponentiation

## Modular Inverse
