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
	// 144-14-1
	string s; cin >> s;
	int i = 0;
	bool flag = true;
	while (i < s.size()) {
		if (i + 2 < s.size() and s.substr(i, 3) == "144") i += 3;
		else if (i + 1 < s.size() and s.substr(i, 2) == "14") i += 2;
		else if (s[i] == '1') i++;
		else {
			flag = false;
			break;
		}
	}
	if (flag) yes;
	else no;
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