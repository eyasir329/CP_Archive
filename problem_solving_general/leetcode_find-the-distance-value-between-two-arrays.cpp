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

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int ans = 0;
    for (int i = 0; i < sz(arr1); i++) {
        int cnt = 0;
        for (int j = 0; j < sz(arr2); j++) {
            if (abs(arr1[i] - arr2[j]) > d) {
                cnt++;
            }
        }
        if (cnt == sz(arr2)) {
            ans++;
        }
    }
    return ans;
}

void solve() {
    vector<int>arr1 = {1, 4, 2, 3};
    vector<int>arr2 = { -4, -3, 6, 10, 20, 30};
    int d = 3;
    cout << findTheDistanceValue(arr1, arr2, d) << endl;
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