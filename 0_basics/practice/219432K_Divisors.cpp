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

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin>>n;
	vector<int>v;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			v.pb(i);
			if(i!=n/i) v.pb(n/i);
		}
	}
	sort(all(v));
	for(auto x:v){
		cout<<x<<endl;
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
	// cin >> t;
	while (t--) solve();
	return 0;
}