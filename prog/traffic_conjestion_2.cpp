#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int maxn;

vector <int> graph[maxn];
/*

root --> r
r has 5 children
dp[a], dp[b], dp[c], dp[d], dp[e] has max from these 5
so when i shift from r to a let's say

dp[b],c,d,e,f remain same

dp[r] = max(b,c,d,e)

dp[a] = max(dp[a], dp[r])


*/

int dp[maxn];
bool visited[maxn] = {0};

void shift_node(int root = 0) {
	
	if(visited[root]) {
		continue;
	}

	for(auto i: graph[root]) {

		
		shift_node(i);
	}
} 

int dfs(int curr = 0) {
	if(visited[curr]) {
		return dp[curr];
	}

	visited[curr] = 1;
	int ll = 0;
	for(auto i:graph[curr]) {
		ll = max(ll, dfs(i) + p[i]);
	}

	dp[curr] = ll;

	return dp[curr];
}

int LocateCentre(int n, int p[], int s[], int d[]) {
	

	for(int i = 0; i < n - 1; i++) {
		graph[s[i]].pb(d[i]);
		graph[d[i]].pb(s[i]);
	}

	int root = 0;

	int m = dfs(), curr = 0;

	visited = {0};




//	cout << mi << " " << curr << endl;

    return curr;
}
