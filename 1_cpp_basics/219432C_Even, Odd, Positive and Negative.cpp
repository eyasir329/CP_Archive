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
	int n; cin>>n;
	int odd=0,even=0,pos=0,neg=0;
	vector<int>v(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(v[i]&1) odd++;
		else even++;
		if(v[i]>0) pos++;
		if(v[i]<0) neg++;
	}
	cout<<"Even: "<<even<<endl;
	cout<<"Odd: "<<odd<<endl;
	cout<<"Positive: "<<pos<<endl;
	cout<<"Negative: "<<neg<<endl;
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