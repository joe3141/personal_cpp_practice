#include <bits/stdc++.h>
using namespace std;

#define dbug(x) 		cout<<"x = "<<x<<endl
#define pb 				push_back
//http://www.wikihow.com/Calculate-Multiple-Dice-Probabilities

struct spell
{
	int x, y, z;	
};

int to_int(string s){
	return atoi(s.c_str());
}

int main(int argc, char const *argv[]){
	int T, h, s, x, y, z;

	ifstream input;
	ofstream output;
	input.open("in.in");
	output.open("out.txt");
    input >> T;

    for(int t = 1; t <= T; ++t){
    	input>>h>>s;
    	string spellss[s];
    	spell spells[s];
    	for(int i = 0; i < s; ++i)
    		input >> spellss[i];

    	for(int i = 0; i < s; ++i){
    		string x = "", y = "", z="";
    		spell c;
    		int flag = 0;
    		for(int j = 0; j < spellss[i].length(); ++j){
    			if(spellss[i][j] == 'd')
    				flag = 1;
    			else if(spellss[i][j] == '+' || spellss[i][j] == '-'){
    				z.pb(spellss[i][j]);
    				flag = 2;
    			}else if(flag == 0)
    				x.pb(spellss[i][j]);
    			else if (flag == 1)
    				y.pb(spellss[i][j]);
    			else
    				z.pb(spellss[i][j]);
    		}
    		c.x = to_int(x); c.y = to_int(y); 
    		if(z != "")
    			c.z = to_int(z);
    		else
    			c.z = 0;
    		spells[i] = c;
    	}
    	double p[s];
    	for(int i = 0; i < s; ++i){
    		spell cs = spells[i];
    		int sum = h - spells[i].z;
    		if(sum <= 0){
    			p[i] = 1.0;
    			continue;
    		}
    		int dp[(cs.x * cs.y)+1][spells[i].x + 1];
    		memset(dp, 0, sizeof(dp));

    		for(int j = 1; j <= cs.y; ++j)
    			dp[j][1] = 1;

    		for(int k = 2; k <= cs.x; ++k)
    			for(int j = 1; j <= cs.y * k; ++j)
    				for(int r = 1; r < cs.y && (j-r) > 0; ++r)
    					dp[j][k] += dp[j-r][k-1];
    		double cp = 0.0;
    		for(int j = sum; j <= cs.x * cs.y; ++j)
    			cp += dp[j][cs.x];
    		p[i] = (double) cp/(pow(cs.y, cs.x));
    	}

    	double maxp = *max_element(p, p+s);
    	output << "Case #" << t << ": " << maxp << '\n';
    }
}

