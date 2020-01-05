/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2020-01-05 18:36:32
 * @Description: 扫描线
 * @Source: https://codeforces.com/contest/1284/problem/D
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f
#define pb push_back
const double eps=1e-5;
const int MAX=2e5+100;
const int MOD=998244353;
typedef long long ll;
using namespace std;
int n;
struct Node{
    int x,y1,y2,id,op;
    bool operator<(const Node&t)const{
        if(x!=t.x)
            return x<t.x;
        return op>t.op;
        
    }
}node[MAX*2];
int dc[2*MAX],tot;
struct SEGT{
#define lc rt<<1
#define rc rt<<1|1
#define lson lc,l,mid
#define rson rc,mid+1,r
    int maxv[MAX*4],lazy[MAX*4];
    void pushup(int rt){
        maxv[rt]=max(maxv[lc],maxv[rc]);
    }
    void pushdown(int rt){
        if(lazy[rt]){
            maxv[rc]+=lazy[rt];
            maxv[lc]+=lazy[rt];
            lazy[rc]+=lazy[rt];
            lazy[lc]+=lazy[rt];
            lazy[rt]=0;
        }
    }
    void insert(int rt,int l,int r,int L,int R,int x){
        if(L<=l && r<=R){
            maxv[rt]+=x;
            lazy[rt]+=x;
            return;
        }
        int mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid)insert(lson,L,R,x);
        if(R>mid)insert(rson,L,R,x);
        pushup(rt);
    }
    int query(int rt,int l,int r,int L,int R){
        int ans=0;
        if(L<=l && r<=R){
            return maxv[rt];
        }
        int mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid)
            ans=max(ans,query(lson,L,R));
        if(R>mid)
            ans=max(ans,query(rson,L,R));
        pushup(rt);
        return ans;
    }

}T;

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
    scanf("%d",&n);
    int x1,x2,y1,y2,cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
        dc[++tot]=y1,dc[++tot]=y2;
        node[++cnt]={x1,y1,y2,i,1};
        node[++cnt]={x2,y1,y2,i,-1};
    }
    sort(dc+1,dc+1+tot);tot=unique(dc+1,dc+1+tot)-(dc+1);
    sort(node+1,node+1+cnt);
    bool flg=true;
    int sum=0;
    for(int i=1;i<=cnt;i++){
        int yy1=lower_bound(dc+1,dc+1+tot,node[i].y1)-dc;
        int yy2=lower_bound(dc+1,dc+1+tot,node[i].y2)-dc;
        if(node[i].op==1){
            int qry=T.query(1,1,tot,yy1,yy2);
            if(qry!=sum){
                flg=false;
                break;
            }
            T.insert(1,1,tot,yy1,yy2,node[i].op);
        }
        sum+=node[i].op;
    }
    if(flg)puts("YES");
    else puts("NO");
    

    return 0;
}
