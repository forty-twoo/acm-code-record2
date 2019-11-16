/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2019-11-16 13:43:06
 * @Description: 转化为区间覆盖
 * @Source: https://vjudge.net/problem/UVALive-3905
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
const int MAX=2e5+10;
const int MOD=998244353;
typedef long long ll;
using namespace std;
int n,w,h;
struct Node{
	int op;
	double t;
	bool operator<(const Node &A)const{
		if(t==A.t){
			return op>A.op;
		}else return t<A.t;
	}
}node[MAX];


int main(){
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
	int ks;
	scanf("%d",&ks);
	while(ks--){
		scanf("%d%d",&w,&h);
		scanf("%d",&n);
		int x,y,a,b;
		int cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&x,&y,&a,&b);
			/***************/
			if(a==0){
				if(x<=0 || x>=w)continue;
			}else if(a<0){
				if(x<=0)continue;
			}else if(a>0){
				if(x>=w)continue;
			}
			if(b==0){
				if(y<=0 || y>=h)continue;
			}else if(b<0){
				if(y<=0)continue;
			}else{
				if(y>=h)continue;
			}
			/****************/
			double L=0,R=1e9;
			if(x<=0){
				L=max(L,-(double)x/(double)a);
				R=min(R,(double)(w-x)/(double)a);
			}else if(x<w){
				if(a<0){
					R=min(R,-(double)(x)/(double)a);
				}else if(a>0){
					R=min(R,(double)(w-x)/(double)a);
				}
			}else{
				
				L=max(L,-(double)(x-w)/(double)a);
				R=min(R,-(double)x/(double)a);
			}
			if(y<0){
				L=max(L,-(double)y/(double)b);
				R=min(R,(double)(h-y)/(double)b);
			}else if(y<h){
				if(b<0){
					R=min(R,-(double)y/(double)b);
				}else if(b>0){
					R=min(R,(double)(h-y)/(double)b);
				}
			}else{
				L=max(L,-(double)(y-h)/(double)b);
				R=min(R,-(double)y/(double)b);
			}
			if(L>=R)continue;
			// cout<<L<<"  "<<R<<endl;
			node[++cnt]={1,L};
			node[++cnt]={2,R};
		}
		sort(node+1,node+1+cnt);
		int sum=0,ans=0;
		for(int i=1;i<=cnt;i++){
			if(node[i].op==1){
				//cout<<"L"<<" ";
				sum++;
			}else{
				//cout<<"R"<<" ";
				sum--;
			}
			ans=max(ans,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}
