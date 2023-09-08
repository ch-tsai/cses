#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#define int long long
#define pii pair<int, int>
#define ff first
#define ss second
#define MAXN 500
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
	vector<vector<int>> adj2(n+1);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
		adj[a].push_back(b);
		adj2[b].push_back(a);
	}
	priority_queue<pii> ijk;
	ijk.push({0, 1});
	vector<int> dis(n+1, INT32_MAX);
	vector<int> dis2(n+1, INT32_MAX);
	vector<int> vis(n+1, 0);
	vector<int> vis2(n+1, 0);
	dis[1]=0;
	dis2[n]=0;
	while(!ijk.empty()){
		pii tmp=ijk.top();ijk.pop();
		int tpp=tmp.ss;
		if(vis[tpp]) continue;
		vis[tpp]=1;
		for(int x:adj[tpp]){
			if(dis[x]<=dis[tpp]-1) continue;
			dis[x]=dis[tpp]-1;
			ijk.push({dis[x], x});
		}
	}
	ijk.push({0, n});
	while(!ijk.empty()){
		pii tmp=ijk.top();ijk.pop();
		int tpp=tmp.ss;
		if(vis2[tpp]) continue;
		vis2[tpp]=1;
		for(int x:adj2[tpp]){
			if(dis2[x]<=dis2[tpp]-1) continue;
			dis2[x]=dis2[tpp]-1;
			ijk.push({dis2[x], x});
		}
	}
	int mini=INT32_MAX, ind;
	for(int i=1; i<=n; i++){
		if(dis[i]<1&&dis2[i]<1){
			if(dis[i]+dis2[i]<mini){
				mini=dis[i]+dis2[i];
				ind=i;
			}
		}
	}
	if(mini==INT32_MAX){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	deque<int> dq;
	dq.push_back(ind);
	int cur=ind;
	cout<<dis[cur]<<' '<<dis2[cur];
	return 0;
	while(cur!=1){
		if(cur==1) break;
		for(int x:adj2[cur]){
			if(dis[cur]==dis[x]-1){
				dq.push_front(x);
				cur=x;
				break;
			}
		}
		if(cur==1) break;
	}
	cur=ind;
	while(cur!=n){
		if(cur==n) break;
		for(int x:adj[cur]){
			if(dis2[cur]==dis2[x]-1){
				dq.push_back(x);
				cur=x;
				break;
			}
		}
		if(cur==n) break;
	}
	cout<<dq.size()<<'\n';
	for(int x:dq){
		cout<<x<<' ';
	}

}
