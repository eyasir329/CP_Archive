# Table of Contents

* [Fast Input & Output](#fast-input--output)

  * [Input with spaces](#input-with-spaces)
  * [End Of File (EOF)](#end-of-file-eof)
* [Data Types and Conditions](#data-types-and-conditions)
* [Large Numbers](#large-numbers)

  * [Read/Write \_\_int128 Example](#readwrite-__int128-example)
  * [Arbitrary Precision Notes](#arbitrary-precision-notes)
  * [Python and Java Modulo Power Examples](#python-and-java-modulo-power-examples)
* [Some Builtin Functions](#some-builtin-functions)
* [Other Tips](#other-tips)

  * [Floating Point Caveats](#floating-point-caveats)
  * [Program Duration Measurement](#program-duration-measurement)
  * [Random Number Generator (C++11+)](#random-number-generator-c11)
  * [Debugging](#debugging)
  * [Multiplying Different Data Types](#multiplying-different-data-types)
  * [Common Mistakes and Tips](#common-mistakes-and-tips)

---

# Fast Input & Output

[USACO Guide: Fast I/O](https://usaco.guide/general/fast-io?lang=cpp)

* Input/output operations are slow by default.

```cpp
ios::sync_with_stdio(false);
```

* Disables synchronization between C and C++ standard streams.
* Allows independent buffering of C++ streams.
* Mixing C-style and C++-style I/O after this may cause unexpected behavior.

```cpp
cin.tie(nullptr);
```

* Unties `cin` from `cout`.

* By default, `cin` is tied to `cout` to flush `cout` before `cin` operations for sensible user interaction.

* Prefer `'\n'` over `endl` for faster output since `endl` flushes the buffer.

---

## Input with spaces

* Use `cin.getline(s, n);` or `getline()` instead of `get()` to read input lines including spaces.

```cpp
char c[100];
int n; cin >> n;
// cin.get(); // avoid off-by-one line reading due to leftover newline
cin.ignore();
while (n--) {
    cin.getline(c, 100);
}
```

---

## End Of File (EOF)

Input until EOF example:

```cpp
while (cin >> x) {
    ans += x;
}
```

---

# Data Types and Conditions

[USACO Guide: Data Types](https://usaco.guide/general/data-types?lang=cpp)

![data_type](https://i.ibb.co.com/mCSZKPF/Screenshot-from-2024-10-02-23-41-19.png)

* Floating-point numbers are not exact.
* Avoid direct equality comparison (`==`) for floating points.
* Use an epsilon check:

```cpp
if (abs(a - b) < 1e-9) {
    // a and b are effectively equal
}
```

* Typical floating point types:

  * `double` (64-bit) — usually sufficient
  * `long double` (80-bit, GCC extension) — more precise but slower

* Some numbers can’t be represented exactly, leading to rounding errors.

* Integers up to $2^{53}$ can be exactly represented in double precision.

* Booleans use 1 byte (8 bits), wasting 7 bits; to save space use `std::bitset`.

---

### Example: Beware subtle integer overflow

```cpp
long long x = 123456789123456789LL;

int a = 123456789;
long long b = a * a;  // WRONG: overflow in a * a before promotion
cout << b << "\n";    // prints incorrect value

// Correct way:
long long b_correct = (long long)a * a;
```

---

# Large Numbers

* `long long` usually suffices in contests.

* GCC supports `__int128_t` (128-bit integer), range approx $-10^{38}$ to $10^{38}$, but not always available.

* `unsigned long long` ranges from 0 to $2^{64} - 1 \approx 1.8 \times 10^{19}$.

* Integer typical range: up to about 2e9 (signed 32-bit int).

---

## Read/Write \_\_int128 Example

```cpp
#include <bits/stdc++.h>
using namespace std;

__int128 read() {
    string s; cin >> s;
    __int128 ans = 0;
    for (char ch : s)
        ans = ans * 10 + (ch - '0');
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
    cout << to_string(x) << "\n";
}

int32_t main() {
    __int128 x = read();
    write(x);
    return 0;
}
```

---

## Arbitrary Precision Notes

* **Python:**
  `int` is arbitrary precision, limited by available memory.

* **Java:**
  `BigInteger` allows arbitrary precision integers, limited by memory. Larger numbers need more memory and CPU time.

---

## Python and Java Modulo Power Examples

```py
# Python
n = int(input())
m = int(input())
twon = 1 << n
print(m % twon)
```

```java
// Java
import java.math.BigInteger;
import java.util.Scanner;

public class ModuloPower {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        BigInteger m = scanner.nextBigInteger();
        BigInteger twon = BigInteger.valueOf(2).pow((int)n);
        System.out.println(m.mod(twon));
        scanner.close();
    }
}
```

* Example problem: [lightoj\_equal ju ncpc 23](./1_datatype_conditions/lightoj_equal.cpp)

---

# Some Builtin Functions

* `round`, `llround`
* `log` (natural), `log2`, `log10`
* `sqrt`, `cbrt` (cube root)
* `stoi`, `stoll`, `to_string`
* `is_sorted`, `rand` (use `srand(time(0))` for seed)
* `isalpha`, `isdigit`, `islower`, `isupper`, `tolower`, `toupper`

---

# Other Tips

* Use `double` instead of `float` for better accuracy (not 100% exact).
* Prefer using integer data types consistently.
* Be careful when mixing data types.

---

## Floating Point Caveats

```cpp
// log2() or __lg() gives floor(log2(n))
int ans = 0;
while (n > 1) {  // O(log n)
    ans++;
    n /= 2;
}

int ans = 1;
for (int i = 0; i < b; i++) {  // O(b)
    ans *= a;
}

long long ans = sqrt(n);
while (ans * ans <= n) ++ans;
while (ans * ans > n) --ans;
cout << ans << endl;
```

* These return doubles and may have rounding errors.

---

* `long double` is more precise than `double` (avoid using `float`).
* Comparing two doubles:

```cpp
if (abs(a - b) < 1e-9) {
    // considered equal
}
```

* Control decimal precision:

```cpp
cout << setprecision(10) << num;           // set precision globally
cout << fixed << setprecision(10) << num;  // fixed decimal places after dot
```

---

# Program Duration Measurement

```cpp
clock_t start, end;
start = clock();
// ... code to measure ...
end = clock();
cerr << 1.0 * (end - start) / CLOCKS_PER_SEC << " sec\n";
```

---

# Random Number Generator (C++11+)

```cpp
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
```

---

# Debugging

* Use `assert(condition)` — if false, triggers runtime error (useful for debugging).

---

# Multiplying Different Data Types

* Smaller type is promoted to the larger type during multiplication.

---

# Common Mistakes and Tips

* Beware of unsigned types, e.g., `v.size() - 1` can cause underflow because `size()` returns unsigned.
* Reinitialize variables for multiple test cases.

Reference: [https://codeforces.com/blog/entry/111217](https://codeforces.com/blog/entry/111217)

---