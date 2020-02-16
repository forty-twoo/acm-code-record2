/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2020-02-16 21:34:35
 * @Description: 贪心+树上选点使得树上其他关键点到此点的距离和最短+阶乘预处理
 * @Source: https://codeforces.com/problemset/problem/1292/D
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f
#define pb push_back
#define pf push_front
const double eps=1e-5;
const int MAX=5e3+10;
const int MAXN=5e5+10;
const int MOD=20071027;
typedef long long ll;
using namespace std;
int n,x,v[MAX];
int f[MAX][MAX],maxd[MAX],sz[MAX];
const int N=5e3;

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		v[x]++;
	}
	for(int i=1;i<=N;i++){
		int p=i;
		for(int j=2;j<=i;j++){
			f[i][j]=f[i-1][j];
			while(p%j==0){
				f[i][j]+=1;p/=j;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=N;i++){
		if(!v[i]){
			maxd[i]=1;continue;
		}
		for(int j=1;j<=i;j++){
			if(f[i][j]){
				maxd[i]=j;
				ans+=1ll*f[i][j]*v[i];
			}
		}
	}
	while(1){
		mst(sz,0);
		for(int i=1;i<=N;i++){
			sz[maxd[i]]+=v[i];
		}
		int maxx=0,pd;
		for(int i=1;i<=N;i++){
			if(maxx<sz[i]){
				maxx=sz[i];
				pd=i;
			}
		}
		if(pd==1)break;
		ll tmp=ans-maxx+n-maxx;
		if(tmp>=ans)break;
		ans=tmp;
		for(int i=1;i<=N;i++){
			if(maxd[i]!=pd)maxd[i]=1;
			if(maxd[i]==1)continue;
			f[i][pd]--;
			while(!f[i][maxd[i]] && maxd[i]>1)maxd[i]--;
		}
	}
	printf("%lld\n",ans);


    return 0;
}
