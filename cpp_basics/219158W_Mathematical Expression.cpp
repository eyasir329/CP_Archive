#include<iostream>

using namespace std;

void takeIO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {
	takeIO();
	int a, b, c;
	char ch1, ch2;
	cin >> a >> ch1 >> b >> ch2 >> c;
	if (ch1 == '+') {
		if (a + b == c) {
			cout << "Yes";
		} else {
			cout << a + b;
		}
	}
	else if (ch1 == '-') {
		if (a - b == c) {
			cout << "Yes";
		} else {
			cout << a - b;
		}
	}
	else {
		if (a * b == c) {
			cout << "Yes";
		} else {
			cout << a*b;
		}
	}
	return 0;
}