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
    // b是关系矩阵
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
    
    vector<vector<pair<int, vector<int>>>> coset;
    // 所有Bn的陪集
    vector<int> vis(1 << n, 0);
    for(int num = 0; num < (1 << n); num++) {
        vector<int> c(n);
        vector<pair<int, vector<int>>> res;
        for(int i = 0; i < n; i++) c[i] = 1 & (num >> i);

        for(int i = 0; i < b.size(); i++) {
            int t = 0, cnt = 0;
            vector<int> temp(n);
            for(int j = 0; j < n; j++) {
                temp[j] = c[j] ^ b[i][j];
                t += temp[j] * (1 << j);
                cnt += temp[j];
            }
            if(vis[t]) break;
            vis[t] = 1;
            res.push_back({cnt, temp});
        }
        if(res.size()) coset.push_back(res);
    }
    for(auto &it : coset){
        sort(it.begin(), it.end(), [](pair<int, vector<int>> i, pair<int, vector<int>> j) {
            return i.fi < j.fi;
        });
    }
    
    int q; cin >> q;
    auto cmp = [](vector<int> &x, vector<int> &y) {
        for(int i = 0; i < x.size(); i++) {
            if(x[i] != y[i]) return 0;
        }
        return 1;
    };
    while(q--) {
        vector<int> f(n);
        for(auto &i : f) cin >> i;
        for(auto &x : coset) {
            for(auto &y : x) {
                if(cmp(y.se, f)) {
                    vector<int> temp;
                    for(int i = 0; i < n; i++) {
                        temp.push_back(f[i] ^ (x[0].second[i]));
                    }
                    int res = 0;
                    for(int i = 0; i < b.size(); i++) {
                        if(cmp(b[i], temp)) {
                            for(int j = 0; j < m; j++) {
                                cout << (1 & (i >> j)) << ' ';
                            }
                            cout << "\n";
                            break;
                        }
                    }
                    goto endloop;
                }
            }
        }
        endloop:
            ;
    }// 输出译码
}
