/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-18 23:11:20
 * @Description: 模板带权并查集
 * @Source: https://vjudge.net/problem/UVA-1329
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=2e5+10;
const int MAXN=1e6+10;
const int MOD=1e3;
typedef long long ll;
using namespace std;
int ks,n,x,y;
char op[2];
int fa[MAX];
ll d[MAX];
void Union(int x,int y){
	fa[x]=y;
	d[x]+=(abs(y-x))%MOD;
}

int find(int x){
	if(fa[x]==x)return x;
	int rt=find(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=rt;
}
 
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	scanf("%d",&ks);
	while(ks--){
		scanf("%d",&n);
		for(int i=1;i<MAX;i++)fa[i]=i,d[i]=0;
		while(~scanf("%s",op) && op[0]!='O'){
			if(op[0]=='E'){
				scanf("%d",&x);
				find(x);
				printf("%lld\n",d[x]);
			}else{
				scanf("%d%d",&x,&y);
				Union(x,y);
			}
		}
	}
    return 0;
}
