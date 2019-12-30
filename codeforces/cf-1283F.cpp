/*
 * @Don't panic: Allons-y!
 * @Author: forty-twoo
 * @LastEditTime : 2019-12-30 17:56:47
 * @Description: 贪心 构造
 * @Source: https://codeforces.com/contest/1283/problem/F
 */
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define prique priority_queue
#define pb push_back
const double eps=1e-5;
const int MAX=2e5+10;
const int MOD=998244353;
typedef long long ll;
using namespace std;
int n,a[MAX],vis[MAX];
int ans[MAX];
int mp[MAX];
int maxv[MAX];
set<int> S;
 
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d",&a[i]);
		vis[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		mp[i]=maxv[i]=i;
		if(!vis[i]){
			S.insert(i);
		}
	}
	int rt=a[1];
	for(int i=n-1;i>=1;i--){
		auto ptr=S.begin();
		ans[i]=mp[*ptr];
		vis[a[i]]--;
		maxv[a[i]]=max(maxv[a[i]],maxv[ans[i]]);
		mp[*ptr]=a[i];
		S.erase(*ptr);
		if(vis[a[i]]==0){
			S.insert(maxv[a[i]]);
		}
	}
 
	printf("%d\n",rt);
	for(int i=1;i<n;i++){
		printf("%d %d\n",a[i],ans[i]);
	}
 
    return 0;
}
 
