/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2019-11-08 13:30:04
 * @Description: 转为矩阵乘法+线段树维护
 * @Source: https://codeforces.com/contest/1252/problem/K
 */
#include<bits/stdc++.h>
#define mst(a,x) memset(a,x,sizeof(a))
#define INF 0x3f3f3f3f
typedef long long ll;
typedef long double ldle;
using namespace std;
const int MAX = 1e5+10;
const int MAXN = 1e6+10;
const int MOD = 1e9+7;
int n,Q;
char str[MAX];
struct Mat{
	ll a[3][3];
};
Mat Matmul(Mat A,Mat B){
	Mat ans;
	mst(ans.a,0);
	for(int i=1;i<=2;i++){
		for(int k=1;k<=2;k++){
			for(int j=1;j<=2;j++){
				ans.a[i][j]=(ans.a[i][j]+A.a[i][k]*B.a[k][j]%MOD)%MOD;
			}
		}
	}
	return ans;
}
Mat initmat(){
	Mat ans;
	for(int i=1;i<=2;i++){
		ans.a[i][i]=1;
	}
	ans.a[1][2]=ans.a[2][1]=0;
	return ans;
}
struct SEGT{
#define lc rt<<1
#define rc rt<<1|1
#define lson lc,l,mid
#define rson rc,mid+1,r
	Mat mat[MAX<<2];int lazy[MAX<<2];
	void pushup(int rt){
		mat[rt]=Matmul(mat[lc],mat[rc]);
	}
	void swapp(int rt){
		ll x=mat[rt].a[2][1];
		ll y=mat[rt].a[2][2];
		mat[rt].a[2][1]=mat[rt].a[1][2];
		mat[rt].a[2][2]=mat[rt].a[1][1];
		mat[rt].a[1][1]=y;
		mat[rt].a[1][2]=x;
	}
	void pushdown(int rt){
		if(lazy[rt]){
			swapp(lc);swapp(rc);
			lazy[lc]^=1;
			lazy[rc]^=1;
			lazy[rt]^=1;
		}
	}
	void build(int rt,int l,int r){
		if(l==r){
			if(str[l]=='A'){
				mat[rt].a[1][1]=1;
				mat[rt].a[1][2]=0;
				mat[rt].a[2][1]=1;
				mat[rt].a[2][2]=1;
			} else{
				mat[rt].a[1][1]=1;
				mat[rt].a[1][2]=1;
				mat[rt].a[2][1]=0;
				mat[rt].a[2][2]=1;
			}
			return ;
		}
		int mid=(l+r)>>1;
		build(lson);build(rson);
		pushup(rt);
	}
	void change(int rt,int l,int r,int L,int R){
		if(L<=l && r<=R){
			swapp(rt);
			lazy[rt]^=1;
			return;
		}
		int mid=(l+r)>>1;
		pushdown(rt);
		if(L<=mid)change(lson,L,R);
		if(R>mid)change(rson,L,R);
		pushup(rt);
	}
	Mat getquery(int rt,int l,int r,int L,int R){
		Mat ans=initmat();
		if(L<=l && r<=R){
			return mat[rt];
		}
		int mid=(l+r)>>1;
		pushdown(rt);
		if(L<=mid){
			ans=Matmul(ans,getquery(lson,L,R));
		}
		if(R>mid){
			ans=Matmul(ans,getquery(rson,L,R));
		}
		pushup(rt);
		return ans;
	}
}T;
int main(){
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
	scanf("%d%d",&n,&Q);
	scanf("%s",str+1);
	T.build(1,1,n);
	while(Q--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int L,R;
			scanf("%d%d",&L,&R);
			T.change(1,1,n,L,R);
		} else{
			int L,R;ll A,B;
			scanf("%d%d%lld%lld",&L,&R,&A,&B);
			Mat X=T.getquery(1,1,n,L,R);
			ll x=A*X.a[1][1]%MOD;
			x=(x+B*X.a[2][1])%MOD;
			ll y=A*X.a[1][2]%MOD;
			y=(y+B*X.a[2][2])%MOD;
			printf("%lld %lld\n",x,y);
		}
	}
	return 0;
}
