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
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b*log(a)>d*log(c)){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}