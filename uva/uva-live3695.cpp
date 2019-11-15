/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2019-11-15 22:02:12
 * @Description: 求矩形边界上能有的最多点数(离散化+前缀和)
 * @Source: https://vjudge.net/problem/UVALive-3695
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
const int MAX=2e2+10;
const int MOD=998244353;
typedef long long ll;
using namespace std;
int n;
struct Node{
	int x,y;
}node[MAX];
vector<Node> Vx[MAX],Vy[MAX];
int dc[MAX],tot=0;
int line[MAX][MAX],row[MAX][MAX];
int main(){
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
	int cks=0;
	while(~scanf("%d",&n) && n){
		tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&node[i].x,&node[i].y);
			dc[++tot]=node[i].x,dc[++tot]=node[i].y;
		}
		sort(dc+1,dc+1+tot);
		tot=unique(dc+1,dc+1+tot)-(dc+1);
		for(int i=1;i<=tot;i++){
			Vx[i].clear();Vy[i].clear();
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int x=lower_bound(dc+1,dc+1+tot,node[i].x)-dc;
			Vx[x].push_back(node[i]);
			int y=lower_bound(dc+1,dc+1+tot,node[i].y)-dc;
			Vy[y].push_back(node[i]);
		}
		mst(row,0);mst(line,0);
		for(int i=1;i<=tot;i++){
			ans=max(ans,(int)Vx[i].size());
			ans=max(ans,(int)Vy[i].size());
			for(auto nd:Vx[i]){
				int y=lower_bound(dc+1,dc+1+tot,nd.y)-dc;
				line[i][y]++;
			}
			for(int j=1;j<=tot;j++)line[i][j]+=line[i][j-1];
		}
		for(int i=1;i<=tot;i++){
			for(auto nd:Vy[i]){
				int x=lower_bound(dc+1,dc+1+tot,nd.x)-dc;
				row[x][i]++;
			}
			for(int j=1;j<=tot;j++)row[j][i]+=row[j-1][i];
		}
		for(int i=1;i<=tot;i++){
			if(!Vx[i].size())continue;
			for(int j=i+1;j<=tot;j++){
				if(!Vx[j].size())continue;
				int maxx=-INF,sum;
				bool ss=true;
				for(int t=1;t<=tot;t++){
					if(row[j][t]-row[i-1][t]==0)continue;
					if(!ss)
						ans=max(ans,row[j-1][t]-row[i][t]+line[i][t]+line[j][t]+maxx);
					ss=false;
					int tmp_ans=row[j-1][t]-row[i][t]+line[i][t]+line[j][t]+maxx;
					maxx=max(maxx,row[j-1][t]-row[i][t]-line[i][t-1]-line[j][t-1]);
				}
			}
		}
		printf("Case %d: %d\n",++cks,ans);
	}
	return 0;
}
