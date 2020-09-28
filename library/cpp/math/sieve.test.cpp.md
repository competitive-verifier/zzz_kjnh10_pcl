---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/math/sieve.hpp
    title: library/cpp/math/sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"library/cpp/math/sieve.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n//%snippet.fold()%\n\
    #ifndef HEADER_H\n#define HEADER_H\n\n// template version 2.0\nusing namespace\
    \ std;\n#include <bits/stdc++.h>\n\n// varibable settings\nconst long long INF\
    \ = 1e18;\ntemplate <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;\n\
    \n#define _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0,\
    \ n)\n#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n#define rep(...)\
    \ _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n#define _rrep(i, n) rrepi(i,\
    \ 0, n)\n#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)\n\
    #define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)\n#define\
    \ each(i, a) for (auto &&i : a)\n#define all(x) (x).begin(), (x).end()\n#define\
    \ sz(x) ((int)(x).size())\n#define pb(a) push_back(a)\n#define mp(a, b) make_pair(a,\
    \ b)\n#define mt(...) make_tuple(__VA_ARGS__)\n#define ub upper_bound\n#define\
    \ lb lower_bound\n#define lpos(A, x) (lower_bound(all(A), x) - A.begin())\n#define\
    \ upos(A, x) (upper_bound(all(A), x) - A.begin())\ntemplate <class T, class U>\
    \ inline void chmax(T &a, const U &b) { if ((a) < (b)) (a) = (b); }\ntemplate\
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
    #line 2 \"library/cpp/math/sieve.hpp\"\n\n//%snippet.set('sieve')%\n//%snippet.config({'alias':'prime_factor_by_sieve'})%\n\
    //%snippet.fold()%\n\nstruct Sieve {/*{{{*/\n    // \u30A8\u30E9\u30C8\u30B9\u30C6\
    \u30CD\u30B9\u306E\u3075\u308B\u3044 O(NloglogN)\n    ll n;                  \
    \            // n: max number for defined f and primes\n    vector<ll> f;    \
    \                  // [-1, 2, 3, 2, 5, 2, 7, 2, 3, ....]\n    vector<ll> primes;\
    \                 // [2, 3, 5, .......]\n    Sieve(ll n = 1) : n(n), f(n + 1)\
    \ { /*{{{*/\n        f[0] = f[1] = -1;\n        for (ll i = 2; i <= n; ++i) {\n\
    \            if (f[i]) continue;\n            primes.push_back(i);\n         \
    \   f[i] = i;\n            for (ll j = i * i; j <= n; j += i) {\n            \
    \    if (!f[j]) f[j] = i;\n            }\n        }\n    } /*}}}*/\n    bool is_prime(ll\
    \ x) {\n        if (x <= n) return f[x] == x; \n        return sz(factor_list(x))\
    \ == 1;\n    }\n\n    vector<ll> factor_list(ll x) { /*{{{*/\n        assert(x\
    \ <= n*n); // \u3053\u308C\u304C\u6E80\u305F\u3055\u308C\u306A\u3044\u3068\u6B63\
    \u3057\u304F\u8A08\u7B97\u3055\u308C\u306A\u3044\u53EF\u80FD\u6027\u304C\u3042\
    \u308B\u3002\n\n        vector<ll> res;\n        if (x <= n) {\n            while\
    \ (x != 1) {\n                res.push_back(f[x]);\n                x /= f[x];\n\
    \            }\n        }\n        else {\n            for (ll i = 0; primes[i]\
    \ * primes[i] <= x; i++) {\n                while (x % primes[i] == 0) {\n   \
    \                 res.pb(primes[i]);\n                    x /= primes[i];\n  \
    \              }\n            }\n            if (x != 1) res.pb(x);\n        }\n\
    \n        return res;  // [2, 3, 3, 5, 5, 5.....]\n    }                /*}}}*/\n\
    \n    vector<pair<ll, ll>> prime_factor(ll x) { /*{{{*/\n        // just change\
    \ fl vector to map form\n        vector<ll> fl = factor_list(x);\n        if (fl.size()\
    \ == 0) return {};\n        vector<pair<ll, ll>> res = {mp(fl[0], 0)};\n     \
    \   for (ll p : fl) {\n            if (res.back().first == p) {\n            \
    \    res.back().second++;\n            } else {\n                res.emplace_back(p,\
    \ 1);\n            }\n        }\n        return res;  // [(2,1), (3,2), (5,3),\
    \ .....]\n    }                /*}}}*/\n};/*}}}*/\nSieve sv(1e6);\n// How to use\n\
    \    // sv.primes            // \u7D20\u6570\u306E\u30EA\u30B9\u30C8\n    // sv.prime_factor(x);\
    \  // \u7D20\u56E0\u6570\u5206\u89E3\n\n//%snippet.end()%\n#line 3 \"library/cpp/math/sieve.test.cpp\"\
    \n\nbool is_prime_naive(ll n) { /*{{{*/\n    for (ll i = 2; i * i <= n; i++) {\n\
    \        if (n % i == 0) return false;\n    }\n    return n != 1;\n} /*}}}*/\n\
    \nuint64_t rng() {\n    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return uniform_int_distribution<uint64_t>(0, sv.n * 2)(x);\n}\n\nvoid test(ll\
    \ m){\n    // dump(m);\n\n    auto ps = sv.prime_factor(m);\n    // dump(ps);\n\
    \n    ll restore = 1;\n    each(p, ps){\n        if (is_prime_naive(p.first)==false)\
    \ assert(false);\n        rep(i, p.second) restore *= p.first;\n    }\n    assert(restore\
    \ == m);\n}\n\nint main(){\n    assert(sz(sv.prime_factor(1))==0);\n    // test(sv.n\
    \ * sv.n + 1);  // make sure that this will fail\n\n    int num = 100000;\n  \
    \  while(num--){\n        ll m = rng();\n        test(m);\n    }\n\n    cout <<\
    \ \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"sieve.hpp\"\n\nbool is_prime_naive(ll n) { /*{{{*/\n    for (ll i\
    \ = 2; i * i <= n; i++) {\n        if (n % i == 0) return false;\n    }\n    return\
    \ n != 1;\n} /*}}}*/\n\nuint64_t rng() {\n    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return uniform_int_distribution<uint64_t>(0, sv.n * 2)(x);\n}\n\nvoid test(ll\
    \ m){\n    // dump(m);\n\n    auto ps = sv.prime_factor(m);\n    // dump(ps);\n\
    \n    ll restore = 1;\n    each(p, ps){\n        if (is_prime_naive(p.first)==false)\
    \ assert(false);\n        rep(i, p.second) restore *= p.first;\n    }\n    assert(restore\
    \ == m);\n}\n\nint main(){\n    assert(sz(sv.prime_factor(1))==0);\n    // test(sv.n\
    \ * sv.n + 1);  // make sure that this will fail\n\n    int num = 100000;\n  \
    \  while(num--){\n        ll m = rng();\n        test(m);\n    }\n\n    cout <<\
    \ \"Hello World\" << endl;\n}\n"
  dependsOn:
  - library/cpp/math/sieve.hpp
  - library/cpp/header.hpp
  isVerificationFile: true
  path: library/cpp/math/sieve.test.cpp
  requiredBy: []
  timestamp: '2020-09-05 21:34:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: library/cpp/math/sieve.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/math/sieve.test.cpp
- /verify/library/cpp/math/sieve.test.cpp.html
title: library/cpp/math/sieve.test.cpp
---