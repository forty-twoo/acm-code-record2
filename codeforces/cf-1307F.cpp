 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2020-02-21 21:39:53
 * @Description: DSU+LCA
 * @Source: https://codeforces.com/contest/1307/problem/F
 */

#include<bits/stdc++.h>
using namespace std;
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f
#define pb push_back
#define pf push_front
const double eps=1e-5;
const int MAX=5e5+10;
const int MAXN=4e5+10;
const int MOD=20071027;
typedef long long ll;
typedef pair<int,int> PI;
/************************/

int n,k,r,u,v,q,vis[MAX],dis[MAX],fa[MAX],x,y;
int f[MAX][30],dep[MAX];
vector<int> G[MAX],V;
queue<int> Q;

int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
void Union(int x,int y){
	int fx=Find(x),fy=Find(y);
	if(fx==fy)return;
	fa[fx]=fy;
}
void dfs(int u,int ff){
	f[u][0]=ff,dep[u]=dep[ff]+1;
	for(auto v:G[u]){
		if(v==ff)continue;
		dfs(v,u);
	}
}
void init(){
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			if(dep[f[j][i-1]]<=0)continue;
			if(dep[f[j][i-1]]-(1<<(i-1))<=0)continue;
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
}
int Lca(int x,int y){
	if(x==y)return x;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
		if(x==y)return x;
	}
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int walk_k(int u,int v,int k){
	int rt=Lca(u,v);
	int dis=dep[u]+dep[v]-2*dep[rt];
	if(dep[u]-dep[rt]==k){
		return rt;
	}else if(dep[u]-dep[rt]<k){
		return walk_k(v,rt,dis-k);
	}else{
		int pt=u;
		for(int i=20;i>=0;i--){
			if(!k)break;
			if((1<<i)<=k){
				k-=(1<<i);
				pt=f[pt][i];
			}
		}
		return pt;
	}
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&k,&r);
	for(int i=1;i<n;i++){
		//!!!attension
		scanf("%d%d",&u,&v);
		G[u].pb(n+i);G[n+i].pb(u);
		G[v].pb(n+i);G[n+i].pb(v);
	}
	n*=2;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=r;i++){
		scanf("%d",&x);
		Q.push(x);dis[x]=0,vis[x]=1;
	}
	while(Q.size()){
		int u=Q.front();Q.pop();
		if(dis[u]>=k)break;
		for(auto v:G[u]){
			Union(v,u);
			if(vis[v])continue;
			vis[v]=1;dis[v]=dis[u]+1;
			Q.push(v);
		}
	}
	dfs(1,0);
	init();
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&u,&v);
		int rt=Lca(u,v);
		if(dep[u]+dep[v]-2*dep[rt]<=2*k ){
			printf("YES\n");
			continue;
		}
		int pt=walk_k(u,v,k);
		int pz=walk_k(v,u,k);
		if(Find(pt)==Find(pz)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
    return 0;
}
