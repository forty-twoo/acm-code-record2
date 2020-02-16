/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2020-02-16 22:59:26
 * @Description: 思维+多源bfs
 * @Source: https://codeforces.com/contest/1301/problem/F
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f
#define pb push_back
#define pf push_front
const double eps=1e-5;
const int MAX=1e3+5;
const int MAXN=5e5+10;
const int MOD=20071027;
typedef long long ll;
using namespace std;
int n,m,k,c,gra[MAX][MAX];
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
typedef pair<int,int> PI;
vector<PI> V[50];
int dis[MAX][MAX][41],vis[MAX][MAX];
int gcol[50];
struct Node{
	int x,y,stp;
};
queue<Node> Q;
void bfs(int c){
	while(Q.size()){
		Node cur=Q.front();Q.pop();
		if(!gcol[gra[cur.x][cur.y]]){
			for(auto t:V[gra[cur.x][cur.y]]){
				if(!vis[t.first][t.second]){
					vis[t.first][t.second]=1;
					dis[t.first][t.second][c]=cur.stp+1;
					Node tmp={t.first,t.second,cur.stp+1};Q.push(tmp);
				}
			}
			gcol[gra[cur.x][cur.y]]=1;
		}
		for(int i=1;i<=4;i++){
			int xx=cur.x+dx[i];
			int yy=cur.y+dy[i];
			if(vis[xx][yy] || xx>n || xx<1 || yy>m || yy<1)continue;
			vis[xx][yy]=1;dis[xx][yy][c]=cur.stp+1;
			Node tmp={xx,yy,cur.stp+1};Q.push(tmp);
		}
	}
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&c);
			gra[i][j]=c;
			V[c].pb(make_pair(i,j));
		}
	}
	mst(dis,INF);
	for(int i=1;i<=k;i++){
		if(!V[i].size())continue;
		mst(vis,0);mst(gcol,0);
		gcol[i]=1;
		while(Q.size())Q.pop();
		for(auto t:V[i]){
			Node cur={t.first,t.second};
			dis[t.first][t.second][i]=0;
			vis[t.first][t.second]=1;
			Q.push(cur);
		}
		bfs(i);
	}
	int r1,c1,r2,c2,q;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		int ans=abs(r1-r2)+abs(c1-c2);
		for(int i=1;i<=k;i++){
			//cout<<i<<" : "<<dis[r1][c1][i]<< " + "<<dis[r2][c2][i]<<endl;
			ans=min(ans,dis[r1][c1][i]+dis[r2][c2][i]+1);
		}
		printf("%d\n",ans);
	}

    return 0;
}
