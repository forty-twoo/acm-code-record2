/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2019-11-20 23:36:05
 * @Description: 贪心
 * @Source: https://vjudge.net/problem/UVA-10382
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
#define pb push_back
const double eps=1e-5;
const int MAX=1e5+10;
const int MOD=998244353;
typedef long long ll;
using namespace std;
int n,h,w;
struct Node{
	double l,r;
	bool operator<(const Node&x){
		if(l!=x.l)
			return l<x.l;
		return r>x.r;
	}
}node[MAX];
int main(){
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
	while(~scanf("%d%d%d",&n,&w,&h)){
		double p,x;
		int cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&p,&x);
			if(2*x<=(double)h)continue;
			double len=sqrt(x*x-h*h/4.0);
			node[++cnt].l=max(0.0,p-len);
			node[cnt].r=min((double)w,p+len);
		}
		sort(node+1,node+1+cnt);
		if(node[1].l>0){
			puts("-1");
			continue;
		}
		double lst=node[1].r;
		int ans=1;
		bool f=0;
		for(int i=2;i<=cnt;){
			if(lst>=(double)w){
				f=1;
				break;
			}
			if(node[i].l>lst){
				f=0;break;
			}
			int tmp=i;double maxx=lst;
			for(;tmp<=cnt;tmp++){
				if(node[tmp].l>lst){
					break;
				}
				maxx=max(maxx,node[tmp].r);
			}
			i=tmp;lst=maxx;ans++;
			if(lst>=(double)w){
				f=1;
				break;
			}
		}
		if(!f)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
