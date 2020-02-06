/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-02-06 23:43:08
 * @Description: 矩阵加速递推
 * @Source: https://ac.nowcoder.com/acm/contest/1024/B
 */

#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=70;
const int MAXN=5e6+10;
const int MOD=20071027;
typedef long long ll;
using namespace std;
int n,m,t,act;
char str[20][10];
int a[MAX][MAX];
int cnt[MAX][MAX];
struct Mat{
	ll m[MAX][MAX];
}mat[MAX],pre[MAX],f;

Mat mult(Mat A,Mat B){
	Mat C;mst(C.m,0);
	for(int i=0;i<=n*m;i++){
		for(int j=0;j<=n*m;j++){
			for(int k=0;k<=n*m;k++){
				C.m[i][j]=A.m[i][k]*B.m[k][j]+C.m[i][j];
			}
		}
	}
	return C;
}

Mat qpow_mat(Mat A,int p){
	if(p==0){
		return A;
	}
	Mat res;
	mst(res.m,0);
	//res.m[0][0]=1;
	for(int i=0;i<=n*m;i++)res.m[i][i]=1;
	while(p){
		if(p&1){
			res=mult(res,A);
		}
		p>>=1;
		A=mult(A,A);
	}
	return res;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&m,&t,&act);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&a[i][j]);
		}
	}
	for(int i=0;i<act;i++){
		scanf("%s",str[i]);
	}
	f.m[0][0]=1;
	for(int k=1;k<=min(t,60);k++){
		mat[k].m[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int id=(i-1)*m+j;
				cnt[i][j]++;
				char c=str[a[i][j]][cnt[i][j]-1];
				if(c>='0'&&c<='9'){
					mat[k].m[0][id]=c-'0';
					mat[k].m[id][id]=1;
				}else{
					if(c=='N'){
						int x=(i-2)*m+j;
						mat[k].m[id][id]=0;
						if(i>1){
							mat[k].m[id][x]=1;
						}
					}else if(c=='S'){
						int x=(i)*m+j;
						mat[k].m[id][id]=0;
						if(i<n){
							mat[k].m[id][x]=1;
						}
					}else if(c=='W'){
						int x=id-1;
						mat[k].m[id][id]=0;
						if(j>1){
							mat[k].m[id][x]=1;
						}
					}else if(c=='E'){
						int x=id+1;
						mat[k].m[id][id]=0;
						if(j<m){
							mat[k].m[id][x]=1;
						}
					}else{
						mat[k].m[id][id]=0;
					}
				}
				if(cnt[i][j]==strlen(str[a[i][j]])){
					cnt[i][j]=0;
				}
			}
		}
	}


	for(int i=0;i<=60;i++){
		mst(pre[i].m,0);
		for(int j=0;j<=n*m;j++){
			pre[i].m[j][j]=1;
		}
	}
	for(int i=1;i<=min(t,60);i++){
		pre[i]=mult(pre[i-1],mat[i]);
	}
	if(t>60){
		Mat tmp=qpow_mat(pre[60],t/60);
		tmp=mult(tmp,pre[t%60]);
		f=mult(f,tmp);
	}else{
		f=mult(f,pre[t]);
	}
	ll ans=0;
	for(int i=1;i<=n*m;i++){
		ans=max(ans,f.m[0][i]);
	}
	printf("%lld\n",ans);
    return 0;
}
