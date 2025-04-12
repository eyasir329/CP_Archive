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
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	vector<int>freq(14,0);
	freq[a]++;
	freq[b]++;
	freq[c]++;
	freq[d]++;
	freq[e]++;
	for(int i=1;i<14;i++){
		for(int j=1;j<14;j++){
			if(freq[i]==2 and freq[j]==3){
				cout<<"Yes";
				return;
			}
		}
	}
	cout<<"No";
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