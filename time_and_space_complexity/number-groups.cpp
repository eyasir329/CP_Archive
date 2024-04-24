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
	int k; cin>>k;
	int ans = 0;
	int ith = (k*(k-1))/2+1;
	int num = 1+(ith-1)*2;//a+(n-1)*d 
	for(int i=0;i<k;i++){
		ans+=num;
		num+=2;
	}
	cout<<ans<<endl;
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

#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define vi vector <int>
#define vii vector <pair<int,int>>
#define vc vector <char>
#define all(a) a.begin(),a.end()
#define sz(a) ((int) a.size())
#define F0R(i,a,b) for(int i=a; i<(b); i++)
#define FOR(i,a) for(int i=0; i<(a); i++)
#define SORT(a) sort(all(a),[](auto &left,auto &right){return left.second<right.second})
/* --------------------------------------------
---must be initialise in another variable ----*/
#define is(num) to_string(num);
#define ci(ch) static_cast<int>(ch)-48; //A-65 0-48 a-97
#define si(str) stoi(str);
/*-------------------------------------------*/
#define BS(a,x) binary_search(all(a),x) //r-1/0
#define LB(a,x) lower_bound(all(a),x)-a.begin() //r-index ..check condition ind>=0 or ind!=n
#define UB(a,x) upper_bound(all(a),x)-a.begin() //r-next to real index
#define FIND(a,x) find(all(a),x) //r-index ..init vi:iterator it/auto..check it!=a.end()
/*-------------------------------------------*/
#define REDUCE(a) sort(all(a);a.erase(unique(all(a)),a.end()))
#define FREQ(a,m) for(auto i=0;i<sz(a);i++) m[a[i]]++ //m like ..map<char,int>m
#define mPrint(m) for(auto itr=m.begin();itr!=m.end();itr++)cout<<itr->first<<" "<<itr->second<<endl
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a)  accumulate(all(a), 0LL)
#define SRT(a)  is_sorted(all(a)) //range1,range2
#define IN(a,pos,num) a.insert(pos,num)
#define DE(a,pos) a.erase(a.begin()+pos)
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl
#define endl '\n'
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl


void solve()
{

}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();
    int t = 1,i=1;
    cin >> t;
    while (t--){
        auto s = ((double)(clock() - z) / CLOCKS_PER_SEC);
        solve();
        auto e = ((double)(clock() - z) / CLOCKS_PER_SEC);
        cerr<<"Case # "<<i<<" RT :"<<e-s<<endl;
        i++;
    }
    cerr<<"TRT :"<<((double)(clock() - z) / CLOCKS_PER_SEC)<<endl;
    return 0;
}