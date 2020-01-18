/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-18 20:56:43
 * @Description: RMQ
 * @Source: https://vjudge.net/problem/UVA-11235
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define lowbit(x) (x&(-x))
#define INF 0x3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=1e5+10;
const int MAXN=1e6+10;
const int MOD=1e3;
typedef long long ll;
using namespace std;
int n,Q,a[MAX],p;
int Lb[MAX],Rb[MAX];
int id[MAX],sz[MAX];
int dp[MAX][40];
void init(){
	for(int i=1;i<=p;i++){
		dp[i][0]=sz[i];
	}
	int t=log(p)/log(2)+1;
	for(int j=1;j<t;j++){
		for(int i=1;i+(1<<j)-1<=p;i++){
			dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
		}
	}
}
int Query(int l,int r){
	int k=log(r-l+1)/log(2);
	return max(dp[l][k],dp[r-(1<<k)+1][k]);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	while(~scanf("%d",&n) && n){
		scanf("%d",&Q);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		a[0]=a[n+1]=INF;
		p=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]){
				Lb[i]=Lb[i-1];
				sz[p]++;
				id[i]=p;
			}else{
				Lb[i]=i;
				sz[++p]=1;
				id[i]=p;
			}
		}
		for(int i=n;i>=1;i--){
			if(a[i]==a[i+1]){
				Rb[i]=Rb[i+1];
			}else{
				Rb[i]=i;
			}
		}
		int x,y,ans;
		init();
		while(Q--){
			ans=0;
			scanf("%d%d",&x,&y);
			if(x>y)swap(x,y);
			if(a[x]==a[y]){
				ans=y-x+1;
				printf("%d\n",ans);
				continue;
			}
			ans=max(Rb[x]-x+1,y-Lb[y]+1);
			int L=id[x]+1,R=id[y]-1;
			if(L==R){
				ans=max(ans,sz[L]);
			}else if(L<R){
				ans=max(ans,Query(L,R));
			}
			printf("%d\n",ans);
		}
	}
    return 0;
}
