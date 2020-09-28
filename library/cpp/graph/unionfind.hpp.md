---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/bellman_ford.hpp
    title: library/cpp/graph/bellman_ford.hpp
  - icon: ':question:'
    path: library/cpp/graph/graph.hpp
    title: library/cpp/graph/graph.hpp
  - icon: ':warning:'
    path: library/cpp/graph/gridgraph.cpp
    title: library/cpp/graph/gridgraph.cpp
  - icon: ':warning:'
    path: library/cpp/graph/local_min_cycle.hpp
    title: library/cpp/graph/local_min_cycle.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/strongly_connected_components.hpp
    title: library/cpp/graph/strongly_connected_components.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/topological_sort.hpp
    title: library/cpp/graph/topological_sort.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/two_sat.hpp
    title: library/cpp/graph/two_sat.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/tests/bellman_ford.test.cpp
    title: library/cpp/graph/tests/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/tests/graph.2dcost.test.cpp
    title: library/cpp/graph/tests/graph.2dcost.test.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/tests/graph.bridge.test.cpp
    title: library/cpp/graph/tests/graph.bridge.test.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/tests/graph.dijkstra.test.cpp
    title: library/cpp/graph/tests/graph.dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/tests/graph.kruskal.test.cpp
    title: library/cpp/graph/tests/graph.kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/tests/graph.lowlink.test.cpp
    title: library/cpp/graph/tests/graph.lowlink.test.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/tests/scc.test.cpp
    title: library/cpp/graph/tests/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/tests/topological_sort.test.cpp
    title: library/cpp/graph/tests/topological_sort.test.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/tests/two_sat.test.cpp
    title: library/cpp/graph/tests/two_sat.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n\
    //%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\n// template version\
    \ 2.0\nusing namespace std;\n#include <bits/stdc++.h>\n\n// varibable settings\n\
    const long long INF = 1e18;\ntemplate <class T> constexpr T inf = numeric_limits<T>::max()\
    \ / 2.1;\n\n#define _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n)\
    \ repi(i, 0, n)\n#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n\
    #define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n#define _rrep(i,\
    \ n) rrepi(i, 0, n)\n#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a);\
    \ --i)\n#define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)\n\
    #define each(i, a) for (auto &&i : a)\n#define all(x) (x).begin(), (x).end()\n\
    #define sz(x) ((int)(x).size())\n#define pb(a) push_back(a)\n#define mp(a, b)\
    \ make_pair(a, b)\n#define mt(...) make_tuple(__VA_ARGS__)\n#define ub upper_bound\n\
    #define lb lower_bound\n#define lpos(A, x) (lower_bound(all(A), x) - A.begin())\n\
    #define upos(A, x) (upper_bound(all(A), x) - A.begin())\ntemplate <class T, class\
    \ U> inline void chmax(T &a, const U &b) { if ((a) < (b)) (a) = (b); }\ntemplate\
    \ <class T, class U> inline void chmin(T &a, const U &b) { if ((a) > (b)) (a)\
    \ = (b); }\ntemplate <typename X, typename T> auto make_table(X x, T a) { return\
    \ vector<T>(x, a); }\ntemplate <typename X, typename Y, typename Z, typename...\
    \ Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z,\
    \ zs...); return vector<decltype(cont)>(x, cont); }\n\n#define cdiv(a, b) (((a)\
    \ + (b)-1) / (b))\n#define is_in(x, a, b) ((a) <= (x) && (x) < (b))\n#define uni(x)\
    \ sort(all(x)); x.erase(unique(all(x)), x.end())\n#define slice(l, r) substr(l,\
    \ r - l)\n\ntypedef long long ll;\ntypedef long double ld;\nusing vl = vector<ll>;\n\
    using vvl = vector<vl>;\nusing pll = pair<ll, ll>;\n\ntemplate <typename T>\n\
    using PQ = priority_queue<T, vector<T>, greater<T>>;\nvoid check_input() { assert(cin.eof()\
    \ == 0); int tmp; cin >> tmp; assert(cin.eof() == 1); }\n\n#if defined(PCM) ||\
    \ defined(LOCAL)\n#else\n#define dump(...) ;\n#define dump_1d(...) ;\n#define\
    \ dump_2d(...) ;\n#define cerrendl ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n\
    #line 3 \"library/cpp/graph/unionfind.hpp\"\n\n//%snippet.set('UnionFind')%\n\
    //%snippet.fold()%\n\nstruct UnionFind {\n    vector<int> par;   // par[x]: parent\
    \ of x. if root, -size.\n    int gcount;         // count of groups\n\n    UnionFind()\
    \ {}\n    UnionFind(int _n) : par(_n, -1), gcount(_n) {}\n    bool merge(int x,\
    \ int y) { \n        x = root(x);\n        y = root(y);\n        if (x != y) {\n\
    \            if (par[y] < par[x]) swap(x, y);\n            par[x] += par[y];\n\
    \            par[y] = x;\n            gcount--;\n        }\n        return x !=\
    \ y;\n    } \n    int root(int x) {\n        if (is_root(x)){\n            return\
    \ x;\n        }\n        else{\n            return par[x] = root(par[x]);  //\
    \ \u7D4C\u8DEF\u5727\u7E2E\n            // return root(par[x]);         // \u7D4C\
    \u8DEF\u5727\u7E2E\u306A\u3057\n        }\n    }\n    bool is_root(int x) { return\
    \ par[x] < 0; }\n    bool same(int x, int y) { return root(x) == root(y); }\n\
    \    int size(int x) { return -par[root(x)]; }\n\n#if defined(PCM) || defined(LOCAL)\
    \  // {{{\n    friend ostream& operator<<(ostream& os, UnionFind& uf) {\n    \
    \    map<int, vector<int>> group;\n        rep(i, sz(uf.par)) { group[uf.root(i)].pb(i);\
    \ }\n        os << endl;\n        each(g, group) { os << g << endl; }\n      \
    \  return os;\n    }\n#endif  // }}}\n};\n\n//%snippet.end()%\n"
  code: "#pragma once\n#include \"../header.hpp\"\n\n//%snippet.set('UnionFind')%\n\
    //%snippet.fold()%\n\nstruct UnionFind {\n    vector<int> par;   // par[x]: parent\
    \ of x. if root, -size.\n    int gcount;         // count of groups\n\n    UnionFind()\
    \ {}\n    UnionFind(int _n) : par(_n, -1), gcount(_n) {}\n    bool merge(int x,\
    \ int y) { \n        x = root(x);\n        y = root(y);\n        if (x != y) {\n\
    \            if (par[y] < par[x]) swap(x, y);\n            par[x] += par[y];\n\
    \            par[y] = x;\n            gcount--;\n        }\n        return x !=\
    \ y;\n    } \n    int root(int x) {\n        if (is_root(x)){\n            return\
    \ x;\n        }\n        else{\n            return par[x] = root(par[x]);  //\
    \ \u7D4C\u8DEF\u5727\u7E2E\n            // return root(par[x]);         // \u7D4C\
    \u8DEF\u5727\u7E2E\u306A\u3057\n        }\n    }\n    bool is_root(int x) { return\
    \ par[x] < 0; }\n    bool same(int x, int y) { return root(x) == root(y); }\n\
    \    int size(int x) { return -par[root(x)]; }\n\n#if defined(PCM) || defined(LOCAL)\
    \  // {{{\n    friend ostream& operator<<(ostream& os, UnionFind& uf) {\n    \
    \    map<int, vector<int>> group;\n        rep(i, sz(uf.par)) { group[uf.root(i)].pb(i);\
    \ }\n        os << endl;\n        each(g, group) { os << g << endl; }\n      \
    \  return os;\n    }\n#endif  // }}}\n};\n\n//%snippet.end()%\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/graph/unionfind.hpp
  requiredBy:
  - library/cpp/graph/strongly_connected_components.hpp
  - library/cpp/graph/graph.hpp
  - library/cpp/graph/bellman_ford.hpp
  - library/cpp/graph/local_min_cycle.hpp
  - library/cpp/graph/gridgraph.cpp
  - library/cpp/graph/topological_sort.hpp
  - library/cpp/graph/two_sat.hpp
  timestamp: '2020-09-05 21:34:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - library/cpp/graph/tests/graph.lowlink.test.cpp
  - library/cpp/graph/tests/graph.bridge.test.cpp
  - library/cpp/graph/tests/bellman_ford.test.cpp
  - library/cpp/graph/tests/scc.test.cpp
  - library/cpp/graph/tests/graph.2dcost.test.cpp
  - library/cpp/graph/tests/graph.dijkstra.test.cpp
  - library/cpp/graph/tests/topological_sort.test.cpp
  - library/cpp/graph/tests/graph.kruskal.test.cpp
  - library/cpp/graph/tests/two_sat.test.cpp
documentation_of: library/cpp/graph/unionfind.hpp
layout: document
redirect_from:
- /library/library/cpp/graph/unionfind.hpp
- /library/library/cpp/graph/unionfind.hpp.html
title: library/cpp/graph/unionfind.hpp
---