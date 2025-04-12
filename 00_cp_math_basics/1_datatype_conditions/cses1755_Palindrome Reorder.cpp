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
    string s; cin >> s;
    map<char, int>m;
    for (int i = 0; i < sz(s); i++) {
        m[s[i]]++;
    }
    int cnt = 0;
    for (auto x : m) {
        if (x.ss % 2 != 0) {
            cnt++;
        }
    }
    if (cnt!=0) {
        if (cnt != 1) {
            cout << "NO SOLUTION" << endl;
        } else {
            string temp;
            char c;
            for (auto x : m) {
                if (x.ss % 2 == 0) {
                    int t2 = (int)x.ss / 2;
                    while (t2--) {
                        temp += x.ff;
                    }
                } else {
                    c = x.ff;
                    if (x.ss > 1) {
                        int t3 = x.ss;
                        t3--;
                        t3 /= 2;
                        while (t3--) {
                            temp += c;
                        }
                    }

                }
            }
            cout << temp;
            if (c) cout << c;
            reverse(all(temp));
            cout << temp << endl;
        }
    } else {
        string temp;
        for (auto x : m) {
            int t2 = (int)x.ss / 2;
            while (t2--) {
                temp += x.ff;
            }
        }
        cout << temp;
        reverse(all(temp));
        cout << temp << endl;
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