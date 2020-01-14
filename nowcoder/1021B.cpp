/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-14 13:47:03
 * @Description: 阶乘的质因数分解
 * @Source: https://ac.nowcoder.com/acm/contest/1021/B
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=1e6+10;
const int MAXN=1e6+10;
const int MOD=1e9;
typedef long long ll;
using namespace std;
int n,v[MAX],cnt,pri[MAX],c[MAX],p[MAX];
void init(){
	for(int i=2;i<=n;i++){
		if(!v[i]){
			v[i]=i;pri[++cnt]=i;
		}
		for(int j=1;j<=cnt;j++){
			ll cur=(ll)pri[j]*i;
			if(v[i]<pri[j] || cur>n)break;
			v[i*pri[j]]=pri[j];
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	scanf("%d",&n);
	init();
	for(int i=1;i<=cnt;i++){
		if(pri[i]>n)break;
		ll cur=pri[i];
		c[i]=pri[i];
		for(int j=1;;j++){
			p[i]+=(n/cur);
			cur*=pri[i];
			if(cur>n)break;
		}
	}
	for(int i=1;i<=cnt;i++){
		printf("%d %d\n",c[i],p[i]);
	}

    return 0;
}
