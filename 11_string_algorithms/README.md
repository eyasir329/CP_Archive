### Turning a string into a long positive integer (modulo `g`)

Let’s break it down so it’s clear:

```cpp
ll m = 0;
for (int i = 0; i < s.size(); i++) {
    m = ((m * 256) % g + (int)s[i]) % g;
}
m = (m * 65536) % g;
```

---

### 🔎 What it does

1. `m * 256 + s[i]`

   - Each character is treated as a byte (`0–255`).
   - Multiplying by `256` shifts the previous bytes left by 8 bits.
   - Adding `s[i]` appends the new byte at the end.
   - So effectively, you’re interpreting the string as a **big base-256 number**.

2. `% g`

   - Keeps everything reduced modulo `g` (so the number never overflows).

3. `m = (m * 65536) % g;`

   - At the end, the whole number is multiplied by `2^16`.
   - This is like **appending two zero bytes** at the end of the constructed number.

---

### Example

Suppose:

```cpp
string s = "Hi";   // ASCII: 72 105
long long g = 1e9+7;
```

Step by step:

- Start: `m = 0`
- Process `'H'` (`72`): `m = 72`
- Process `'i'` (`105`): `m = 72*256 + 105 = 18537`
- Multiply by `65536`: `m = 18537 * 65536 = 1216346112`
- Modulo `1e9+7`: `m = 216346105`

So final result = **`216346105`**

---

⚡ So your code interprets the string as a **big positive integer in base-256**, then shifts it left by 16 bits (adds two zero bytes).

```cpp
void decToHexa16(unsigned int n) {
    // force it into 16-bit range
    unsigned int high = (n >> 8) & 0xFF; // upper byte
    unsigned int low  = n & 0xFF;        // lower byte

    // print in uppercase hex with 2 digits each
    cout << uppercase << hex << setw(2) << setfill('0') << high << " "
         << setw(2) << setfill('0') << low << endl;
}
```

---
