### Primes

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

example:

- Prove that, for all primes p, the smallest positive integer whose factorial is divisible by p is p itself.

  <pre>
  It is trivial by inspection that p satisfies this condition. Let the smallest positive such
  integer be k. For the sake of contradiction, assume that k < p and p|k!. Then, k! is the product of all positive integers less than p and p is present in the prime factorization of k!. Some of the positive integers in this product are themselves primes less than p, while others are less than p and have unique prime factorizations involving only primes less than p by the fundamental theorem of arithmetic. Thus, p cannot be present in prime factorization of k!, establishing contradiction. This means that k = p. 
  </pre>

---

### Factorization

- [576A_Vasya and Petya's Game](./2.divisors/576A_Vasya%20and%20Petya's%20Game.cpp)

<pre>
# thought of number x between 1 and n, another tries to guess the number
# another can ask, is the unknown number divisible by number y?
# find the minimum number of questions he should ask to make a guaranteed guess number.

n factorize = (2,2,2,3,5...y)
if(n is divisible y) y*y until find n.. then next y

</pre>

---
