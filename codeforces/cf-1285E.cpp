/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime: 2020-02-18 19:44:46
 * @Description: 删除一个区间使得剩下区间的并集数最多
 * @Source: https://codeforces.com/contest/1285/problem/E
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define INF 0x3f3f3f3f
#define pb push_back
#define pf push_front
const double eps=1e-5;
const int MAX=2e5+10;
const int MAXN=4e5+10;
const int MOD=20071027;
typedef long long ll;
using namespace std;
typedef pair<int,int> PI;
int n;
vector<PI> V;
set<int> S;
int cnt[MAX];

int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	int ks;
	scanf("%d",&ks);
	while(ks--){
		scanf("%d",&n);
		for(int i=0;i<=n+1;i++)cnt[i]=0;
		V.clear();S.clear();
		int x,y,tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			V.pb(make_pair(x,-i));
			V.pb(make_pair(y,i));
		}
		sort(V.begin(),V.end());
		for(auto t:V){
			int sid=abs(t.second);
			if(t.second<0){
				if(S.empty())cnt[sid]--;
				S.insert(sid);
			}else{
				S.erase(sid);
				if(S.empty())cnt[sid]--;
			}
			if(S.empty())tot++;
			if(S.size()==1)cnt[*S.begin()]++;
		}
		int ext=-1;
		for(int i=1;i<=n;i++)ext=max(ext,cnt[i]);
		printf("%d\n",tot+ext);


	}

    return 0;
}
