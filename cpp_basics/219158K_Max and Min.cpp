#include<iostream>
#include<algorithm>

using namespace std;

void takeIO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void solve() {
	int a,b,c;
	cin>>a>>b>>c;
	// if(a<=b and a<=c){
	// 	cout<<a;
	// }else if(b<=c){
	// 	cout<<b;
	// }else{
	// 	cout<<c;
	// }
	// cout<<" ";
	// if(a>=b and a>=c){
	// 	cout<<a;
	// }else if(b>=c){
	// 	cout<<b;
	// }else{
	// 	cout<<c;
	// }
	// cout<<endl;
	cout<<min({a,b,c})<<" "<<max({a,b,c})<<endl;
}

int main() {
	takeIO();
	solve();
	return 0;
}