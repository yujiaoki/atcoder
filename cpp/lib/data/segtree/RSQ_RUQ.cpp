#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
static const ll INF = (1LL << 62) - 1;  // 4611686018427387904 - 1
// --------------------------------------------------------
#include <atcoder/lazysegtree>
using namespace atcoder;

// 区間更新・区間総和
struct S { ll v; ll num; };
struct F { ll x; };
S op(S a, S b) { return S{a.v + b.v, a.num + b.num}; }
S e() { return S{0, 0}; }
S mapping(F f, S a) { return (f.x == INF) ? a : S{f.x * a.num, a.num}; }
F composition(F f, F g) { return (f.x == INF) ? g : f; }
F id() { return F{INF}; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    ll N, Q; cin >> N >> Q;
    vector<S> A(N, S{0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

    ll q, s, t, x;
    while (Q--) {
        cin >> q;
        if (q == 0) {
            cin >> s >> t >> x;
            seg.apply(s, t + 1, F{x});
        } else {
            cin >> s >> t;
            cout << seg.prod(s, t + 1).v << '\n';
        }
    }

    return 0;
}
// Verify: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I&lang=ja
