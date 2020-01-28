/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-28 19:41:21
 * @Description: Trie+DP
 * @Source: https://vjudge.net/problem/UVALive-3942#author=0
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=3e5+10; 
const int MAXN=1e6+10;
const int MOD=20071027;
typedef long long ll;
using namespace std;
char str[MAX];
int n;
char a[150],b[150];
int dp[MAX];
struct Trie{
	int ch[MAXN][27];
	int val[MAXN];
	int sz;
	void init(){
		sz=0;mst(ch,0);mst(val,0);
	}
	void insert(char *s,int v){
		int u=0,len=strlen(s);
		for(int i=0;i<len;i++){
			if(!ch[u][s[i]-'a']){
				++sz;
				mst(ch[sz],0);
				val[sz]=0;
				ch[u][s[i]-'a']=sz;
			}
			u=ch[u][s[i]-'a'];
		}
		val[u]=v;
	}
}T;

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	int cks=0;
	while(scanf("%s%d",str+1,&n)==2){
		T.init();
		for(int i=1;i<=n;i++){
			scanf("%s",a);
			int len=strlen(a);
			mst(b,0);
			for(int j=0;j<len;j++)b[j]=a[len-j-1];
			T.insert(b,1);
		}
		mst(dp,0);
		int len=strlen(str+1);
		dp[0]=1;
		for(int i=1;i<=len;i++){
			int u=0,t=i;
			int c=str[i]-'a';
			while(T.ch[u][c]){
				if(T.val[T.ch[u][c]]){
					dp[i]=(dp[i]+dp[t-1])%MOD;
				}
				t--;
				if(!t)break;
				u=T.ch[u][c];
				c=str[t]-'a';
			}
		}
		printf("Case %d: %d\n",++cks,dp[len]);
	}
	
    return 0;
}
