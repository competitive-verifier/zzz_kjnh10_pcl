// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C

#include "../../header.hpp"
#include "../graph.hpp"
#include "../../math/geometry/p2.hpp"

signed main() {
    int n;
    cin >> n;
    Graph g(n, P2<ll>(0LL, 0LL), P2<ll>(inf<ll>, inf<ll>));
    rep(i, n) {
        int u;
        cin >> u;
        int k;
        cin >> k;
        rep(j, k) {
            int to, cost;
            cin >> to >> cost;
            g.add_edge(u, to, P2<ll>(cost, 0LL), i);
        }
    }
    auto d = g.dijkstra(0);
    rep(i, n) { cout << i << " " << d[i].x << endl; }

    return 0;
}
