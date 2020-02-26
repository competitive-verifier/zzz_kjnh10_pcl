// template version 1.12
using namespace std;
#include <iostream>
#include <bits/stdc++.h>
 
// varibable settings
#define infile "../test/sample-1.in"
#define int long long //{{{
const int INF=1e18;
const int MOD=1e9+7; //}}}
 
// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;
 
template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;
 
#if defined(PCM) || defined(LOCAL)
  #include "lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}
 
//%snippet.set('SegmentTree2DRMQ')%
//%snippet.config({'alias':'2drmq'})%
struct segtree {
    int H, W;
    vector<vector<int>> dat;
    segtree(){}
    segtree(vector<vector<int>> &f) {
        H = W = 1;
        while(H < (int)f.size()) H <<= 1;
        while(W < (int)f[0].size()) W <<= 1;
        dat.assign(2*H-1,vector<int>(2*W-1,INF));
        init(f);
    }
    void init(vector<vector<int>> &f) {
        for (int i = 0; i < (int)f.size(); i++)
            for (int j = 0; j < (int)f[0].size(); j++)
                dat[i+H-1][j+W-1] = f[i][j];
        dump("hello");
        for (int i = 2*H-2; i > H-2; i--)
            for (int j = W-2; j >= 0; j--)
                dat[i][j] = min(dat[i][2*j+1], dat[i][2*j+2]);
        dump("hello1");
        for (int i = H-2; i >= 0; i--)
            for (int j = 0; j < 2*W-1; j++)
                dat[i][j] = min(dat[2*i+1][j], dat[2*i+2][j]);
        dump("hello2");
    }
    int minimum(int li, int lj, int ri, int rj) { return minimum_h(li,lj,ri,rj,0,H,0); }
    int minimum_h(int li, int lj, int ri, int rj, int si, int ti, int k) {
        if(ri <= si or ti <= li) return INF;
        if(li <= si and ti <= ri) return minimum_w(lj,rj,0,W,k,0);
        const int mi = (si+ti)/2;
        return min(minimum_h(li,lj,ri,rj,si,mi,2*k+1), minimum_h(li,lj,ri,rj,mi,ti,2*k+2));
    }
    int minimum_w(int lj, int rj, int sj, int tj, int i, int k) {
        if(rj <= sj or tj <= lj) return INF;
        if(lj <= sj and tj <= rj) return dat[i][k];
        const int mj = (sj+tj)/2;
        return min(minimum_w(lj,rj,sj,mj,i,2*k+1),minimum_w(lj,rj,mj,tj,i,2*k+2));
    }
};
//%snippet.end()%