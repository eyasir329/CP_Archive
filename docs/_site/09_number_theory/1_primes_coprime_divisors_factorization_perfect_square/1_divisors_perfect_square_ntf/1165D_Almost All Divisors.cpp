#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int n; cin>>n;
    std::vector<int> div(n);
    for(int i=0;i<n;i++){
        cin>>div[i];
    }
    sort(div.begin(),div.end());
    int original_num = div[0]*div[n-1]*1ll;
    std::vector<int> div2;
    for(int i=2;i*i<=original_num;i++){
        if(original_num%i==0){
            div2.push_back(i);
            if(i!=original_num/i){
                div2.push_back(original_num/i);
            }
        }
    }
    sort(div2.begin(),div2.end());
    if(div==div2){
        cout<<original_num<<endl;
    }else{
        cout<<-1<<endl;
    }
}

int32_t main() {
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