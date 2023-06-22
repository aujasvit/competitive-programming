//Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1201

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define p pair<int, int>
#define mp make_pair


vector <p> a;
int n;

int ans() {
    sort(a.begin(), a.end());
    
    int m = 0;
    int c = 0;
    for(int i = n - 1; i >= 0; i--) {
        int d = c + a[i].first + a[i].second;
        m = max(m, d);
        c += a[i].second;
    }
    
    return m;
    
}


signed main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int k, l, m;
        cin >> k >> l >> m;
        p temp = mp(l + m, k);
        a.pb(temp);
    }
    
    cout << ans() << endl;
    
    return 0;
}