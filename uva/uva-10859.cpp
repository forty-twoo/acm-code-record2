/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2019-11-18 23:27:59
 * @Description: 树形dp+2个优化目标的解法
 * @Source: https://vjudge.net/problem/UVA-10859
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
const int MAX=1e3+10;
const int MOD=998244353;
typedef long long ll;
using namespace std;
const int M=2000;
int n,m,vis[MAX];
vector<int> G[MAX];
int dp[MAX][2],rt;

void dfs(int u,int ff){
	dp[u][0]=0;
	dp[u][1]=M;
	vis[u]=1;
	for(auto v: G[u]){
		if(v==ff)continue;
		dfs(v,u);
		dp[u][0]+=dp[v][1]+1;
		dp[u][1]+=min(dp[v][1],dp[v][0]+1);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
	int ks;
	scanf("%d",&ks);
	while(ks--){
		scanf("%d%d",&n,&m);
		int x,y;
		for(int i=1;i<=n;i++)G[i].clear();
		mst(vis,0);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			x++;y++;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!vis[i] || !G[i].size()){
				dfs(i,0);
				ans+=min(dp[i][1],dp[i][0]);
			}
		}
		printf("%d %d %d\n",ans/M,m-ans%M,ans%M);
	}
	return 0;
}
