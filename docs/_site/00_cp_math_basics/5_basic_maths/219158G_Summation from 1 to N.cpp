#include<iostream>

using namespace std;

void takeIO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void solve() {
	long long n;
	cin >> n;
	long long ans = (n * 1LL * (n + 1)) / 2;
	cout << ans << endl;
}

int main() {
	takeIO();
	solve();
	return 0;
}