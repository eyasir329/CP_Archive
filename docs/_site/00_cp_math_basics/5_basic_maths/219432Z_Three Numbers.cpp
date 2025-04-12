#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(a) a.begin(),a.end()
#define sz(a) ((int) a.size())
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define endl '\n'
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const int MOD = 1e9 + 7;

void solve() {
	int k, s;
	cin >> k >> s;
	// x+y+z=s
	int cnt = 0;
	for (int x = 0; x <= k; x++) {
		for (int y = 0; y <= k; y++) {
			int z = s - (x + y);
			if(z>=0 and z<=k) cnt++;
		}
	}
	cout << cnt << endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}