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
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			cnt++;
		}
	}
	cnt==2? (cout<<"YES"):(cout<<"NO");
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