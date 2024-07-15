#include<iostream>

using namespace std;

void takeIO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {
	takeIO();
	int a,b;
	cin>>a>>b;
	if(a>=b){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}