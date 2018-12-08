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
#include <unordered_map>
using namespace std;

#define pb        push_back
#define dbug(x)     cout<<"x = "<<x<<endl
#define SEQUENCELENGTH  8
#define mp(a,b)     make_pair(a,b)


string st;
string p_start;
unordered_map<string, int> dp;
unordered_map<string, bool> bankHash;

void printVector(vector<string> v){
  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  cout << '\n';
}

void printVector(vector<int> v){
  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  cout << '\n';
}

int diffCount(string s, string n){
  int count = 0;

  for(int i = 0; i < SEQUENCELENGTH; ++i)
    if(s[i] != n[i])
      ++count;

  return count;
}


bool compFunc(string s, string n){
  return diffCount(s, st) < diffCount(n, st);
}

vector<string> genAdjList(string s, vector<string>::iterator lo,
vector<string>::iterator hi){
  vector<string> res;

  for(vector<string>::iterator it = lo; it != hi; ++it)
    if(diffCount(s, *it) == 1)
      res.pb(*it);

  return res;
}

int BFS(unordered_map<string, vector<string>> graph, unordered_map<string, bool> vis, string source, string dest){
  int length = -1;
  queue<pair<string, int>> q;
  q.push(mp(source, 0));
  vis[source] = true;

  while(!(q.empty())){
    pair<string, int> curr = q.front();
    q.pop();
    if(curr.first == dest){
      length = curr.second;
      break;
    }
    vis[curr.first] = true;
    vector<string> adj = graph[curr.first];
    for(int i = 0; i < adj.size(); ++i){
      if(!(vis[adj[i]]))
        q.push(mp(adj[i], curr.second + 1));
    }
  }

  return length;
}

void printGraph(unordered_map<string, vector<string>> g){
  for(unordered_map<string, vector<string>>::iterator it = g.begin(); it != g.end(); ++it){
    cout << it->first << "=>";
    for(vector<string>::iterator ic = (it->second).begin(); ic != (it->second).end(); ++ic)
      cout << *ic << " ";
    cout << '\n';
  }
}


vector<string> genMutationCandidates(string s){
  int diff = diffCount(s, st), cdiff = -1;
  vector<string> candidates;

  for(int i = 0; i < diff; ++i){
    string curr = "";

    int j = 0;
    for(j; j < SEQUENCELENGTH; ++j)
      if(s[j] != st[j] && j > cdiff){
        cdiff = j;
        curr.pb(st[j]);
        break;
      }else
        curr.pb(s[j]);

    for(++j; j < SEQUENCELENGTH; ++j)
      curr.pb(s[j]);

    candidates.pb(curr);
  }
  return candidates;
}

int findMutRec(string s){
  if(dp.find(s) != dp.end())
    return dp[s];

  if(s != p_start && (bankHash.find(s) == bankHash.end()))
    return dp[s] = -1;

  if(diffCount(s,st) == 1){
    dp[s] = 1;
    return 1;
  } 

  vector<string> candidates = genMutationCandidates(s);
  vector<int> lengths;

  for(int i = 0; i < candidates.size(); ++i){
      int curr = findMutRec(candidates[i]);
      if(curr > 0)
        lengths.pb(curr);
    }

  if(lengths.empty()){
      dp[s] = -1;
      return -1;
    }
 

  dp[s] = *(min_element(lengths.begin(), lengths.end())) + 1;

  return dp[s];
}

int findMutationDistance(string start, string end, vector < string > bank) {
    st = end;
    p_start = start;
    dp.clear();
    bankHash.clear();

    if(start == end)
      return 0;

    for(int i = 0; i < bank.size(); ++i)
      bankHash[bank[i]] = true;

    if(bankHash.find(end) == bankHash.end())
      return -1;

    return findMutRec(start);
}


int main() {

  string s = "AAAAAAAA", end = "GGAAAAAA";
  vector<string> b = {"GAAAAAAA", "AAGAAAAA", "AAAAGAAA", "GGAAAAAA"};
  // findMutationDistance(s, end, b);
  cout << findMutationDistance(s, end, b) << '\n';
  // st = end;
  // printVector(genMutationCandidates(s));
  vector<string>::iterator i = s == b[0] ? b.begin() + 1 : b.begin();
  std::vector<string> v(i,b.end());
  // printVector(v);
  return 0;
}
