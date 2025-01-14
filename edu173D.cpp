#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    ll l, r, g; cin >> l >> r >> g;
    l = l / g + (l % g != 0);
    r = r / g;

    for(ll d = r - l; d >= 0; d--) {
        for(ll a = l; a + d <= r; a++) {
            ll b = a + d;
            if(__gcd(a, b) == 1) {
                cout << a * g << ' ' << b * g << "\n";
                return;
            }
        }
    }
    cout << "-1 -1\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;  cin >> t;
    while(t--) {
        solve();
    }
}
