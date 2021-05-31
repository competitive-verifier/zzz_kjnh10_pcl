---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/array/bit.hpp
    title: library/cpp/array/bit.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"library/cpp/array/bit.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#line 2 \"library/cpp/header.hpp\"\n\n//%snippet.set('header')%\n//%snippet.fold()%\n\
    #ifndef HEADER_H\n#define HEADER_H\n\n// template version 2.0\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// varibable settings\ntemplate <class T> constexpr T\
    \ inf = numeric_limits<T>::max() / 2.1;\n\n#define _overload3(_1, _2, _3, name,\
    \ ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for (ll i\
    \ = (ll)(a); i < (ll)(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi,\
    \ _rep, )(__VA_ARGS__)\n#define _rrep(i, n) rrepi(i, 0, n)\n#define rrepi(i, a,\
    \ b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)\n#define r_rep(...) _overload3(__VA_ARGS__,\
    \ rrepi, _rrep, )(__VA_ARGS__)\n#define each(i, a) for (auto &&i : a)\n#define\
    \ all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n#define pb(a)\
    \ push_back(a)\n#define mp(a, b) make_pair(a, b)\n#define mt(...) make_tuple(__VA_ARGS__)\n\
    #define ub upper_bound\n#define lb lower_bound\n#define lpos(A, x) (lower_bound(all(A),\
    \ x) - A.begin())\n#define upos(A, x) (upper_bound(all(A), x) - A.begin())\ntemplate\
    \ <class T, class U> inline void chmax(T &a, const U &b) { if ((a) < (b)) (a)\
    \ = (b); }\ntemplate <class T, class U> inline void chmin(T &a, const U &b) {\
    \ if ((a) > (b)) (a) = (b); }\ntemplate <typename X, typename T> auto mv(X x,\
    \ T a) { return vector<T>(x, a); }\ntemplate <typename X, typename Y, typename\
    \ Z, typename... Zs> auto mv(X x, Y y, Z z, Zs... zs) { auto cont = mv(y, z, zs...);\
    \ return vector<decltype(cont)>(x, cont); }\n\ntemplate <class T> T cdiv(T a,\
    \ T b){ assert(a >= 0 && b > 0); return (a+b-1)/b; }\n\n#define is_in(x, a, b)\
    \ ((a) <= (x) && (x) < (b))\n#define uni(x) sort(all(x)); x.erase(unique(all(x)),\
    \ x.end())\n#define slice(l, r) substr(l, r - l)\n\n#include <cxxabi.h>\nstring\
    \ demangle(const char * name) {\n    size_t len = strlen(name) + 256;\n    char\
    \ output_buffer[len];\n    int status = 0;\n    return string(abi::__cxa_demangle(name,\
    \ output_buffer, &len, &status));\n}\ntemplate<class T> string type(T x){ return\
    \ demangle(typeid(x).name()); }\n\ntypedef long long ll;\ntypedef long double\
    \ ld;\n\ntemplate <typename T>\nusing PQ = priority_queue<T, vector<T>, greater<T>>;\n\
    void check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp; assert(cin.eof()\
    \ == 1); }\n\n#if defined(PCM) || defined(LOCAL)\n#else\n#define dump(...) ;\n\
    #define dump_1d(...) ;\n#define dump_2d(...) ;\n#define cerrendl ;\n#endif\n\n\
    #endif /* HEADER_H */\n//%snippet.end()%\n#line 3 \"library/cpp/array/bit.hpp\"\
    \n\n//%snippet.set('bit')%\n\ntemplate <typename T = ll>\nstruct bit {  //{{{\n\
    \    int n;\n    vector<T> dat;\n    vector<T> raw;\n\n    bit(int _n = 0) { \
    \ //{{{\n        n = _n;\n        dat = vector<T>(n);\n        raw = vector<T>(n);\n\
    \    }  //}}}\n\n    bit(vector<T> a) {  // {{{\n        n = (int)a.size();\n\
    \        dat = vector<T>(n);\n        raw = vector<T>(n);\n        for (int i\
    \ = 0; i < n; i++) {\n            add(i, a[i]);\n            raw[i] = a[i];\n\
    \        }\n    }  //}}}\n\n    T _rsum(int i) {  //{{{ [0, i]\n        T s =\
    \ 0;\n        while (i >= 0) {\n            s += dat[i];\n            i = (i &\
    \ (i + 1)) - 1;\n        }\n        return s;\n    }  //}}}\n\n    T query(int\
    \ l, int r) {  //{{{  [l, r)\n        if (l > r - 1) return 0;\n        return\
    \ _rsum(r - 1) - _rsum(l - 1);\n    }  //}}}\n\n    void add(int i, T x) {  //{{{\n\
    \        raw[i] += x;\n        while (i < n) {\n            dat[i] += x;\n   \
    \         i |= i + 1;\n        }\n    }  //}}}\n\n    int lower_bound(T x) { \
    \ // a[0]+...+a[ret] >= x{{{\n        int ret = -1;\n        int k = 1;\n    \
    \    while (2 * k <= n) k <<= 1;\n        for (; k > 0; k >>= 1) {\n         \
    \   if (ret + k < n && dat[ret + k] < x) {\n                x -= dat[ret + k];\n\
    \                ret += k;\n            }\n        }\n        return ret + 1;\n\
    \    }  //}}}\n\n    #if defined(PCM) || defined(LOCAL)\n    friend ostream& operator<<(ostream&\
    \ os, bit<T>& b) {  //{{{\n        os << endl << \"  raw:\" << b.raw << endl;\n\
    \        vector<T> acum;\n        rep(i, b.n) { acum.pb(b.sum(i)); }\n       \
    \ os << \"  acm:\" << acum << endl;\n        return os;\n    }  //}}}\n    #endif\n\
    };     //}}}\n\n//%snippet.end()%\n#line 4 \"library/cpp/array/bit.test.cpp\"\n\
    \nint main(){\n    ll N,Q;cin>>N>>Q;\n    vector<ll> a(N);\n    rep(i, N) {\n\
    \        cin>>a[i];\n    }\n\n    bit<ll> b(a);\n    rep(q, Q){\n        int t;cin>>t;\n\
    \        if (t==0){\n            int i;cin>>i;\n            ll x;cin>>x;\n   \
    \         b.add(i, x);\n        }\n        if (t==1){\n            int l,r;cin>>l>>r;\n\
    \            cout << b.query(l, r) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"bit.hpp\"\n\nint main(){\n    ll N,Q;cin>>N>>Q;\n    vector<ll> a(N);\n\
    \    rep(i, N) {\n        cin>>a[i];\n    }\n\n    bit<ll> b(a);\n    rep(q, Q){\n\
    \        int t;cin>>t;\n        if (t==0){\n            int i;cin>>i;\n      \
    \      ll x;cin>>x;\n            b.add(i, x);\n        }\n        if (t==1){\n\
    \            int l,r;cin>>l>>r;\n            cout << b.query(l, r) << endl;\n\
    \        }\n    }\n}\n"
  dependsOn:
  - library/cpp/array/bit.hpp
  - library/cpp/header.hpp
  isVerificationFile: true
  path: library/cpp/array/bit.test.cpp
  requiredBy: []
  timestamp: '2021-05-31 23:41:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: library/cpp/array/bit.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/array/bit.test.cpp
- /verify/library/cpp/array/bit.test.cpp.html
title: library/cpp/array/bit.test.cpp
---