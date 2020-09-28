---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    #line 2 \"library/cpp/math/gbsgs/naive.cpp\"\n\nint solve() {\n    int a, b, p;\n\
    \    cin >> a >> b >> p;\n    int v = 1;\n    int res = INF;\n    rep(x, 0, p)\
    \ {\n        // dump(x, v);\n        if (v == b) {\n            cout << x << endl;\n\
    \            return 0;\n        }\n        v *= a;\n        v %= p;\n    }\n \
    \   cout << -1 << endl;\n    return 0;\n}\n\nsigned main() {  //{{{\n#ifdef INPUT_FROM_FILE\n\
    \    std::ifstream in(infile);\n    std::cin.rdbuf(in.rdbuf());\n#endif\n    solve();\n\
    \    return 0;\n}  //}}}\n"
  code: "#include \"../../header.hpp\"\n\nint solve() {\n    int a, b, p;\n    cin\
    \ >> a >> b >> p;\n    int v = 1;\n    int res = INF;\n    rep(x, 0, p) {\n  \
    \      // dump(x, v);\n        if (v == b) {\n            cout << x << endl;\n\
    \            return 0;\n        }\n        v *= a;\n        v %= p;\n    }\n \
    \   cout << -1 << endl;\n    return 0;\n}\n\nsigned main() {  //{{{\n#ifdef INPUT_FROM_FILE\n\
    \    std::ifstream in(infile);\n    std::cin.rdbuf(in.rdbuf());\n#endif\n    solve();\n\
    \    return 0;\n}  //}}}\n"
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/math/gbsgs/naive.cpp
  requiredBy: []
  timestamp: '2020-09-05 21:34:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/math/gbsgs/naive.cpp
layout: document
redirect_from:
- /library/library/cpp/math/gbsgs/naive.cpp
- /library/library/cpp/math/gbsgs/naive.cpp.html
title: library/cpp/math/gbsgs/naive.cpp
---