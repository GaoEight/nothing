#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
typedef pair<int, ll> pii;
typedef pair<ll, ll> pll;
constexpr int INF = INT_MAX;

struct cmp {
    bool operator()(int i, int j) {
        return i > j;
    }
};
void solve() {
    int n; cin >> n;
    vector<int> l(n), r(n);
    vector<int> L(n, -1), R(n, -1);
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    {
        sort(ind.begin(), ind.end(), [&](int i, int j) {
            if(r[i] != r[j]) return r[i] > r[j];
            else return l[i] < l[j];
        });
        set<int, greater<int>> st;
        for(int  j = 0; j < n; j++) {
            int i = ind[j];
            auto it = st.lower_bound(l[i]);
            if(it != st.end() && st.size()) {
                L[i] = *it;
            }
            st.insert(l[i]);
            if(j != n - 1 && l[ind[j + 1]] == l[i] && r[ind[j + 1]] == r[i]) {
                L[i] = l[i];
            }
        }
    }

    {
        sort(ind.begin(), ind.end(), [&](int i, int j) {
            if(l[i] != l[j]) return l[i] < l[j];
            else return r[i] > r[j];
        });
        set<int> st;
        for(int j = 0; j < n; j++) {
            int i = ind[j];
            auto it = st.lower_bound(r[i]);
            if(it != st.end() && st.size()) {
                R[i] = *it;
            }
            st.insert(r[i]);
            if(j != n - 1 && l[ind[j + 1]] == l[i] && r[ind[j + 1]] == r[i]) {
                R[i] = r[i];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        // cerr << L[i] << ' ' << R[i] << "\n";
        int ans = (L[i] == -1 ? 0 : l[i] - L[i]) + (R[i] == -1 ? 0 : R[i] - r[i]);
        cout << ans << "\n";
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        solve();
    }
}

