#pragma once

// http://www.creativ.xyz/dump-cpp-652
using namespace std;
#include <bits/stdc++.h>

#include "../header.hpp"

#define DUMPOUT cerr  // where to dump. cout or cerr

#define cerrendl cerr << endl

namespace dump_macro {
stack<vector<string>> varnames;
stack<int> varidx;
}  // namespace dump_macro

#define dump(...)                                                            \
    {                                                                        \
        dump_macro::varnames.push([](string s) -> vector<string> {           \
            int n = s.size();                                                \
            vector<string> res;                                              \
            string tmp = "";                                                 \
            int parlevel = 0;                                                \
            int angle_level = 0;                                             \
            for (int i = 0; i < n; i++) {                                    \
                if (s[i] == '(') parlevel++;                                 \
                if (s[i] == ')') parlevel--;                                 \
                if (s[i] == '<') angle_level++;                              \
                if (s[i] == '>') angle_level--;                              \
                if (s[i] == ' ') continue;                                   \
                if (s[i] == ',' && parlevel == 0 && angle_level == 0) {      \
                    res.push_back(tmp);                                      \
                    tmp = "";                                                \
                } else {                                                     \
                    tmp += s[i];                                             \
                }                                                            \
            }                                                                \
            res.push_back(tmp);                                              \
            return res;                                                      \
        }(#__VA_ARGS__));                                                    \
        dump_macro::varidx.push(0);                                          \
        dump_func(__VA_ARGS__);                                              \
        DUMPOUT << "in [" << __LINE__ << ":" << __FUNCTION__ << "]" << endl; \
        dump_macro::varnames.pop();                                          \
        dump_macro::varidx.pop();                                            \
    }

#define dump_1d(x, n)                                                     \
    {                                                                     \
        DUMPOUT << "  " << #x << "[" << #n << "]"                         \
                << ":=> {";                                               \
        rep(i, n) { DUMPOUT << x[i] << (((i) == (n - 1)) ? "}" : ", "); } \
        DUMPOUT << " in [" << __LINE__ << "]" << endl;                    \
    }

#define dump_2d(x, n, m)                                      \
    {                                                         \
        DUMPOUT << "  " << #x << "[" << #n << "]"             \
                << "[" << #m << "]"                           \
                << ":=> \n";                                  \
        rep(i, n) rep(j, m) {                                 \
            DUMPOUT << ((j == 0) ? "     |" : " ") << x[i][j] \
                    << (((j) == (m - 1)) ? "|\n" : " ");      \
        }                                                     \
        DUMPOUT << "  in [" << __LINE__ << "]" << endl;       \
    }

void dump_func() {}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
    DUMPOUT << dump_macro::varnames.top()[dump_macro::varidx.top()] << ":"
            << head;
    if (sizeof...(Tail) == 0) {
        DUMPOUT << " ";
    } else {
        DUMPOUT << ", ";
    }
    ++dump_macro::varidx.top();
    dump_func(std::move(tail)...);
}

#include "prettyprint.hpp"