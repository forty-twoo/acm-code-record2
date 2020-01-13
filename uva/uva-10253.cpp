/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-13 14:33:36
 * @Description: 组合数学+递推
 * @Source: https://vjudge.net/problem/UVA-10253
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=35;
const int MOD=1e9;
typedef long long ll;
using namespace std;
int n;
ll dp[MAX][MAX],f[MAX];
//有重复取出的组合数
double solve(ll x,ll y){
	ll i=x;
	double ans=1;
	for(ll j=y;j>=1;j--){;
		ans=ans*i;
		i--;
	}
	for(ll j=y;j>=1;j--){;
		ans/=j;
	}
	return (ans+0.5);
}
void init(){
	mst(dp,0);mst(f,0);
	//注意边界
	f[1]=1;
	for(int i=0;i<MAX;i++)dp[i][0]=1;
	for(int i=1;i<MAX;i++)dp[i][1]=1,dp[0][i]=0;

	for(int i=1;i<MAX;i++){
		for(int j=2;j<MAX;j++){
			for(int k=0;k*i<=j;k++){
				dp[i][j]+=dp[i-1][j-k*i]*(ll)solve(f[i]+k-1,k);
			}
		}
		f[i+1]=dp[i][i+1];
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	while(~scanf("%d",&n) && n){
		init();
		if(n==1){
			printf("1\n");
		}else{
			printf("%lld\n",f[n]*2ll);
		}
	}
    return 0;
}
