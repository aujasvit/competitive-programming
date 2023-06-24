
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair <int,int>
#define fr first
#define sc second

int n, m, k;
int dp1[50005], dp2[50005];
vector <pii> graph[50005];
vector <pii> food;

void dj1() {
    priority_queue<pii> q;
    bool visited[n + 5] = {0};
    for(int i = 1; i <= n; i++) dp1[i] = INT_MAX;
   
    dp1[n] = 0;
   
    q.push(mp(0,n));
   
    while(!q.empty()) {
        pii curr = q.top();q.pop();
        if(visited[curr.sc])continue;
        visited[curr.sc] = 1;
       
        for(int i = 0; i < graph[curr.sc].size(); i++) {
            pii dodo = graph[curr.sc][i];
            if(dp1[dodo.fr] > dp1[curr.sc] + dodo.sc) {
                dp1[dodo.fr] = dp1[curr.sc] + dodo.sc;
                q.push(mp(-1*dp1[dodo.fr], dodo.fr));
            }
        }
    }

   
}

void dj2() {
    priority_queue<pii> q;
    bool visited[n + 5] = {0};
    for(int i = 1; i <= n; i++) dp2[i] = INT_MAX;
   
    dp2[n] = 0;
   
    q.push(mp(0,n));
   
    while(!q.empty()) {
        pii curr = q.top();q.pop();
        if(visited[curr.sc])continue;
        visited[curr.sc] = 1;
       
        for(int i = 0; i < graph[curr.sc].size(); i++) {
            pii dodo = graph[curr.sc][i];
            if(dodo.fr == n) continue;

            if(dp2[dodo.fr] > dp2[curr.sc] + dodo.sc) {
                dp2[dodo.fr] = dp2[curr.sc] + dodo.sc;
                q.push(mp(-1*dp2[dodo.fr], dodo.fr));
            }
        }
    }


}

void change_graph() {
    //graph[n].clear();
   
    for(int i = 0; i < food.size(); i++) {
        graph[n].pb(mp(food[i].fr, dp1[food[i].fr] - food[i].sc));
    }
}

signed main() {
freopen("dining.in", "r", stdin);
// the following line creates/overwrites the output file
freopen("dining.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int al,be,ga;
        cin >> al >> be >> ga;
        graph[al].pb(mp(be,ga));
        graph[be].pb(mp(al,ga));
    }
   
    for(int i = 1; i <= k; i++) {
        int al,be;
        cin >> al >> be;
        food.pb(mp(al,be));
    }
    dj1();
    change_graph();
    dj2();
   
    for(int i = 1; i < n; i++) {
        if(dp2[i] <= dp1[i]) cout << 1 << endl;
        else cout << 0 << endl;
    }
   
    return 0;
   
}

