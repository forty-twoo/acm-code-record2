/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-17 22:23:57
 * @Description: 欧拉函数 
 * @Source: https://ac.nowcoder.com/acm/contest/1022/D
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=1e4+10;
const int MAXN=1e6+10;
const int MOD=1e9;
typedef long long ll;
using namespace std;
int ks,n;
int phi[MAX],pri[MAX],v[MAX],cnt;
void init(){
    for(int i=2;i<MAX;i++){
        if(v[i]==0){
            pri[++cnt]=i;v[i]=i;phi[i]=i-1;
        }
        for(int j=1;j<=cnt;j++){
            if(v[i]<pri[j] || i*pri[j]>=MAX)break;
            v[i*pri[j]]=pri[j];
            phi[i*pri[j]]=phi[i]*(i%pri[j] ? pri[j]-1 : pri[j] );
        }
    }
}
 
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
    scanf("%d",&ks);
    int cks=0;
    init();
    while(ks--){
        ++cks;
        scanf("%d",&n);
        int ans=3;
        for(int i=2;i<=n;i++){
            ans+=2*phi[i];
        }
        printf("%d %d %d\n",cks,n,ans);
    }

    return 0;
}
