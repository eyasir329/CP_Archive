# Number Theory

https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/tutorial/

## Divisors

<pre>
- odd number of divisors are perfect square (i==n/i we eliminate one divisors because of unique divisors.) (ex. cf2020B)
- otherwise all other number has even number of divisors
</pre>

```cpp
//finding divisors using sqrt method O(sqrt(n))
//used to find single number
vector<int>divisors_of_n(int n) {
    vector<int>divisors;
    //we have to maintain (i*i) not go to overflow
    //if(overflow) then it go to infinite loop
    for (int i = 1; i * i <= n; i++) {//because of sqrt()-> may cause precision error
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {//because of unique divisors
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    for (auto x : divisors) {
        cout << x << " ";
    }
    return divisors;
}
```

- Number of Divisors from 1 to N (Each Number)

<pre>
  normal way O(nsqrt(n) causes TLE) (n upto 1e5)-> O(nlogn)
</pre>

```cpp
//complexity O(nlogn)
//used to find multiple number
const int N = 1e7+9;
int d[N];
for(int i=1;i<N;i++){
  for(int j=i;j<N;j+=i){//harmonic series
    d[j]++;
  }
}
// if(d[i]==2) -> they are prime
```

example:

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

## Primes

<pre>
- prime has exactly two divisors (1 & that number)
- other number can be represented by multiple of different prime numbers
</pre>

```cpp
//check n is prime or not
bool is_prime(long long n){
  if(n==1) return false;
  for(int i=2;1LL*i*i<=n;i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}
```

###### Co-Prime Numbers

<pre>
- no common factors other than one
</pre>

<img src="https://st.adda247.com/https://www.adda247.com/jobs/wp-content/uploads/sites/2/2022/11/15181619/Co-prime-numbers.png" alt="coprime" style="height:230px;">

example:

- [spoj_VECTAR8 - Primal Fear](./1_primes_and_divisors/1_primes/spoj_VECTAR8_Primal%20Fear.cpp)

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

---

## Factorization

- [576A_Vasya and Petya's Game](./2.divisors/576A_Vasya%20and%20Petya's%20Game.cpp)

<pre>
# thought of number x between 1 and n, another tries to guess the number
# another can ask, is the unknown number divisible by number y?
# find the minimum number of questions he should ask to make a guaranteed guess number.

n factorize = (2,2,2,3,5...y)
if(n is divisible y) y*y until find n.. then next y

</pre>

---

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

---
