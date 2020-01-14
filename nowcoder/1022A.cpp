/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-14 14:48:50
 * @Description: 反素数
 * @Source: https://ac.nowcoder.com/acm/contest/1022/A
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
int pri[12]={0,2,3,5,7,11,13,17,19,23,29,31};
int anscnt=2;
ll ansval=INF,n;
void dfs(int cid,ll sum,int cnt){
	if(cnt>anscnt){
		ansval=sum,anscnt=cnt;
	}
	if(cnt==anscnt){
		ansval=min(ansval,sum);
	}
	for(int i=1;;i++){
		ll mi=pow(pri[cid],i);
		if(mi>n || mi*sum>n)return;
		dfs(cid+1,sum*mi,cnt*(1+i));
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	scanf("%lld",&n);
	if(n==1){
		printf("%d\n",1);
		return 0;
	}
	dfs(1,1,1);
	printf("%lld\n",ansval);
    return 0;
}
