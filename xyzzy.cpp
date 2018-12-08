// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1498

#include <bits/stdc++.h>
 
using namespace std;
const int N = 101;
vector <int>adj[N];
int n;
int p[N];
bool vis[N][N * N + 1];
bool dfs(int room, int power){
	if (room < 0 || room >= N || power <= 0 || power > N * N || vis[room][power]){
		return 0;
	}
	vis[room][power] = 1;
	if (room == n - 1){
		return 1;
	}
	for (int i = 0; i < (int)adj[room].size(); i++){
		if (dfs(adj[room][i], power + p[room]))
			return 1;
	}
	return 0;
}
int main() {
	while(true){
		scanf("%d", &n);
		if (n == -1)
			break;
		memset(p, 0, sizeof p);
		memset(vis, 0, sizeof vis);
		for (int i = 0; i <= 100 ; i++)
			adj[i].clear();
 
		for (int i = 0 ;i < n ;i++){
			int x, y;
			scanf("%d %d", &p[i], &x);
 
			for (int j = 0; j < x; j++){
				scanf("%d", &y);
				adj[i].push_back(y - 1);
 
			}
		}
		bool res = dfs(0, 100);
		if (res)
			cout << "winnable\n";
		else
			cout <<"hopeless\n";
	}
	return 0;
}
 
