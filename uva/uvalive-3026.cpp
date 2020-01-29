/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-29 22:06:11
 * @Description: kmp求循环节
 * @Source: https://vjudge.net/problem/UVALive-3026
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=1e6+10;
const int MAXN=5e6+10;
const int MOD=20071027;
typedef long long ll;
using namespace std;
int n;
char a[MAX];
int nxt[MAX];

void calnxt(){
	nxt[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j>0 && a[i]!=a[j+1])j=nxt[j];
		if(a[i]==a[j+1])j++;
		nxt[i]=j;
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	int cks=0;
	while(~scanf("%d",&n) && n){
		mst(nxt,0);
		scanf("%s",a+1);
		printf("Test case #%d\n",++cks);
		calnxt();
		for(int i=2;i<=n;i++){
			int d=i-nxt[i];
			if(i%d==0 && i/d>1){
				printf("%d %d\n",i,i/d);
			}
		}
		puts("");
	}


    return 0;
}
