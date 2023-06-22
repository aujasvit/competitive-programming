//Problem Link: https://www.codechef.com/INOIPRAC/problems/ROADTRIP

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back


vector <int> a[1000009];
vector <int> val;
vector <int> ans;
int n, m, k;

int d = 0;

void anss(bool visited[], int curr) {
    visited[curr] = true;
    d += val[curr];
    for(int i = 0; i < a[curr].size(); i++) {
        if(!visited[a[curr][i]])anss(visited, a[curr][i]);
    }
}




signed main() {
    int tt;
    cin >> tt;

    while(tt--) {
        cin >> n >> m >> k;
        bool visited[n + 2] = {0};
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }
        val.resize(n + 2);
        for(int i = 1; i <= n; i++) {
            cin >> val[i];
        }

        // anss();

        for(int i = 1; i<=n;i++) {
            if(visited[i]) continue;
            visited[i] = true;
            anss(visited, i);
            ans.pb(d);
            d = 0;
        }

        sort(ans.begin(), ans.end());

        int fin = 0;
        bool lav = true, dodo = false;
        int nik = 0, l = ans.size() - 1;
        for(int i = 0; i < k; i++) {
            if(nik > l) {
                cout << -1 << endl;
                dodo = true;
                break;
            }
            if(lav) {
                lav = false;
                fin += ans[l];
                l--;
            } else {
                lav = true;
                fin += ans[nik];
                nik++;
            }
        }

        if(!dodo) cout << fin << endl;

        for(int i = 1; i <= n; i++) {
            a[i].clear();
        }
        val.clear();
        ans.clear();
    }

    return 0;
}