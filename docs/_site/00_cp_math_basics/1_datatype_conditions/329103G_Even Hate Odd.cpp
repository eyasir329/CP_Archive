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
	int n;
	cin>>n;
	vector<int>v(n,0);
	int cnt = 0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		cnt+=v[i]&1;
	}
	if(n&1) cout<<-1<<endl;
	else{
		cout<<abs(cnt-n/2)<<endl;
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