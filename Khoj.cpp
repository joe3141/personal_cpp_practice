//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4914
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

int probable(string a, string b){
	bool x = false;
	for(int i = 0; i < a.length(); ++i){
		if(a[i] != b[i])
			if(x)
				return 0;
			else
				x = true;
	}
	return 1;
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false); // use this if using iostream. DON'T USE WITH PRINTF!!!
	cin.tie(0), cout.tie(NULL);

	// freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);

	int T, N; vector<string> res, nums; string m, in;
	cin >> T;

	for(int t = 1; t <= T; ++t){
		cin >> N;
		cin.ignore(256, '\n');
		for(int i = 0; i < N; ++i){
			getline(cin, in);
			nums.push_back(in);
			in.clear();
		}
		getline(cin, m);
		for(int i = 0; i < sz(nums); ++i){
			if(probable(nums[i], m))
				res.push_back(nums[i]);
		}
		cout << "Case " << t << ":\n";
		for(int i = 0; i < sz(res); ++i){
			cout << res[i] << '\n';
		}
		res.clear();
		nums.clear();
		m.clear();
	}

	return 0;
}
