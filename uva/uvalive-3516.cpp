/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-13 13:06:13
 * @Description: 区间dp
 * @Source: https://vjudge.net/problem/UVALive-3516
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=3e2+10;
const int MOD=1e9;
typedef long long ll;
using namespace std;
char str[MAX];
ll dp[MAX][MAX];
ll solve(int i,int j){
	if(i==j)return 1;
	if(str[i]!=str[j]) return 0;
	if(dp[i][j]>=0)return dp[i][j];
	ll ans=0;
	for(int k=i+2;k<=j;k++){
		ans=(ans+solve(i+1,k-1)*solve(k,j))%MOD;
	}
	return dp[i][j]=ans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	while(~scanf("%s",str+1)){
		int len=strlen(str+1);
		mst(dp,-1);
		ll ans=solve(1,len);
		printf("%lld\n",ans);

	}

    return 0;
}
