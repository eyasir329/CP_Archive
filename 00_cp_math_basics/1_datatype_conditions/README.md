### Data Types, Conditions

https://usaco.guide/general/data-types?lang=cpp
![data_type](https://i.ibb.co.com/mCSZKPF/Screenshot-from-2024-10-02-23-41-19.png)

```
* floating point numbers are not exact.
* so it's generally a bad idea to compare two floating-point numbers for exact equality (==).
* Hence, we should always expect that floating point numbers are slightly o↵.
```

```cpp
    if (abs(a-b) < 1e-9) {
        // a and b are equal
    }
```

- The usual floating point types in competitive programming are the 64-bit double
  and, as an extension in the g++ compiler, the 80-bit long double. In most cases,
  double is enough, but long double is **more accurate**.

- Some numbers cannot
  be represented accurately as floating point numbers, and there will be rounding
  errors.

* Note that while floating point numbers are inaccurate, integers up to a certain
  limit can still be represented accurately. For example, using double, it is possible to accurately represent all integers whose absolute value is at most 2<sup>53</sup>.

Booleans require 1 byte (8 bits) of storage, not 1 bit, wasting the other 7 bits of storage. To use less memory, one can use bitsets (std::bitset in C++ / BitSet in Java).

https://usaco.guide/CPH.pdf#page=16

```cpp
long long x = 123456789123456789LL;

//subtle error:
int a = 123456789;
long long b = a*a;
cout << b << "\n"; // -1757895751
//solve it using
(long long)a*a
```

---

### Large Numbers

Usually contest problems are set so that the type long long is enough. Still,
it is good to know that the g++ compiler also provides a 128-bit type \_\_int128_t
with a value range of −2<sup>127</sup> . . . 2<sup>127</sup> − 1 or about −10<sup>38</sup> . . . 10<sup>38</sup>. However, this type
is not available in all contest systems

- unsigned long long (range 0 -> 2^64-1 (1.8\*10<sup><b>19</b></sup>)), occupies 8 bytes of memory.

```cpp
//read, write function of 128 bit integer
#include <bits/stdc++.h>
using namespace std;

__int128 read() {
    string s; cin >> s;
    __int128 ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - '0');
    }
    return ans;
}

string to_string(__int128 x) {
    string s;
    while (x > 0) {
        s += (char)(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

void write(__int128 x) {
    cout << to_string(x) << endl;
}

int32_t main() {
    __int128 x = read();
    write(x);
    return 0;
}
```

```
In Python:
- Arbitrary-Precision: int type can grow as large as memory allows.
- Memory constraints: Size is limited by available system memory.

In Java:
- Arbitrary Precision: BigInteger handles integers limited by available memory.
- Memory Limitation: Size is constrained by system memory, more memory needed for larger numbers.
- Efficiency: Operations on large BigIntegers take more time and memory.
- Practical Example: BigInteger with 100,000 digits works if system memory allows.
```

- https://vjudge.net/problem/CodeForces-913A

```py
#using python
n = int(input())
m = int(input())
twon = 1 << n
print(m % twon)`
```

```java
//using java
import java.math.BigInteger;
import java.util.Scanner;

public class ModuloPower {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        BigInteger m = scanner.nextBigInteger();
        BigInteger twon = BigInteger.valueOf(2).pow((int) n);
        System.out.println(m.mod(twon));
        scanner.close();
    }
}
```

example:

- [lightoj_equal ju ncpc 23](./1_datatype_conditions/lightoj_equal.cpp)

---

#### Some builtin function

- round, llround
- log -> natural log, log2, log10
- sqrt, cbrt -> cube root
- stoi, stoll, to_string
- is_sorted, rand -> random number (srand(time(0)) seed the random number generator-change everytime)
- isalpa, isdigit, islower, isupper, tolower, toupper

---

#### Other's Things\*

- better to use double instead of float to have more accuracy (not precious 100%)
- it's always better to use integer data type, use same type everywhere.
- we have to be careful to use (NEVER EVER DO, UNTILL HAVE TO DO)
- [Cautions for use inbuild functions](https://codeforces.com/blog/entry/107717)

```cpp
log2()->__lg()->give us floor (max set number),
int ans = 0;
while (n > 1) { //0(logn) but accurate
      ans++;
      n /= 2;
}
pow()->round(pow()),
    int ans = 1;
for (int i = 0; i < b; i++) { //log(b) but accurate
      ans *= a;
}
sqrt()->//similar to cubic root
long long ans = sqrt(n);//sqrtl()
while (ans * ans <= n)++ans;
while (ans * ans > n)--ans;
cout << ans << endl;
```

because that are return double values.

[Dhaka ICPC 24 Preli Three Quick Brown Foxes Jump Over a Lazy Chicken]()

- long double is more precise that double//but not use float

- compare two double

```cpp
  if(a-b<1e-9){
    //they are equal
  }
```

- cout<<setprecision(10)<<num; //from starting//rounding last digit
- cout<<fixed<<setprecision(10)<<num; //from after dot

- program duration

```cpp
    clock_t start,end;
    start = clock();//store clock tick (between 1e6)
        ....
    end = clock();
    cerr<<1.0*(end-start)/CLOCKS_PER_SEC<<" sec"<<endl;
```

- assert(condition) -> if true noting happened otherwise give runtime error. -- using for debugging purpose.

- Multiplying two different Data Types

      -> smaller type gets promoted to the larger type

- common mistakes

  https://codeforces.com/blog/entry/111217

- be careful in v.size()-1 -> because of unsigned int doesn't have negative number

- be careful in multiple test case (all variable need to be reinitialization)
