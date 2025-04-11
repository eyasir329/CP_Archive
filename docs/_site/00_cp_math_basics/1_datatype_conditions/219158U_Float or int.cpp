#include<iostream>
#include<math.h>

using namespace std;

void takeIO(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}

int main(){
	takeIO();
	long double n;
	cin>>n;
	if(floor(n)==ceil(n)){
		cout<<"int"<<" "<<n;
	}else{
		cout<<"float "<<floor(n)<<" "<<n-floor(n);
	}
	return 0;
}