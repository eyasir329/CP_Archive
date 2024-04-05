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
	char c;
	cin >> c;
	if (c >= 'A' and c <= 'Z') {
		cout << char(c + 32);
	} else {
		cout << char(c - 32);
	}
	return 0;
}