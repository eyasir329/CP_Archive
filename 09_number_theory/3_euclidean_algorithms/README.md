## Euclidean Algorithms

- https://codeforces.com/problemset/problem/1866/B

<pre>
LCM and GCD Relationships:
For any prime k, the exponent in LCM(p, q) is the maximum of the exponents of k in p and q.
For any prime k, the exponent in GCD(p, q) is the minimum of the exponents of k in p and q.

Exponent Conditions:
For each prime k in X and Y, we must have:
max(fk(p), fk(q)) = fk(X)
min(fk(p), fk(q)) = fk(Y)
Here, fk(p) denotes the exponent of prime k in p.

Feasibility Check:
If for any prime k, fk(Y) > fk(X), it's impossible to satisfy both conditions, so the answer is 0.
If fk(Y) = fk(X), then fk(p) = fk(q) = fk(X).
If fk(Y) < fk(X), there are two choices:
fk(p) = fk(X) and fk(q) = fk(Y).
fk(p) = fk(Y) and fk(q) = fk(X).
The final result is 2 raised to the power of the number of primes where the exponent in X is greater than in Y,
</pre>

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
