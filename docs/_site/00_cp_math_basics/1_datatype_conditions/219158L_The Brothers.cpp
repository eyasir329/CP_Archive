#include<iostream>

using namespace std;

void takeIO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void solve() {
	string f1,s1,f2,s2;
	cin>>f1>>s1>>f2>>s2;
	if(s1==s2){
		cout<<"ARE Brothers"<<endl;
	}else{
		cout<<"NOT"<<endl;
	}
}

int main() {
	takeIO();
	solve();
	return 0;
}