#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int dp[100329];

int solve(int n,int k){
  if(n<k){
    return 1;
  }
  if(dp[n]!=-1){
    return dp[n];
  }
  int pick = solve(n-k,k);//white
  int not_pick = solve(n-1,k);//red
  dp[n]=(pick+not_pick)%MOD;
  return dp[n];
}

int main(){
  memset(dp,-1,sizeof(dp));//only initialize by 0 or -1 nothing else
  int t,k;cin>>t>>k;
  int prefix[100329]={0};
  prefix[0]=solve(0,k);
  for(int i=1;i<100329;i++){
    prefix[i]=(prefix[i-1]+solve(i,k))%MOD;
  }
  while(t--){
    int a,b; cin>>a>>b;
    cout<<((prefix[b]-prefix[a-1])%MOD+MOD)%MOD<<endl;
  }
  return 0;
}