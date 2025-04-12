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
	int a, b;
	char ch;
	cin >> a >> ch >> b;
	if (ch == '>' and a > b) {
		cout << "Right";
	} else if (ch == '<' and a < b) {
		cout << "Right";
	} else if (ch == '=' and a == b) {
		cout << "Right";
	} else {
		cout << "Wrong";
	}
	return 0;
}