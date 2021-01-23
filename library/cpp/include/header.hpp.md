---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "library/cpp/header.hpp"


    //%snippet.set(''header'')%

    //%snippet.fold()%

    #ifndef HEADER_H

    #define HEADER_H


    // template version 2.0

    #include <bits/stdc++.h>

    using namespace std;


    // varibable settings

    template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;


    #define _overload3(_1, _2, _3, name, ...) name

    #define _rep(i, n) repi(i, 0, n)

    #define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)

    #define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

    #define _rrep(i, n) rrepi(i, 0, n)

    #define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)

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

    template <class T, class U> inline void chmax(T &a, const U &b) { if ((a) < (b))
    (a) = (b); }

    template <class T, class U> inline void chmin(T &a, const U &b) { if ((a) > (b))
    (a) = (b); }

    template <typename X, typename T> auto make_table(X x, T a) { return vector<T>(x,
    a); }

    template <typename X, typename Y, typename Z, typename... Zs> auto make_table(X
    x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z, zs...); return vector<decltype(cont)>(x,
    cont); }


    template <class T> T cdiv(T a, T b){ assert(a >= 0 && b > 0); return (a+b-1)/b;
    }


    #define is_in(x, a, b) ((a) <= (x) && (x) < (b))

    #define uni(x) sort(all(x)); x.erase(unique(all(x)), x.end())

    #define slice(l, r) substr(l, r - l)


    typedef long long ll;

    typedef long double ld;


    template <typename T>

    using PQ = priority_queue<T, vector<T>, greater<T>>;

    void check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp; assert(cin.eof()
    == 1); }


    #if defined(PCM) || defined(LOCAL)

    #else

    #define dump(...) ;

    #define dump_1d(...) ;

    #define dump_2d(...) ;

    #define cerrendl ;

    #endif


    #endif /* HEADER_H */

    //%snippet.end()%

    #line 2 "library/cpp/include/header.hpp"

    '
  code: '#include "../header.hpp"'
  dependsOn:
  - library/cpp/header.hpp
  isVerificationFile: false
  path: library/cpp/include/header.hpp
  requiredBy: []
  timestamp: '2021-01-12 22:17:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/include/header.hpp
layout: document
redirect_from:
- /library/library/cpp/include/header.hpp
- /library/library/cpp/include/header.hpp.html
title: library/cpp/include/header.hpp
---