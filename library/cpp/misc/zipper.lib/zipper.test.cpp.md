---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/misc/zipper.lib/zipper.hpp
    title: library/cpp/misc/zipper.lib/zipper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"library/cpp/misc/zipper.lib/zipper.test.cpp\"\n#define PROBLEM\
    \ \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
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
    #line 2 \"library/cpp/misc/zipper.lib/zipper.hpp\"\n\n//%snippet.set('zipper')%\n\
    \nstruct zipper {                             /*{{{*/\n    // unordered_map<long\
    \ long, int> zip_map;  // [2:0, 3:1, 5:2, 10:3] debug\u3057\u3065\u3089\u3044\n\
    \    map<long long, int> zip_map;  // [2:0, 3:1, 5:2, 10:3]\n    vector<long long>\
    \ _unzipper;            // [2, 3, 5, 10]\n    bool _is_build = false;\n    int\
    \ n = 0;\n\n    zipper(long long inf_value = INF) { /*{{{*/\n        _unzipper.push_back(-inf_value);\n\
    \        _unzipper.push_back(inf_value);\n    }                              \
    \                          /*}}}*/\n    zipper(vector<long long> a, long long\
    \ inf_value = INF) { /*{{{*/\n        _unzipper = vector<long long>(sz(a));\n\
    \        rep(i, sz(a)) { _unzipper[i] = a[i]; }\n        _unzipper.push_back(-inf_value);\n\
    \        _unzipper.push_back(inf_value);\n        build();\n    }            \
    \                  /*}}}*/\n    void add_value(long long lv) { /*{{{*/\n     \
    \   _unzipper.push_back(lv);\n        _is_build = false;\n    }              /*}}}*/\n\
    \    void build() { /*{{{*/\n        uni(_unzipper);\n        zip_map.clear();\n\
    \        n = sz(_unzipper);\n        rep(i, n) { zip_map[_unzipper[i]] = i; }\n\
    \        _is_build = true;\n    }                              /*}}}*/\n    vector<int>\
    \ zip(vector<long long> lvs) { /*{{{*/\n        if (!_is_build) assert(false);\n\
    \        int n = sz(lvs);\n        vector<int> res(n);\n        rep(i, n) res[i]\
    \ = zip_map[lvs[i]];\n        return res;\n    }                             \
    \ /*}}}*/\n    int zip(long long lv) { /*{{{*/\n        if (!_is_build) assert(false);\n\
    \        return zip_map[lv];\n    }                                          \
    \     /*}}}*/\n    int operator()(long long lv) { return zip(lv); }\n\n    long\
    \ long unzip(int sv) { /*{{{*/\n        if (!_is_build) assert(false);\n     \
    \   return _unzipper[sv];\n    }                              /*}}}*/\n    int\
    \ operator[](int sv) { return unzip(sv); }\n\n    int size() {return n;}\n\n#if\
    \ defined(PCM) || defined(LOCAL) /*{{{*/\n    friend ostream& operator<<(ostream&\
    \ os, const zipper& zp) {\n        os << endl;\n        os << \"_is_build: \"\
    \ << zp._is_build << endl;\n        os << \"zip_map:   \" << zp.zip_map << endl;\n\
    \        os << \"_unzipper:   \" << zp._unzipper << endl;\n        return os;\n\
    \    }\n#endif /*}}}*/\n};     /*}}}*/\n// How to use {{{\n// construct\n// auto\
    \ z = zipper(x); // x: vector<long long>;\n// auto z = zipper(x, 30*INF);\n\n\
    // auto z = zipper();\n// z.add_value(3);\n// z.add_value(5);\n// z.add_value(10);\n\
    // z.add_value(100000000);\n// z.build();\n\n// other method\n// z(x[i]); -> zipped\
    \ x[i]\n// z.unzip(z(x[i])) -> x[i];\n// z.zip(ll x) -> zipped x\n// z.zip(vl\
    \ v) -> zipped v\n// }}}\n\n//%snippet.end()%\n#line 4 \"library/cpp/misc/zipper.lib/zipper.test.cpp\"\
    \n\nsigned main() {\n    vector<ll> x({3, 10, 5, (ll)1e12});\n    auto z1 = zipper(x);\
    \  // x: vector<long long>;\n    dump(z1);\n    auto z2 = zipper(x, INF + 5);\n\
    \    dump(z2);\n\n    auto z3 = zipper();\n    z3.add_value(3);\n    z3.add_value(5);\n\
    \    z3.add_value(10);\n    z3.add_value((ll)1e12);\n    z3.build();\n    dump(z3);\n\
    \n    dump(z1);\n    dump(z1(5));\n    assert(z1(5) == 2);\n    assert(z1.unzip(4)\
    \ == (ll)1e12);\n    dump(z1.zip(x));\n    assert(z1.zip(x) == vector<int>({1,\
    \ 3, 2, 4}));\n\n    cout << \"Hello World\" << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"zipper.hpp\"\n\nsigned main() {\n    vector<ll> x({3, 10, 5, (ll)1e12});\n\
    \    auto z1 = zipper(x);  // x: vector<long long>;\n    dump(z1);\n    auto z2\
    \ = zipper(x, INF + 5);\n    dump(z2);\n\n    auto z3 = zipper();\n    z3.add_value(3);\n\
    \    z3.add_value(5);\n    z3.add_value(10);\n    z3.add_value((ll)1e12);\n  \
    \  z3.build();\n    dump(z3);\n\n    dump(z1);\n    dump(z1(5));\n    assert(z1(5)\
    \ == 2);\n    assert(z1.unzip(4) == (ll)1e12);\n    dump(z1.zip(x));\n    assert(z1.zip(x)\
    \ == vector<int>({1, 3, 2, 4}));\n\n    cout << \"Hello World\" << endl;\n   \
    \ return 0;\n}\n"
  dependsOn:
  - library/cpp/misc/zipper.lib/zipper.hpp
  - library/cpp/header.hpp
  isVerificationFile: true
  path: library/cpp/misc/zipper.lib/zipper.test.cpp
  requiredBy: []
  timestamp: '2020-09-29 00:07:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: library/cpp/misc/zipper.lib/zipper.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/misc/zipper.lib/zipper.test.cpp
- /verify/library/cpp/misc/zipper.lib/zipper.test.cpp.html
title: library/cpp/misc/zipper.lib/zipper.test.cpp
---