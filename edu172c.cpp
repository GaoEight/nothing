#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
typedef pair<int, ll> pii;
typedef pair<ll, ll> pll;
constexpr int INF = INT_MAX;


void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> suf(n + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + (s[i] == '1' ? 1 : -1);
    }
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin() + 1, ind.end(), [&](int i, int j) {
        return suf[i] > suf[j];
    });
    ll cur = 0;
    for(int i = 1; i < n; i++) {
        cur += suf[ind[i]];
        if(cur >= k) {
            cout << i + 1 << "\n";
            return ;
        }
    }
    cout << -1 << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        solve();
    }
}

