#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
template<class T> bool chmax(T& a, const T b) { if (a < b) { a = b; return 1; } return 0; }
#define FOR(i,l,r) for (ll i = (l); i < (r); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define MAX(c) *max_element(ALL(c))
using VLL = vector<ll>;
using VVLL = vector<VLL>;
// --------------------------------------------------------


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    ll N, W; cin >> N >> W;
    VLL v(N+1),w(N+1),m(N+1); FOR(i,1,N+1) cin >> v[i] >> w[i] >> m[i];

    VLL dp(W+1,0);
    FOR(i,1,N+1) {
        ll n = m[i];
        for (ll k = 1; n > 0; k <<= 1) {
            ll t = min(n, k);  // 1, 2, 4, ... , a
            n -= t;
            for (ll j = W; 0 <= j - t*w[i]; j--) {
                chmax(dp[j], dp[j - t*w[i]] + t*v[i]);
            }
        }
    }
    cout << MAX(dp) << '\n';

    return 0;
}
// Verify: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G&lang=ja
