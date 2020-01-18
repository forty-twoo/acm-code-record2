/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-18 21:29:03
 * @Description: BIT
 * @Source: https://vjudge.net/problem/UVA-1428
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define lowbit(x) (x&(-x))
#define INF 0x3f3f3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=2e4+10;
const int MAXN=1e6+10;
const int MOD=1e3;
const int N = 100000;
typedef long long ll;
using namespace std;
int n,a[MAX];
struct BIT{
	int c[N+10];
	void init(){
		mst(c,0);
	}
	void add(int x,int v){
		for(;x<=N;x+=lowbit(x)) c[x]+=v;
	}
	int ask(int x){
		int sum=0;
		for(;x;x-=lowbit(x))sum+=c[x];
		return sum;
	}
}bit1,bit2;

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	int ks;
	scanf("%d",&ks);
	while(ks--){
		bit1.init();bit2.init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=n;i>=3;i--){
			bit2.add(a[i],1);
		}
		bit1.add(a[1],1);
		ll ans=0,x,y;
		for(int i=2;i<n;i++){
			x=bit1.ask(a[i]-1);
			y=n-i-bit2.ask(a[i]);
			ans+=x*y;
			x=i-1-bit1.ask(a[i]);
			y=bit2.ask(a[i]-1);
			ans+=x*y;
			bit1.add(a[i],1);
			bit2.add(a[i+1],-1);
		}
		printf("%lld\n",ans);
	}
    return 0;
}
