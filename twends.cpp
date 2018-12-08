//http://www.spoj.com/problems/TWENDS

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
#include <iterator>
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
#define pb 				push_back


typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef pair < ll , ll > p2 ;
typedef vector < vector < ll > > vv ;
typedef vector < ll > vll ;

int n, g = 1;
int dp [1000][1000];

int backtrack_optimum(int* cards, int i, int j, int acc){
	if(dp[i][j] != -1)
		return dp[i][j];
	if(j - i > 1 || i-j > 1){
		int t1j = j, t1i = i + 1, t2j = j - 1, t2i = i;
		if(cards[j] > cards[i+1])
			--t1j;
		else
			t1i++;
		if(cards[i] >= cards[j-1])
			++t2i;
		else
			t2j--;
	int t1 = backtrack_optimum(cards, t1i, t1j, acc+cards[i]);
	int t2 = backtrack_optimum(cards, t2i, t2j, acc+cards[j]);
	int t  = dp[i][j] = max(t1, t2);
	return t;
	}
		int t = max(cards[i], cards[j]) + acc;
		return t;
}

int solve(int* cards){
	int sum = 0;
	for(int i = 0; i < n; ++i)
		sum+=cards[i];
	int t = backtrack_optimum(cards, 0, n-1, 0);
	return t - (sum - t);
}


int main(int argc, char const *argv[]){

	// ios_base::sync_with_stdio(false); // use this if using iostream. DON'T USE WITH PRINTF!!!
	// cin.tie(0), cout.tie(NULL);

	// freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


	while(scanf("%d", &n) && n>0){
		int cards[n];
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < n; ++i)
			scanf("%d", &cards[i]);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", g++, solve(cards));
	}
	return 0;
}
