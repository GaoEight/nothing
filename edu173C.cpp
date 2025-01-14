#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr ll INF = ll(1E10) + 5;
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    int pos = n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(abs(a[i]) != 1) {
            pos = i;
        }
    }
    ll mx1 = 0, mx2 = 0, mn1 = 0, mn2 = 0;
    ll t_mx = 0, t_mn = 0;
    for(int i = 0; i < pos; i++) {
        if(a[i] == -1) {
            t_mx = max(0LL, t_mx - 1);
            t_mn--;
        } else {
            t_mn = min(0LL, t_mn + 1);
            t_mx++;
        }
        mx1 = max(mx1, t_mx);
        mn1 = min(mn1, t_mn);
    }
    t_mx = t_mn = 0;
    for(int i = pos + 1; i < n; i++) {
         if(a[i] == -1) {
            t_mx = max(0LL, t_mx - 1);
            t_mn--;
        } else {
            t_mn = min(0LL, t_mn + 1);
            t_mx++;
        }
        mx2 = max(mx2, t_mx);
        mn2 = min(mn2, t_mn);
    }
     
    set<ll> st;
    for(int i = min(mn1, mn2); i <= max(mx1, mx2); i++) st.insert(i);
    mx1 = 0, mx2 = 0, mn1 = 0, mn2 = 0;
    if(pos != n) {
        ll temp = 0;
        for(ll i = pos - 1; i >= 0; i--) {
            temp += a[i];
            mx1 = max(temp, mx1);
            mn1 = min(temp, mn1);
        }
        temp = 0;
        for(ll i = pos + 1; i < n; i++) {
            temp += a[i];
            mx2 = max(mx2, temp);
            mn2 = min(mn2, temp);
        }
        for(ll i = mn1 + mn2; i <= mx1 + mx2; i++) {
            st.insert(i + a[pos]);
        }
    }
    cout << st.size() << "\n";
    for(auto it : st) {
        cout << it << ' ' ;
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
