---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :question: library/cpp/graph/tree.lib/tree.hpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#eaeee77e776a943cad05fb3e3b603f65">library/cpp/graph/tree.lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/graph/tree.lib/tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 19:35:46+09:00




## Depends on

* :question: <a href="../../array/segtree/segment_tree.hpp.html">library/cpp/array/segtree/segment_tree.hpp</a>
* :question: <a href="../edge.hpp.html">library/cpp/graph/edge.hpp</a>
* :question: <a href="../../header.hpp.html">library/cpp/header.hpp</a>


## Required by

* :heavy_check_mark: <a href="../bellman_ford.hpp.html">library/cpp/graph/bellman_ford.hpp</a>
* :question: <a href="../graph.hpp.html">library/cpp/graph/graph.hpp</a>
* :warning: <a href="../gridgraph.cpp.html">library/cpp/graph/gridgraph.cpp</a>
* :heavy_check_mark: <a href="../scc.hpp.html">library/cpp/graph/scc.hpp</a>
* :warning: <a href="../test.make_bipartie/codes/solve.cpp.html">library/cpp/graph/test.make_bipartie/codes/solve.cpp</a>
* :x: <a href="../topological_sort.hpp.html">library/cpp/graph/topological_sort.hpp</a>
* :warning: <a href="reroot.cpp.html">library/cpp/graph/tree.lib/reroot.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tests/bellman_ford.test.cpp.html">library/cpp/graph/tests/bellman_ford.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tests/graph.2dcost.test.cpp.html">library/cpp/graph/tests/graph.2dcost.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tests/graph.bridge.test.cpp.html">library/cpp/graph/tests/graph.bridge.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tests/graph.dijkstra.test.cpp.html">library/cpp/graph/tests/graph.dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tests/graph.kruskal.test.cpp.html">library/cpp/graph/tests/graph.kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tests/graph.lowlink.test.cpp.html">library/cpp/graph/tests/graph.lowlink.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tests/scc.test.cpp.html">library/cpp/graph/tests/scc.test.cpp</a>
* :x: <a href="../../../../../verify/library/cpp/graph/tests/topological_sort.test.cpp.html">library/cpp/graph/tests/topological_sort.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tree.lib/hld.test.cpp.html">library/cpp/graph/tree.lib/hld.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/library/cpp/graph/tree.lib/lca.test.cpp.html">library/cpp/graph/tree.lib/lca.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../../header.hpp"
#include "../../array/segtree/segment_tree.hpp"
#include "../edge.hpp"
// (ref) https://www.slideshare.net/Proktmr/ss-138534092
// (ref:HL decomposition) https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3

//%snippet.set('tree')%
//%snippet.include('segment_tree')%
//%snippet.include('edge')%
//%snippet.fold()%
template<class Cost=ll>
struct tree { 
    int n;
    vector<int> par;   // par[i]: dfs木における親
    vector<Cost> cost;  // par[i]: dfs木における親への辺のコスト
    vector<int> dfstrv;  // dfstrv[i]: dfs木でi番目に訪れるノード。dpはこれを逆順に回す
    vector<int> ord;    // ord[u]: uのdfs木における訪問順
    vector<int> end;    // end[u]: uのdfs終了時のカウンター
    vector<int> psize;  // psize[u]: uのpartial tree size
    // uの部分木は[ord[u], end[u])
    // ordとdfstrvは逆変換
    vector<int> depth;   // depth[i]: dfs木でのiの深さ
    vector<Cost> ldepth;  //  ldepth[i]: dfs木でのrootからの距離
    vector<vector<Edge<Cost>>> adj_list;       // 辺(隣接リスト)
    auto operator[](int pos) const { return adj_list[pos]; }
    vector<vector<int>> children;
    vector<int> euler_tour;
    vector<int> et_fpos;    // euler_tour first occurence position
    SegmentTree<int> _seg;  // seg(map(ord, euler_tour), mymin, 1e18)
    vector<int> head_of_comp;
    int _counter = 0;

    tree(){};/*{{{*/
    tree(int n)
        : n(n),
          par(n),
          cost(n),
          ord(n),
          end(n),
          psize(n),
          depth(n),
          ldepth(n),
          adj_list(n),
          children(n),
          et_fpos(n),
          head_of_comp(n){};/*}}}*/
    void add_edge(int u, int v, Cost cost, int idx=-1) { /*{{{*/
        adj_list[u].emplace_back(u, v, cost, idx);
        adj_list[v].emplace_back(v, u, cost, idx);
    }                             /*}}}*/
    void add_edge(int u, int v) { /*{{{*/
        adj_list[u].emplace_back(u, v, 1, -1);
        adj_list[v].emplace_back(v, u, 1, -1);
    }                      /*}}}*/
    void build(int root) { /*{{{*/
        _counter = 0;
        // par[root] = -1;
        // cost[root] = -1;
        _dfs_psize(root, -1);
        _dfs_tree(root, -1, root);
        _dfs_et(root);
        vector<int> ini(2 * n - 1);
        rep(i, 2 * n - 1) ini[i] = ord[euler_tour[i]];
        _seg = SegmentTree<int>(
            ini, [](auto a, auto b) { return min(a, b); }, 1e18);
    }                                /*}}}*/
    int _dfs_psize(int u, int pre) { /*{{{*/
        psize[u] = 1;
        each(edge, adj_list[u]) {
            if (edge.to == pre) continue;
            psize[u] += _dfs_psize(edge.to, u);
        }
        return psize[u];
    }                                               /*}}}*/
    void _dfs_tree(int u, int pre, int head_node) { /*{{{*/
        dfstrv.pb(u);
        ord[u] = _counter;
        if (pre != -1) {
            depth[u] = depth[pre] + 1;
            ldepth[u] = ldepth[pre] + cost[u];
        }

        _counter++;
        {
            // set most heavy child to top
            int max_psize = 0;
            int most_heavy_i = -1;
            rep(i, sz(adj_list[u])) {
                if (adj_list[u][i].to == pre) continue;
                if (psize[adj_list[u][i].to] > max_psize) {
                    most_heavy_i = i;
                    max_psize = psize[adj_list[u][i].to];
                }
            }
            if (most_heavy_i != -1) swap(adj_list[u][most_heavy_i], adj_list[u][0]);
        }

        head_of_comp[u] = head_node;
        rep(i, sz(adj_list[u])) {
            int v = adj_list[u][i].to;
            if (v == pre) continue;

            children[u].pb(v);
            par[v] = u;
            cost[v] = adj_list[u][i].cost;

            if (i == 0)
                _dfs_tree(v, u, head_node);  // continue components
            else
                _dfs_tree(v, u, v);  // new
        }
        end[u] = _counter;
    }                     /*}}}*/
    void _dfs_et(int u) { /*{{{*/
        et_fpos[u] = euler_tour.size();
        euler_tour.pb(u);
        each(v, children[u]) {
            _dfs_et(v);
            euler_tour.pb(u);
        }
    }                       /*}}}*/
    int lca(int u, int v) { /*{{{*/
        if (u == v) return u;
        if (et_fpos[u] > et_fpos[v]) swap(u, v);
        return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];
    }                        /*}}}*/
    int dist(int u, int v) { /*{{{*/
        int p = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[p];
    }                          /*}}}*/
    Cost ldist(int u, int v) {  // length dist{{{
        int p = lca(u, v);
        return ldepth[u] + ldepth[v] - 2 * ldepth[p];
    }                           /*}}}*/
    pair<int, int> diameter() { /*{{{*/
        int u, v;
        Cost max_len = *max_element(all(ldepth));
        rep(i, n) {
            if (ldepth[i] == max_len) {
                u = i;
                break;
            }
        }
        Cost md = -1;
        rep(i, n) {
            Cost d = ldist(u, i);
            if (d > md) {
                v = i;
                md = d;
            }
        }
        return mp(u, v);
    }                                                /*}}}*/
    vector<pair<int, int>> hld_path(int u, int v) {  //{{{
        // 閉区間をvectorで返す
        vector<pair<int, int>> res;
        while (head_of_comp[u] != head_of_comp[v]) {
            if (depth[head_of_comp[u]] < depth[head_of_comp[v]]) {
                res.push_back({ord[head_of_comp[v]], ord[v]});
                v = par[head_of_comp[v]];
            } else {
                res.push_back({ord[head_of_comp[u]], ord[u]});
                u = par[head_of_comp[u]];
            }
        }
        res.push_back({min(ord[u], ord[v]), max(ord[u], ord[v])});
        return res;
    }                              //}}}
#if defined(PCM) || defined(LOCAL) /*{{{*/
    friend ostream& operator<<(ostream& os, const tree& tr) {
        os << endl;
        os << "par:         " << tr.par << endl;
        os << "cost:        " << tr.cost << endl;
        os << "dfstrv:      " << tr.dfstrv << endl;
        os << "ord:         " << tr.ord << endl;
        os << "end:         " << tr.end << endl;
        os << "depth:       " << tr.depth << endl;
        os << "children:    " << tr.children << endl;
        os << "euler_tour:  " << tr.euler_tour << endl;
        os << "et_fpos:     " << tr.et_fpos << endl;
        os << "head_of_comp:" << tr.head_of_comp << endl;
        return os;
    }
#endif /*}}}*/
}; 

//%snippet.end()%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "library/cpp/header.hpp"

//%snippet.set('header')%
//%snippet.fold()%
#ifndef HEADER_H
#define HEADER_H

// template version 2.0
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF = 1e18;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _rrep(i, n) rrepi(i, 0, n)
#define rrepi(i, a, b) for (int i = (int)((b)-1); i >= (int)(a); --i)
#define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)
#define each(i, a) for (auto &&i : a)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x) - A.begin())
#define upos(A, x) (upper_bound(all(A), x) - A.begin())
template <class T>
inline void chmax(T &a, const T &b) {
    if ((a) < (b)) (a) = (b);
}
template <class T>
inline void chmin(T &a, const T &b) {
    if ((a) > (b)) (a) = (b);
}

#define divceil(a, b) ((a) + (b)-1) / (b)
#define is_in(x, a, b) ((a) <= (x) && (x) < (b))
#define uni(x)    \
    sort(all(x)); \
    x.erase(unique(all(x)), x.end())
#define slice(l, r) substr(l, r - l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;

template <typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast {
    Fast() {
        std::cin.tie(0);
        ios::sync_with_stdio(false);
    }
} fast;
void check_input() {
    assert(cin.eof() == 0);
    int tmp;
    cin >> tmp;
    assert(cin.eof() == 1);
}

#if defined(PCM) || defined(LOCAL)
#else
#define dump(...) ;
#define dump_1d(...) ;
#define dump_2d(...) ;
#define cerrendl ;
#endif

#endif /* HEADER_H */
//%snippet.end()%
#line 3 "library/cpp/array/segtree/segment_tree.hpp"
// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

//%snippet.set('segment_tree')%
//%snippet.config({'alias':'rmq'})%
//%snippet.fold()%

template <typename T> struct SegmentTree {  // {{{
    private:
        using F = function<T(T, T)>;
        int n;  // 元の配列のサイズ
        int N;  // n以上の最小の2冪
        vector<T> node;
        F merge;
        T identity;

    public:
        SegmentTree() {}
        SegmentTree(vector<T> a, F f, T id) : merge(f), identity(id) {
            n = a.size();
            N = 1;
            while (N < n) N *= 2;
            node.resize(2 * N - 1, identity);
            for (int i = 0; i < n; i++) node[i + N - 1] = a[i];
            for (int i = N - 2; i >= 0; i--)
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
        }
        SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id) {}

        T& operator[](int i) { return node[i + N - 1]; }

        void update(int i, T val) {
            i += (N - 1);
            node[i] = val;
            while (i > 0) {
                i = (i - 1) / 2;
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
            }
        }

        void add(int i, T val) {
            i += (N - 1);
            node[i] += val;
            while (i > 0) {
                i = (i - 1) / 2;
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
            }
        }

        // query for [l, r)
        T query(int a, int b, int k = 0, int l = 0, int r = -1) {
            if (r < 0) r = N;
            if (r <= a || b <= l) return identity;
            if (a <= l && r <= b) return node[k];

            T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(vl, vr);
        }

        #if defined(PCM) || defined(LOCAL)
        friend ostream& operator<<(ostream& os, SegmentTree<T>& sg) {  //
            os << "[";
            for (int i = 0; i < sg.n; i++) {
                os << sg[i] << (i == sg.n - 1 ? "]\n" : ", ");
            }
            return os;
        }
        #endif
};/*}}}*/
// sample of initialize SegmentTree:
// -----------------------------------------------
// auto mymin=[](auto a, auto b){return min(a,b);};
// SegmentTree<ll> seg(a, mymin, 1e18);

// auto mymax=[](auto a, auto b){return max(a,b);};
// SegmentTree<ll> seg(a, mymax, -1e18);

// auto add=[](auto a, auto b){return a+b;};
// SegmentTree<ll> seg(a, add, 0);
// -----------------------------------------------

//%snippet.end()%
#line 3 "library/cpp/graph/edge.hpp"

//%snippet.set('edge')%
//%snippet.fold()%
template<class Cost=ll>
struct Edge {
    int from, to;
    Cost cost;
    int idx;
    Edge(){};
    Edge(int from, int to, Cost cost, int idx)
        : from(from), to(to), cost(cost), idx(idx) {}

    friend ostream& operator<<(ostream& os, const Edge& e) {
        // os << "(f:" << e.from << ", t:" << e.to << ", c:" << e.cost << ", i" << e.idx << ")";  // detailed
        os << "(" << e.from << "," << e.to << ")";
        return os;
    }
};
//%snippet.end()%
#line 5 "library/cpp/graph/tree.lib/tree.hpp"
// (ref) https://www.slideshare.net/Proktmr/ss-138534092
// (ref:HL decomposition) https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3

//%snippet.set('tree')%
//%snippet.include('segment_tree')%
//%snippet.include('edge')%
//%snippet.fold()%
template<class Cost=ll>
struct tree { 
    int n;
    vector<int> par;   // par[i]: dfs木における親
    vector<Cost> cost;  // par[i]: dfs木における親への辺のコスト
    vector<int> dfstrv;  // dfstrv[i]: dfs木でi番目に訪れるノード。dpはこれを逆順に回す
    vector<int> ord;    // ord[u]: uのdfs木における訪問順
    vector<int> end;    // end[u]: uのdfs終了時のカウンター
    vector<int> psize;  // psize[u]: uのpartial tree size
    // uの部分木は[ord[u], end[u])
    // ordとdfstrvは逆変換
    vector<int> depth;   // depth[i]: dfs木でのiの深さ
    vector<Cost> ldepth;  //  ldepth[i]: dfs木でのrootからの距離
    vector<vector<Edge<Cost>>> adj_list;       // 辺(隣接リスト)
    auto operator[](int pos) const { return adj_list[pos]; }
    vector<vector<int>> children;
    vector<int> euler_tour;
    vector<int> et_fpos;    // euler_tour first occurence position
    SegmentTree<int> _seg;  // seg(map(ord, euler_tour), mymin, 1e18)
    vector<int> head_of_comp;
    int _counter = 0;

    tree(){};/*{{{*/
    tree(int n)
        : n(n),
          par(n),
          cost(n),
          ord(n),
          end(n),
          psize(n),
          depth(n),
          ldepth(n),
          adj_list(n),
          children(n),
          et_fpos(n),
          head_of_comp(n){};/*}}}*/
    void add_edge(int u, int v, Cost cost, int idx=-1) { /*{{{*/
        adj_list[u].emplace_back(u, v, cost, idx);
        adj_list[v].emplace_back(v, u, cost, idx);
    }                             /*}}}*/
    void add_edge(int u, int v) { /*{{{*/
        adj_list[u].emplace_back(u, v, 1, -1);
        adj_list[v].emplace_back(v, u, 1, -1);
    }                      /*}}}*/
    void build(int root) { /*{{{*/
        _counter = 0;
        // par[root] = -1;
        // cost[root] = -1;
        _dfs_psize(root, -1);
        _dfs_tree(root, -1, root);
        _dfs_et(root);
        vector<int> ini(2 * n - 1);
        rep(i, 2 * n - 1) ini[i] = ord[euler_tour[i]];
        _seg = SegmentTree<int>(
            ini, [](auto a, auto b) { return min(a, b); }, 1e18);
    }                                /*}}}*/
    int _dfs_psize(int u, int pre) { /*{{{*/
        psize[u] = 1;
        each(edge, adj_list[u]) {
            if (edge.to == pre) continue;
            psize[u] += _dfs_psize(edge.to, u);
        }
        return psize[u];
    }                                               /*}}}*/
    void _dfs_tree(int u, int pre, int head_node) { /*{{{*/
        dfstrv.pb(u);
        ord[u] = _counter;
        if (pre != -1) {
            depth[u] = depth[pre] + 1;
            ldepth[u] = ldepth[pre] + cost[u];
        }

        _counter++;
        {
            // set most heavy child to top
            int max_psize = 0;
            int most_heavy_i = -1;
            rep(i, sz(adj_list[u])) {
                if (adj_list[u][i].to == pre) continue;
                if (psize[adj_list[u][i].to] > max_psize) {
                    most_heavy_i = i;
                    max_psize = psize[adj_list[u][i].to];
                }
            }
            if (most_heavy_i != -1) swap(adj_list[u][most_heavy_i], adj_list[u][0]);
        }

        head_of_comp[u] = head_node;
        rep(i, sz(adj_list[u])) {
            int v = adj_list[u][i].to;
            if (v == pre) continue;

            children[u].pb(v);
            par[v] = u;
            cost[v] = adj_list[u][i].cost;

            if (i == 0)
                _dfs_tree(v, u, head_node);  // continue components
            else
                _dfs_tree(v, u, v);  // new
        }
        end[u] = _counter;
    }                     /*}}}*/
    void _dfs_et(int u) { /*{{{*/
        et_fpos[u] = euler_tour.size();
        euler_tour.pb(u);
        each(v, children[u]) {
            _dfs_et(v);
            euler_tour.pb(u);
        }
    }                       /*}}}*/
    int lca(int u, int v) { /*{{{*/
        if (u == v) return u;
        if (et_fpos[u] > et_fpos[v]) swap(u, v);
        return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];
    }                        /*}}}*/
    int dist(int u, int v) { /*{{{*/
        int p = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[p];
    }                          /*}}}*/
    Cost ldist(int u, int v) {  // length dist{{{
        int p = lca(u, v);
        return ldepth[u] + ldepth[v] - 2 * ldepth[p];
    }                           /*}}}*/
    pair<int, int> diameter() { /*{{{*/
        int u, v;
        Cost max_len = *max_element(all(ldepth));
        rep(i, n) {
            if (ldepth[i] == max_len) {
                u = i;
                break;
            }
        }
        Cost md = -1;
        rep(i, n) {
            Cost d = ldist(u, i);
            if (d > md) {
                v = i;
                md = d;
            }
        }
        return mp(u, v);
    }                                                /*}}}*/
    vector<pair<int, int>> hld_path(int u, int v) {  //{{{
        // 閉区間をvectorで返す
        vector<pair<int, int>> res;
        while (head_of_comp[u] != head_of_comp[v]) {
            if (depth[head_of_comp[u]] < depth[head_of_comp[v]]) {
                res.push_back({ord[head_of_comp[v]], ord[v]});
                v = par[head_of_comp[v]];
            } else {
                res.push_back({ord[head_of_comp[u]], ord[u]});
                u = par[head_of_comp[u]];
            }
        }
        res.push_back({min(ord[u], ord[v]), max(ord[u], ord[v])});
        return res;
    }                              //}}}
#if defined(PCM) || defined(LOCAL) /*{{{*/
    friend ostream& operator<<(ostream& os, const tree& tr) {
        os << endl;
        os << "par:         " << tr.par << endl;
        os << "cost:        " << tr.cost << endl;
        os << "dfstrv:      " << tr.dfstrv << endl;
        os << "ord:         " << tr.ord << endl;
        os << "end:         " << tr.end << endl;
        os << "depth:       " << tr.depth << endl;
        os << "children:    " << tr.children << endl;
        os << "euler_tour:  " << tr.euler_tour << endl;
        os << "et_fpos:     " << tr.et_fpos << endl;
        os << "head_of_comp:" << tr.head_of_comp << endl;
        return os;
    }
#endif /*}}}*/
}; 

//%snippet.end()%

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>
