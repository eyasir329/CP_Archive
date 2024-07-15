#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin>>n;
    long long maxn = 0,minn=0;
    if(n<4 or n&1){
        cout<<-1<<endl;
    }else{
        maxn = n/4;
        minn = n/6;
        if(n%6!=0){
            minn++;
        }
        cout<<minn<<" "<<maxn<<endl; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}