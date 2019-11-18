/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2019-11-18 19:50:50
 * @Description: 区间dp+记忆化+博弈
 * @Source: https://vjudge.net/problem/UVA-10891
 */
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<set>
#define INF 0x3f3f3f3f
#define mst(a,b) memset(a,b,sizeof(a))
const double eps=1e-5;
const int MAX=1e2+10;
const int MOD=998244353;
typedef long long ll;
using namespace std;
int n;
int a[MAX],sum[MAX],dp[MAX][MAX],vis[MAX][MAX];
int solve(int i,int j){
	if(vis[i][j]) return dp[i][j];
	vis[i][j]=1;
	int minn=0;
	//注意for的范围
	for(int k=i+1;k<=j;k++){
		minn=min(minn,solve(k,j));
	}
	for(int k=i;k<j;k++){
		minn=min(minn,solve(i,k));
	}
	dp[i][j]=sum[j]-sum[i-1]-minn;
	return dp[i][j];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
	while(~scanf("%d",&n) && n){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		mst(vis,0);
		mst(dp,0);
		int ans=2*solve(1,n)-sum[n];
		printf("%d\n",ans);
	}
	return 0;
}
