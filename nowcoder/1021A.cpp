/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-14 00:21:17
 * @Description: 区间筛素数
 * @Source: https://ac.nowcoder.com/acm/contest/1021/A
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=7e4+10;
const int MAXN=1e6+10;
const int MOD=1e9;
typedef long long ll;
using namespace std;
ll L,R;
ll v[MAX],pri[MAX],cnt;
int vis[MAXN];
void init(){
	for(int i=2;i<MAX;i++){
		if(v[i]==0){
			v[i]=i;
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt;j++){
			ll cur=pri[j]*i;
			if(cur>=MAX || v[i]<pri[j])break;
			v[cur]=pri[j];
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	init();
	while(~scanf("%lld%lld",&L,&R)){
		mst(vis,0);
		if(L==1)vis[0]=1;
		for(int i=1;i<=cnt;i++){
			ll cur=pri[i]*pri[i];
			if(cur>R)break;
			ll l=ceil((double)L/(double)pri[i]);
			ll r=floor((double)R/(double)pri[i]);
			for(ll j=l;j<=r;j++){
				if(j==1)continue;
				vis[pri[i]*j-L]=1;
			}
		}
		int maxx=0,minn=1000000;
		int max1,max2,min1,min2;
		int lst=-1;
		for(int i=0;i<=R-L;i++){
			if(vis[i]==0){
				if(lst==-1){
					lst=i;
				}else{
					if(i-lst>maxx){
						maxx=i-lst;max1=lst,max2=i;
					}
					if(i-lst<minn){
						minn=i-lst;min1=lst,min2=i;
					}
					lst=i;
				}
			}
		}
		if(maxx==0){
			puts("There are no adjacent primes.");
		}else{
			printf("%d,%d are closest, %d,%d are most distant.\n",min1+L,min2+L,max1+L,max2+L);
		}
	}
    return 0;
}
