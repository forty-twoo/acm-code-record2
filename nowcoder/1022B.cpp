/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-16 22:25:39
 * @Description: 整除分块
 * @Source: https://ac.nowcoder.com/acm/contest/1022/B
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
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	ll n,k,ans;
	scanf("%lld%lld",&n,&k);
	ans=n*k;
	for(int x=1,gx;x<=n;x=gx+1){
		gx=k/x ? min(k/(k/x),n):n;
		ans-=(ll)(gx-x+1)*(x+gx)*(k/x)/2;
	}
	printf("%lld\n",ans);

    return 0;
}
