//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1081

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
#define pb 				push_back
#define maxN 			1000000

typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef pair < ll , ll > p2 ;
typedef vector < vector < ll > > vv ;
typedef vector < ll > vll ;

ll l = 0, u = 0;
vector<ll> primes;
bitset<maxN+1> is_prime;

void sieve(){
	is_prime.set();
	is_prime.reset(0);
	is_prime.reset(1);

	for(int i = 4; i < maxN; i+=2) is_prime.reset(i);
	for(ll i = 3; i*i <= maxN; i+=2){
		if(is_prime[i]){
			for(int j = i * 2; j <= maxN; j += i)
				is_prime.reset(j);
		}
	}

	for(ll i = 2; i < maxN; ++i){
		if(is_prime[i])
			primes.pb(i);
	}

}

bool isPrime(ll n){
	if(n < maxN) return is_prime[n];
	if(n % 2 == 0) return false;
	ll sq = (ll) sqrt(n);
	for(int i = 0; i < maxN && primes[i] <= sq; ++i)
		if(n%primes[i] == 0) return false;
	return true;
}

ll nextPrime(ll n){
	for(++n; n <= u; n++)
		if(isPrime(n)) return n;
	return -1;
}

int main(int argc, char const *argv[]){

	// ios_base::sync_with_stdio(false); // use this if using iostream. DON'T USE WITH PRINTF!!!
	// cin.tie(0), cout.tie(NULL);

	// freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	sieve();

	while(scanf("%lld %lld", &l, &u) == 2){
		ll min = INF, max = 0, size = sz(primes), curr = 0, np1 = 0, np2 = 0, xp1 = 0, xp2 = 0, 
		last = nextPrime(l-1), next = 0;
		if(last!=-1) while(1){
			next = nextPrime(last);
			if(next == -1) break;
			curr = next - last;
			if(curr < min){
				min = curr;
				np1 = last;
				np2 = next;
			}
			if(curr > max){
				max = curr;
				xp1 = last;
				xp2 = next;
			}
			last = next;
		}
		int npp1 = (int) np1, npp2 = (int) np2, xpp1 = (int) xp1, xpp2 = (int) xp2;
		if(max == 0)
			printf("There are no adjacent primes.\n");
		else
			printf("%d,%d are closest, %d,%d are most distant.\n", npp1, npp2, xpp1, xpp2);			
	}
	return 0;
}