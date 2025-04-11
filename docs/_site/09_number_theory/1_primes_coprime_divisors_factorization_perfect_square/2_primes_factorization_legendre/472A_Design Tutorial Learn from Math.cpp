#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

std::vector<int> seive(maxn+1,1);

void seiveoferatosthenes(){
    seive[0]=0;
    for(int i=2;i<=maxn;i++){
        if(seive[i]==1){
            for(int j=i;j<=maxn;j+=i){
                if(seive[j]==1){
                    seive[j]=i;
                }
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    for(int i=4;i<n;i++){
        int x=i;
        int y = n-x;
        if(seive[x]!=x and seive[y]!=y){
            cout<<x<<" "<<y<<endl;
            return;
        }
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

    seiveoferatosthenes();

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}