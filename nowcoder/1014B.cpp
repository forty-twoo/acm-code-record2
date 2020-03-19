/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2020-03-20 00:30:09
 * @Description: 填数独
 * @Source: https://ac.nowcoder.com/acm/contest/1014/B
 */
#include<bits/stdc++.h>
using namespace std;
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f
#define lowbit(x) (x&(-x))
#define pb push_back
#define pf push_front
const double eps=1e-5;
const int MAX=3e5+10;
const int MAXN=1e6+10;
const int MOD=20071027;
typedef long long ll;
typedef pair<int,int> PI;
/************************/
char str[MAX];
int gra[10][10],mp[2000];
int row[10],col[10],g[10],ones[MAX];
int gg(int x,int y){
	return (x-1)/3*3+(y-1)/3+1;
}
int getnum(int x,int y){
	return row[x]&col[y]&g[gg(x,y)];
}
bool show(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			printf("%c",gra[i][j]+'0');
		}
	}
	puts("");
	return 1;
}

bool dfs(int cnt){
	if(!cnt)return show();
	int minv=10;
	int px,py,pv=0;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if(!gra[i][j]){
				pv=ones[getnum(i,j)];
				if(pv<minv){
					minv=pv;px=i,py=j;
				}
			}
		}
	}
	for(int i=getnum(px,py);i;i=i-lowbit(i)){
		int t=mp[lowbit(i)];
		row[px]-=(1<<t);
		col[py]-=(1<<t);
		g[gg(px,py)]-=(1<<t);
		gra[px][py]=t+1;
		if(dfs(cnt-1)){
			return 1;
		}
		row[px]+=(1<<t);
		col[py]+=(1<<t);
		g[gg(px,py)]+=(1<<t);
		gra[px][py]=0;
	}
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	for(int i=0;i<(1<<9);i++){
		int cnt=0;
		for(int j=0;j<9;j++){
			if((i>>j)&1)cnt++;
		}
		ones[i]=cnt;
	}
	
	for(int i=0;i<9;i++)mp[1<<i]=i;
	while(~scanf("%s",str)){
		if(str[0]=='e')break;
		for(int i=1;i<=9;i++)row[i]=col[i]=g[i]=(1<<9)-1;
		int t=0,cnt=0;
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				if(str[t]=='.')
					gra[i][j]=0,cnt++;
				else
					gra[i][j]=str[t]-'0';
				t++;
				if(gra[i][j]!=0){
					int v=1<<(gra[i][j]-1);
					row[i]-=v;
					col[j]-=v;
					g[gg(i,j)]-=v;
				}
			}
		}
		dfs(cnt);

	}
    return 0;
}
