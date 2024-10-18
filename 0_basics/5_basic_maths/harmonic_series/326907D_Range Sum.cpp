#include<iostream>

using namespace std;

void takeIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    long long l, r;
    cin >> l >> r;
    if (r > l) {
        long long temp = l;
        l = r;
        r = temp;
    }
    long long left = (l * 1LL * (l + 1)) / 2;
    long long right = ((r - 1) * 1LL * (r - 1 + 1)) / 2;
    cout << left - right << endl;
}

int main() {
    takeIO();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}