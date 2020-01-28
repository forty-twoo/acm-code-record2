/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-28 23:24:46
 * @Description: Trie+计数
 * @Source: https://vjudge.net/problem/UVA-11732
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=3e5+10; 
const int MAXN=5e6+10;
const int MOD=20071027;
typedef long long ll;
using namespace std;
int n,tot=64;
char tmp[1010];
char str[1010];

int idx(char c){
	if(c>='0' && c<='9')return c-'0'+1;
	if(c>='a' && c<='z')return c-'a'+1+10;
	if(c>='A' && c<='Z')return c-'A'+1+10+26;
	if(c=='#')return 64;
}
struct Trie{
	int ch[MAXN][70];
	int num[MAXN];
	int sz;
	int wordnum;
	void init(){
		sz=0;mst(num,0);mst(ch[0],0);
		wordnum=0;
	}
	void insert(char *s,int v){
		int u=0,len=strlen(s);
		for(int i=0;i<len;i++){
			int id=idx(s[i]);
			if(!ch[u][id]){
				++sz;
				mst(ch[sz],0);
				ch[u][id]=sz;
			}
			u=ch[u][id];
			num[u]+=2;
		}
		wordnum++;
	}
	ll query(char *s){
		ll cnt=0;
		int u=0,len=strlen(s);
		for(int i=0;i<len;i++){
			int id=idx(s[i]);
			if(ch[u][id]){
				int x=ch[u][id];
				cnt+=num[x];
				//分叉点
				for(int j=1;j<=tot;j++){
					if(ch[u][j] && j!=id){
						cnt+=num[ch[u][j]]/2;
					}
				}
				u=x;
			}else{
				if(i==0){
					return wordnum;
				}else{
					for(int j=1;j<=tot;j++){
						if(ch[u][j]){
							cnt+=num[ch[u][j]]/2;
						}
					}
					return cnt;
				}
			}
		}
		return cnt;
	}
}T;

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	int cks=0;
	while(~scanf("%d",&n) && n){
		T.init();
		ll ans=0;
		ll pre=0;
		for(int i=1;i<=n;i++){
			scanf("%s",str);
			int len=strlen(str);
			str[len]='#';
			str[len+1]='\0';
			ans+=T.query(str);
			pre=ans;
			T.insert(str,i);
		}
		printf("Case %d: %lld\n",++cks,ans);
	}
    return 0;
}
