/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-02-03 15:18:50
 * @Description: 同余+欧拉函数
 * @Source: https://ac.nowcoder.com/acm/contest/1023/A
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=4e3+10;
const int MAXN=5e6+10;
const int MOD=20071027;
typedef long long ll;
using namespace std;
ll l;
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
ll phi(ll n){
	ll ans=n;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0)n/=i;
		}
	}
	if(n>1)ans=ans/n*(n-1);
	return ans;
}
ll qpow(ll a,ll p,ll mod){
	ll res=1;
	while(p){
		if(p&1){
			res=res*a%mod;
		}
		a=a*a%mod;
		p>>=1;
	}
	return res;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	int cks=0;
	while(~scanf("%lld",&l) && l){
		ll d=gcd(l,8);
		ll v=9ll*l/d;
		ll p=phi(v);
		ll ans=1e9;
		for(int i=1;i<=sqrt(p);i++){
			if(p%i==0){
				if(qpow(10,i,v)==1)
					ans=min(ans,(ll)i);
				if(p/i!=i ){
					if(qpow(10,p/i,v)==1)
						ans=min(ans,(ll)(p/i));
				}
			}
		}
		if(ans==1e9)ans=0;
		printf("Case %d: %lld\n",++cks,ans);
	}
    return 0;
}
