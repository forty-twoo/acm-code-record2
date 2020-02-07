/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-02-06 23:43:08
 * @Description: 高斯消元
 * @Source: https://ac.nowcoder.com/acm/contest/1025/A
 */

#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=20;
const int MAXN=5e6+10;
const int MOD=20071027;
typedef long long ll;
using namespace std;
double a[MAX][MAX],b[MAX],c[MAX][MAX];
int n;

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=2*(a[i][j]-a[i+1][j]);
			b[i]+=a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
		}
	}

	//高斯消元
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(fabs(c[i][j])>1e-8){
				for(int k=1;k<=n;k++){
					swap(c[j][k],c[i][k]);
				}
				swap(b[i],b[j]);
			}
		}
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			double rate=c[j][i]/c[i][i];
			for(int k=1;k<=n;k++){
				c[j][k]-=c[i][k]*rate;
			}
			b[j]-=b[i]*rate;
		}
	}
	for(int i=1;i<n;i++){
		printf("%.3f ",b[i]/c[i][i]);
	}
	printf("%.3f\n",b[n]/c[n][n]);



    return 0;
}
