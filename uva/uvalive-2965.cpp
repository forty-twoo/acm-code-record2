/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2019-11-16 00:01:56
 * @Description: 折半搜索
 * @Source: https://vjudge.net/problem/UVALive-2965
 */
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<set>
#define INF 0x3f3f3f3f
#define mst(a,b) memset(a,b,sizeof(a))
const double eps=1e-5;
const int MAX=1e2;
const int MOD=998244353;
typedef long long ll;
using namespace std;
int n;
char str[MAX][MAX];
int num[MAX];
map<int,int> mp;
map<int,int> val;
int ansc=0;
int ansv;
void solve(int t,int pre,int pid,int cnt){
	if(mp[pre]<cnt){
		mp[pre]=cnt;val[pre]=pid;
	}
	if(t==n/2+1)return;
	solve(t+1,pre^num[t],pid+(1<<t),cnt+1);
	solve(t+1,pre,pid,cnt);
}
void solve2(int t,int pre,int pid,int cnt){
	if(mp.find(pre)!=mp.end()){
		if(mp[pre]+cnt>ansc){
			ansc=mp[pre]+cnt;
			ansv=val[pre]+pid;
		}
	}
	if(t==n+1)return;
	solve2(t+1,pre^num[t],pid+(1<<t),cnt+1);
	solve2(t+1,pre,pid,cnt);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
	while(~scanf("%d",&n)){
		ansv=ansc=0;mp.clear();mst(num,0);val.clear();
		for(int i=1;i<=n;i++){
			scanf("%s",str[i]+1);
		}
		for(int i=1;i<=n;i++){
			int len=strlen(str[i]+1);
			for(int j=1;j<=len;j++){
				num[i]+=(1<<(str[i][j]-'A'+1));
			}
		}
		int s=n/2;
		solve(1,0,0,0);	
		solve2(s+1,0,0,0);
		printf("%d\n",ansc);
		bool f=true;
		for(int i=1;i<=n;i++){
			if((ansv>>(i))&1){
				if(!f)printf(" ");
				f=false;
				printf("%d",i);
			}
		}
		puts("");
	}

	return 0;
}
