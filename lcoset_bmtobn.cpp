#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> m >> n;
    vector<vector<int>> a(m, vector<int> (n));
    
    for(auto &i : a) {
        for(auto &j : i) cin >> j;
    }
    vector<vector<int>> b((1 << m), vector<int> (n));
    for(int num = 0; num < (1 << m); num++) {
        vector<int> c(m);
        for(int i = 0; i < m; i++) c[i] = 1 & (num >> i);
        for(int i = 0; i < n; i++) {
           b[num][i] = 0;
           for(int j = 0; j < m; j++) {
            b[num][i] ^= (a[j][i] * c[j]);
           }
        }
    }
    
    vector<vector<pair<int, vector<int>>>> ans;
    vector<int> vis(1 << n, 0);
    for(int num = 0; num < (1 << n); num++) {
        vector<int> c(n);
        vector<pair<int, vector<int>>> res;
        for(int i = 0; i < n; i++) c[i] = 1 & (num >> i);

        for(int i = 0; i < b.size(); i++) {
            int t = 0;
            vector<int> temp(n);
            for(int j = 0; j < n; j++) {
                temp[j] = c[j] ^ b[i][j];
                t += temp[j] * (1 << j);
            }
            if(vis[t]) break;
            vis[t] = 1;
            res.push_back({t, temp});
        }
        if(res.size()) ans.push_back(res);
    }
    for(auto &it : ans){
        sort(it.begin(), it.end(), [](pair<int, vector<int>> i, pair<int, vector<int>> j) {
            return i.fi < j.fi;
        });
    }
    for(auto &i : ans) {
        for(auto &j : i) {
            for(auto it : j.se) {
                cout << it;
            }
            cout << "\n";
        }
        cout << "\n\n";
    }

}
