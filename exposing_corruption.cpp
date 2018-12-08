	#include <iostream>
	#include <fstream>
	#include <algorithm>
	#include <set>
	#include <string.h>
	#include <map>
	#include <list>
	#include <iomanip>
	#include <cstdio>
	#include <cmath>
	#include <string>
	#include <vector>
	#include <queue>
	#include <stack>
	#include <complex>
	#include <sstream>
	#include <numeric>
	#include <utility>
	#include <functional>
	#include <stdio.h>
	#include <assert.h>
	#include <memory.h>
	#include <bitset>
	#include <bits/stdc++.h>
	using namespace std;

	#define all(v)			((v).begin(),(v).end())
	#define sz(v)			((ll)(v).size())
	#define clr(v,d)		memset((v),(d),sizeof(v))
	#define rep(i,v)		for(ll i = 0 ; i < (ll) sz(v) ; i++ )
	#define lp(i,n)			for(ll i = 0 ; i < (ll) n; i++ )
	#define lpu(i,j,n)		for(ll i = (j) ; i < (ll) n ; i++ )
	#define lpd(i,j,n)		for(ll i = (j) ; i >= (ll) n ; i-- )
	#define MP(a,b)  		make_pair(a,b)
	#define dbug(x) 		cout<<"x = "<<x<<endl
	#define eps 			(1e-9)
	#define pie  			acos(-1)
	#define INF  			LLONG_MAX

	typedef long long ll;
	typedef unsigned long long ull;
	typedef double dd;
	typedef pair < ll , ll > p2 ;
	typedef vector < vector < ll > > vv ;
	typedef vector < ll > vll ;

	int D, P, R, B;
	list<int> d_adj[101], p_adj[101];
	int d[101], p[101], d_vis[101], p_vis[101];

	void dfs(int can, int there, int isDSP, int *cnt, int *cost){
		if(isDSP && d_vis[can])
			return;
		if(!isDSP && p_vis[can])
			return;
		d_vis[can] = isDSP ? 1 : d_vis[can];
		p_vis[can] = isDSP ? p_vis[can] : 1;
		*cost 	  += isDSP ? d[can]: p[can];
		*cnt   	   = there ? *cnt + 1 : *cnt - 1;
		list<int> adj = isDSP ? d_adj[can] : p_adj[can];
		for(list<int>::iterator it = adj.begin(); it != adj.end(); ++it)
			dfs(*it, !there, !isDSP, cnt, cost);
	}

	int dp(vector<pair<int, int>> candidates){
		int dp[10001];
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < candidates.size(); ++i) {
			int cnt = candidates[i].first, cost = candidates[i].second;
			for (int j = B; j >= cost; --j)
				dp[j] = max(dp[j], dp[j-cost]+cnt);
		}

		 return *max_element(dp, dp + sizeof(dp)/4);

	}

	int DSP(){
		vector<pair<int, int>> candidates;
		memset(d_vis, 0, sizeof(d_vis));
		memset(p_vis, 0, sizeof(p_vis));

		for(int i = 0; i < P; ++i){
			if(!p_vis[i]){
				int cnt = 0, cost = 0;
				dfs(i, 1, 0, &cnt, &cost);
				candidates.push_back(make_pair(cnt, cost));
			}
		}

		return dp(candidates) + D;
	}

	int PPP(){
		vector<pair<int, int>> candidates;
		memset(d_vis, 0, sizeof(d_vis));
		memset(p_vis, 0, sizeof(p_vis));

		for(int i = 0; i < D; ++i){
			if(!d_vis[i]){
				int cnt = 0, cost = 0;
				dfs(i, 1, 1, &cnt, &cost);
				candidates.push_back(make_pair(cnt, cost));
			}
		}

		return dp(candidates) + P;
	}

	int main(int argc, char const *argv[]){

		// ios_base::sync_with_stdio(false); // use this if using iostream. DON'T USE WITH PRINTF!!!
		// cin.tie(0), cout.tie(NULL);

		// freopen("input.txt", "r", stdin);
	    // freopen("output.txt", "w", stdout);

		// while(!cin.eof()){
		while (scanf("%d %d %d %d", &D, &P, &R, &B) == 4){
			for(int i = 0; i < D; ++i){
				cin >> d[i];
				d_adj[i].clear();
			}
			for(int i = 0; i < P; ++i){
				cin >> p[i];
				p_adj[i].clear();
			}
			for(int i = 0; i < R; ++i){
				int d, p;
				cin >> d >> p;
				--d; --p;
				d_adj[d].push_back(p);
				p_adj[p].push_back(d);
			}

			cout << DSP() << ' ' << PPP() << '\n';
		}

		return 0;
	}
