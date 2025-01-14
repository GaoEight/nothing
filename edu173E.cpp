#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
bool check(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<pair<int, bool>>> adj(n + m);
    vector<int> in(n + m, 0);
    
    queue<int> q1;
    vector<int> vis(n + m, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == b[i][j]) {
                continue;
            }
            if(b[i][j] == 1 && !vis[j + n]) {
                q1.push(j + n);
                vis[j + n] = 1;
            } else if(b[i][j] == 0 && !vis[i]) {
                q1.push(i);
                vis[i] = 1;
            }
        }
    }
    while(q1.size()) {
        int cur = q1.front();
        q1.pop();
        if(cur < n) {
            for(int j = 0; j < m; j++) {
                if(b[cur][j] == 1) {
                    adj[cur].push_back({j + n, 1});
                    if(!vis[j + n]) {
                        q1.push(j + n);
                        vis[j + n] = 1;
                    }
                }
            }
        } else {
            for(int i = 0; i < n; i++) {
                if(b[i][cur - n] == 0) {
                    adj[cur].push_back({i,  1});
                    if(!vis[i]) {
                        q1.push(i);
                        vis[i] = 1;
                    }
                }
            }
        }
    }
    for(auto v : adj) {
        for(auto it : v) {
            in[it.fi]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n + m; i++) {
        if(in[i] == 0) q.push(i);
    }
    while(q.size()) {
        int cur = q.front();
        q.pop();
        for(auto it : adj[cur]) {
            in[it.fi]--;
            if(!in[it.fi]) {
                q.push(it.fi);
            }
        }
    }
    for(int i = 0; i < n + m; i++) {
        if(in[i] != 0) {
            /*
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < m; k++) {
                    cerr << a[j][k] << " ";
                }
                cerr << "\n";
            }
            cerr << "\n";
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < m; k++) {
                    cerr << b[j][k] << " ";
                }
                cerr << "\n";
            }*/
            return false;
        }
    }
    return true;
}
void solve(int t) {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m)), b(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> a[i][j];
    } 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> b[i][j];
    } 

    for(int i = 0; i < 31; i++) {
        vector<vector<int>> ta(n, vector<int> (m, 0)), tb(n, vector<int> (m, 0));
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                ta[j][k] = 1 & (a[j][k] >> i);
                tb[j][k] = 1 & (b[j][k] >> i);
            }
        }
        if(check(ta, tb) == false) {
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes\n";

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;  cin >> t;
    for(int i = 1; i <= t; i++) {
        solve(i);
    }
}

/*
1
2 2
1 0
0 1
0 1
1 0
*/
