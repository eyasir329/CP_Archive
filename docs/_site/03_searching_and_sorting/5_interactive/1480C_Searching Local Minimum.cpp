#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int n;
map<int,int>prev_values;

int query(int index){
    if(prev_values.find(index)!=prev_values.end()){
        return prev_values[index];
    }
    if(index==0 or index==n+1){
        return INF;
    }
    cout<<"? "<<index<<endl;
    int value; cin>>value;
    return prev_values[index]=value;
}

void solve() {
    cin>>n;
    int l = 0,r = n+1;
    while(r-l>1){
        int m = (r+l)/2;
        (query(m+1)>query(m))?(r=m):(l=m);
    }
    cout<<"! "<<r<<endl;
}

int32_t main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}