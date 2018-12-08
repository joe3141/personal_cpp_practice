
#include <bits/stdc++.h>
using namespace std;

#define dbug(x) 		cout<<"x = "<<x<<endl
#define eps 			(1e-9)
#define pie  			acos(-1)
#define INF  			LLONG_MAX
#define pb 				push_back

multiset<int> prices[301];
int dp[301][301];
int N, M;

int solve(int n, int num){
	if(dp[n][num] != -1)
		return dp[n][num];
	multiset<int> curr = prices[n];
	if(n == N){
		if(num > 0){
			dp[n][num] = 0;
			return 0;
		}
		else{
			multiset<int>::iterator it = curr.begin();
			dp[n][num] = 1 + *it;
			return 1 + *it;
		}
	}else{
		if(num == 0){
			int cnt = 1, price = 0;
			multiset<int>::iterator it = curr.begin();
			price += *it;
			++it;
			int m = price + 1 + solve(n + 1, 0), i = 0;
			for(it; it != curr.end() && i < N - n; ++it, ++i){
				price += *it;
				++cnt;
				m = min(m, price + (cnt * cnt) + solve(n+1, i+1));
			}
			dp[n][num] = m;
			return m;
		}else{
			int cnt = 0, price = 0;
			multiset<int>::iterator it = curr.begin();
			int m = solve(n+1, num-1), i = 0;
			for(it; it != curr.end() && i < N - n - (num - 1); ++it, ++i){
				price += *it;
				++cnt;
				m = min(m, price + (cnt * cnt) + solve(n+1, (num-1) + i+1));
			}
			dp[n][num] = m;
			return m;
		}
	}
}

int main(int argc, char const *argv[]){
	int T;
	int ans = 0;
	ifstream input;
	ofstream output;
	input.open("in.in");
	output.open("out.txt");
    input >> T;

    for(int t = 1; t <= T; ++t){
	    input >> N;
	    input>>M;

	    for(int i = 1; i <= N; ++i){
	    	multiset<int> curr;
			multiset<int>::iterator it;
			int x;
			input>>x;
			it = curr.insert(x);

			for(int j = 0; j < M - 1; ++j){
				input >> x;
				it = curr.insert(it, x);
			}

			prices[i] = curr;
	    }
	    memset(dp, -1, sizeof(dp));
	    ans = solve(1, 0);
	    output << "Case #" << t << ": " << ans << '\n';
	}

	input.close();
	output.close();

	return 0;
}
