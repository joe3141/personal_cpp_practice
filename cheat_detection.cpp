//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4922

// http://codeforces.com/problemset/problem/131/A

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
#define MAX				50000

typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef pair < ll , ll > p2 ;
typedef vector < vector < ll > > vv ;
typedef vector < ll > vll ;

vector<pair<int, pair<int, char>>> q;
map<int, int> doubts;

vector<int> ls, nl;
// int ls [MAX], nl[MAX];

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false); // use this if using iostream. DON'T USE WITH PRINTF!!!
	cin.tie(0), cout.tie(NULL);

	int T, Q, cd = 11, uq, un, res = 0;

	cin >> T;
	for(int t = 0; t<T; t++){
		cin >> Q;
		for(int y = 0; y < Q; y++){
			int s, d; char r;
			cin >> d >> s;
			cin >> r;
			// pair<int, pair<int, char>> e = (d, (s, r));
			// q.push_back(e);
			if(s == 0){
				if(r == 'i'){
					nl.push_back(d);
				}
			}else{
				if(r == 'c')
					ls.push_back(d);
			}

		}

		// for(vector<pair<int, pair<int, char>>>::iterator it = q.begin(); it != q.end(); ++it){
		// 	if(*it->second->second == 'i' && *it->first < cd && *it->second->first == 0)
		// 		cd = *it->first;
		// 	else if(*it->second->second == 'c' && *it->first > cd && *it->second->first == 0){
		// 		cd = *it->first + 1
		// 	}
		// }
		for(vector<int>::iterator it = ls.begin(); it != ls.end(); ++it)
			for(vector<int>::iterator st = nl.begin(); st != nl.end(); ++st)
				if(*it > *st)
					res++;
		cout << res << endl;
		res = 0;
		nl.clear(); ls.clear();
	}

	return 0;
}
