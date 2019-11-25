/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2019-11-25 14:42:10
 * @Description: 贪心
 * @Source: https://vjudge.net/problem/UVA-11134
 */
#include<iostream>
#include<queue>
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
#define pb push_back
const double eps=1e-5;
const int MAX=1e4+10;
const int MOD=998244353;
typedef long long ll;
using namespace std;
int n;
int vis[MAX];
struct Node{
	int l,r,id;
	bool operator<(const Node &x)const{
		if(r!=x.r)
			return r<x.r;
		return l>x.l;
	}
}col[MAX],row[MAX];
int ansx[MAX],ansy[MAX];
int main(){
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
	while(~scanf("%d",&n) && n){
		bool f=true;
		int x1,x2,y1,y2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			col[i]={y1,y2,i};
			row[i]={x1,x2,i};
		}
		sort(col+1,col+1+n);
		sort(row+1,row+1+n);
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++){
			bool ok=false;
			for(int j=col[i].l;j<=col[i].r;j++){
				if(vis[j])continue;
				ok=true;vis[j]=1;
				ansy[col[i].id]=j;
				break;
			}
			if(!ok){
				f=false;break;
			}
		}
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++){
			bool ok=false;
			for(int j=row[i].l;j<=row[i].r;j++){
				if(vis[j])continue;
				ok=true;vis[j]=1;
				ansx[row[i].id]=j;
				break;
			}
			if(!ok){
				f=false;break;
			}
		}
		if(!f){
			puts("IMPOSSIBLE");
			continue;
		}
		for(int i=1;i<=n;i++){
			printf("%d %d\n",ansx[i],ansy[i]);
		}
	}
	return 0;
}
