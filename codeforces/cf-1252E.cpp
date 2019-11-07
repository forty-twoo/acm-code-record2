/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2019-11-07 23:28:12
 * @Description: 贪心求字典序最小的有相同趋势的序列
 * @Source: https://codeforces.com/contest/1252/problem/E
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
int n,L,R,k,a[MAX];
int low[MAX],hig[MAX];
int b[MAX];
int main(){
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&L,&R,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	bool flag=true;
	low[n]=L,hig[n]=R;
	for(int i=n-1;i>=1;i--){
		if(a[i]<a[i+1]){
			low[i]=max(L,low[i+1]-k);
			hig[i]=min(R,hig[i+1]-1);
		} else if(a[i]==a[i+1]){
			low[i]=low[i+1];
			hig[i]=hig[i+1];
		} else{
			low[i]=max(L,low[i+1]+1);
			hig[i]=min(R,hig[i+1]+k);
		}
		if(low[i]>hig[i]){
			flag=false;break;
		}
	}
	if(!flag){
		puts("-1");
		return 0;
	}
	b[1]=low[1];
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			b[i]=max(b[i-1]+1,low[i]);
		} else if(a[i]==a[i-1]){
			b[i]=b[i-1];
		} else{
			b[i]=max(low[i],b[i-1]-k);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	puts("");
	return 0;
}
