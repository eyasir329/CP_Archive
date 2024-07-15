#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(a) a.begin(),a.end()
#define sz(a) ((int) a.size())
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define endl '\n'
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const int MOD = 1e9 + 7;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x1, y1, x2, y2;
	if (a > b) {
		x1 = a; y1 = b;
	} else {
		x1 = b; y1 = a;
	}
	if (c > d) {
		x2 = c; y2 = d;
	} else {
		x2 = d; y2 = c;
	}

	if (x1 > x2 and y1 <= x2) {
		yes;
	} else if (x2 > x1 and y2 <= x1) {
		yes;
	} else {
		no;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}