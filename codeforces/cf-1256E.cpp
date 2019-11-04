/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2019-11-05 01:10:54
 * @Description: set维护dp
 * @Source: http://codeforces.com/contest/1256/problem/E
 */
#include<bits/stdc++.h>
#define mst(a,x) memset(a,x,sizeof(a))
#define INF 0x3f3f3f3f
typedef long long ll;
typedef long double ldle;
using namespace std;
const int MAX = 1e6+10;
const int MAXN = 1e6+10;
const int MOD = 1e9+7;
int n,a[MAX];
int tag[MAX];
struct Node{
	int v,id;
	int nv,nid;
}node[MAX];
int dp[MAX];
int pre[MAX];
int A[MAX];
bool cmp1(const Node&X,const Node&Y){
	return X.v<Y.v;
}
typedef pair<int,int> PI;
set<PI> S;
void solve(int p,int cnt){
	int x=pre[p];
	tag[x]=cnt;
	if(!x)return;
	solve(x,cnt+1);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		node[i].v=a[i];node[i].id=i;
	}
	sort(node+1,node+1+n,cmp1);
	int ans=node[n].v-node[1].v;
	if(n<6){
		printf("%d 1\n",ans);
		for(int i=1;i<=n;i++){
			printf("1 ");
		}
		puts("");
		return 0;
	}
	dp[0]=-node[1].v;
	S.insert(make_pair(dp[0],0));
	for(int i=3;i<=5;i++){
		dp[i]=node[i].v-node[1].v-node[i+1].v;
	}
	for(int i=6;i<=n;i++){
		S.insert(make_pair(dp[i-3],i-3));
		auto it=*(S.begin());
		dp[i]=it.first+node[i].v-node[i+1].v;
		pre[i]=it.second;
	}
	solve(n,1);
	printf("%d %d\n",dp[n],tag[0]);
	int k=1;
	for(int i=1;i<=n;i++){
		A[node[i].id]=k;
		if(tag[i]){
			k++;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",A[i]);
	}

	puts("");
	return 0;
}
