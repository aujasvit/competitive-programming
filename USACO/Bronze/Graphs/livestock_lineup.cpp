//Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=965

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair <int,int>
#define fr first
#define sc second

vector <int> graph[10];
vector <int> ans;
bool visited[10];

void dfs(int curr) {
	if(visited[curr]) return;
	ans.pb(curr);
	visited[curr] = 1;
	for(auto j:graph[curr]) {
		dfs(j);
	}
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("lineup.in", "r", stdin);
	// freopen("lineup.out", "w", stdout);

	map <string,int> name;
	map <int,string> fu;

	name["Beatrice"] = 1; fu[1] = "Beatrice";
	name["Belinda"] = 2; fu[2] = "Belinda";
	name["Bella"] = 3; fu[3] = "Bella";
	name["Bessie"] = 4; fu[4] = "Bessie";
	name["Betsy"] = 5; fu[5] = "Betsy";
	name["Blue"] = 6; fu[6] = "Blue";
	name["Buttercup"] = 7; fu[7] = "Buttercup";
	name["Sue"] = 8; fu[8] = "Sue";

	int n; cin >> n;
	ans.clear();
	for(int i = 1; i <= 9; i++) graph[i].clear();

	for(int i = 0; i < n; i++) {
		char c[100], d[100];
		scanf("%s", c);


		for(int i = 0; i < 4; i++) scanf("%s", d);

		scanf("%s", d);
		// cout << c << " " << d << endl;
		string alpha = "", beta = "";

		for(int i = 0; c[i] != '\0'; i++) alpha += c[i];
		for(int i = 0; d[i] != '\0'; i++) beta += d[i];
		// cout << alpha << endl;

		graph[name[alpha]].pb(name[beta]);
		graph[name[beta]].pb(name[alpha]);

	}
	for(int i = 0; i < 10; i++) visited[i] = 0;
	for(int i = 1; i <= 8; i++) {
		if(graph[i].size() == 0) {ans.pb(i);}
		else if(graph[i].size() == 1) dfs(i);
	}

	for(auto j:ans) cout << fu[j] << endl;

}