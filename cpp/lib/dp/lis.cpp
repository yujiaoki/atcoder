#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
#define FOR(i,l,r) for (int i = (l); i < (r); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SZ(c) ((int)(c).size())
using VI = vector<int>;
// --------------------------------------------------------


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N; cin >> N;
    VI A(N); REP(i,N) cin >> A[i];

    VI L;
    L.push_back(A[0]);
    FOR(i, 1, N) {
        if (L.back() < A[i]) {
            L.push_back(A[i]);
        } else {
            *lower_bound(ALL(L), A[i]) = A[i];
        }
    }
    int ans = SZ(L);
    cout << ans << '\n';

    return 0;
}