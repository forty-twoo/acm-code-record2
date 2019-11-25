/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2019-11-25 13:11:01
 * @Description: 对时间进行贪心+二分+优先队列check
 * @Source: https://vjudge.net/problem/UVALive-4254
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
int ks,n,Lim;
struct Node{
	int l,r,w;
}node[MAX];

struct Work{
	int r,w;
	bool operator<(const Work&x) const{
		return r>x.r;
	}
};
priority_queue<Work> Q;

bool cmp(const Node&x,const Node&y){
	return x.l<y.l;
}

bool check(int sp){
	while(Q.size())Q.pop();
	int ptr=1;
	Work work;
	for(int i=2;i<=Lim;i++){
		while(node[ptr].l<i && ptr<=n){
			work={node[ptr].r,node[ptr].w};
			Q.push(work);
			ptr++;
		}
		int all=sp;
		while(Q.size() && all>0){
			Work cur=Q.top();Q.pop();
			if(cur.r<i)return false;
			if(cur.w<=all){
				all-=cur.w;
			}else{
				work={cur.r,cur.w-all};Q.push(work);
				all=0;
			}
		}
	}
	if(ptr>n && !Q.size()){
		return true;
	}else{
		return false;
	}

}

int main(){
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
	scanf("%d",&ks);
	while(ks--){
		Lim=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&node[i].l,&node[i].r,&node[i].w);
			Lim=max(Lim,node[i].r);
		}
		sort(node+1,node+1+n,cmp);
		int l=1,r=INF;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		printf("%d\n",l);
	}

	return 0;
}
