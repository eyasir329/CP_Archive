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
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	a = a % 100;
	b = b % 100;
	c = c % 100;
	d = d % 100;
	long long multi = (a * b * c * d) % 100;
	if ( multi > 9) {
		cout << multi;
	} else {
		cout << '0' << multi;
	}
	return 0;
}