# 📘 C++ Basics Cheatsheet

## 📑 Table of Contents

1. [Pointers](#1-pointers)
2. [References (Call by Value & Call by Reference)](#2-references-call-by-value--call-by-reference)
3. [Iterators](#3-iterators)
4. [Struct vs Class](#4-struct-vs-class)
5. [Operator Overloading](#5-operator-overloading)
6. [Others (Utilities)](#6-others-utilities)
7. [Auto / Pair / Tuple](#7-auto--pair--tuple)

---

## 1. 🔁 Pointers

* Memory address of variable `x`: `&x`
* Pointer variable:

  ```cpp
  int* ptr = &n;
  ```
* Dereferencing operator: `*ptr` → value at memory location
* Update pointer value: `*ptr = num`
* Null pointers:

  ```cpp
  int* ptr = nullptr; // or NULL or ptr = 0;
  ```

### Access in Array via Pointer

| Expression        | Meaning                                         |
| ----------------- | ----------------------------------------------- |
| `x + 4*(i-1)`     | Address of i-th element (assuming 4-byte `int`) |
| `ptr + (i - 1)`   | Pointer arithmetic                              |
| `*ptr = *ptr + 2` | Modify the value pointed to                     |

---

## 2. 🔄 References (Call by Value & Call by Reference)

* Call by value:

  ```cpp
  int x = 5; int y = x; // Different memory locations
  ```
* Call by reference:

  ```cpp
  int x = 5; int &y = x; // Same memory location
  y += 5; // x becomes 10
  ```

⚠️ `int &y; y = x;` is invalid.

### Notes

* Call by reference is **faster** than call by value.
* Arrays are passed **by reference** by default.
* Container copy time: **O(n)**

---

## 3. 🔁 Iterators

* Work like pointers for containers.
* Example:

  ```cpp
  vector<int>::iterator it = v.begin(); // or auto it = v.begin();
  ```

### Operations

| Operation             | Description                          |
| --------------------- | ------------------------------------ |
| `*it`                 | Dereference to get value             |
| `it++` / `it--`       | Next / previous element              |
| `it += x`             | Jump forward by x (random iterators) |
| `it -= x`             | Jump backward by x                   |
| `v.end() - v.begin()` | Number of elements (size)            |
| `distance(a, b)`      | Get range between two iterators      |

### Iterator Types

| Container Type                                   | Iterator Type |
| ------------------------------------------------ | ------------- |
| `vector`, `deque`, `array`, `string`             | Random Access |
| `list`, `set`, `map`                             | Bidirectional |
| `forward_list`, `unordered_set`, `unordered_map` | Forward Only  |

### Special Notes

* Reverse:

  ```cpp
  vector<int>::reverse_iterator rit = v.rbegin();
  ```
* Reverse iterators: `rit++` goes backward (normal `-`, reverse `+`)
* Iterators become **invalid** after container modification.

---

## 4. 🆚 Struct vs Class

```cpp
struct Point {
    double x, y;
    void display() const {
        cout << "Point(" << x << ", " << y << ")\n";
    }
};

class Circle {
private:
    double radius;
    Point center;

public:
    Circle(double r, double cx, double cy) : radius(r), center{cx, cy} {}
    void display() const {
        cout << "Circle with radius " << radius << " at ";
        center.display();
    }
};
```

* `struct`: Members are **public** by default
* `class`: Members are **private** by default

---

## 5. ➕ Operator Overloading

```cpp
pair<int, int> operator + (const pair<int, int> a, const pair<int, int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

int main() {
    pair<int, int> a = {2, 3};
    pair<int, int> b = {5, 3};
    pair<int, int> c = a + b; // {7, 6}
}
```

---

## 6. ⚙️ Others (Utilities)

### `boolalpha`

```cpp
cout << boolalpha << a << " " << b << endl;
```

### `sizeof`

```cpp
cout << sizeof(int) << endl; // 4 bytes
size_t n = sizeof(arr) / sizeof(arr[0]);
```

* `size_t`: unsigned integer type
* Danger of `size() - 1`:

  ```cpp
  size_t n = v.size();
  int last_index = (int)v.size() - 1; // safer
  ```

---

## 7. ⚗️ Auto / Pair / Tuple

### `auto`

* Infers the data type automatically from initializer:

  ```cpp
  auto x = 5; // int
  auto it = v.begin(); // iterator
  ```

### `pair`

```cpp
pair<int, double> p = make_pair(5, 2.5);
cout << p.first << " " << p.second << endl;

pair<pair<int, int>, int> p;
p = make_pair(make_pair(1, 2), 3);
cout << p.first.first << " " << p.first.second << " " << p.second;
```

### `tuple`

```cpp
tuple<int, int, int> t = {1, 2, 3};
auto [a, b, c] = t; // C++17 structured binding
tie(a, b, c) = t;

t = make_tuple(a, b, c);
cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
```

* Nested access: `get<0>(get<2>(t))`
* Tuple can store >2 values, unlike pair.

---