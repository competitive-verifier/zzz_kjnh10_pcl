// (参考) https://www.slideshare.net/Proktmr/ss-138534092

// template version 1.15
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

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
#define mt(a, b, c) make_tuple(a, b, c)
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define slice(l, r) substr(l, r-l)

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
  #define cerrendl 42
#endif
//}}}

//%snippet.set('tree')%

template<typename T> struct SegmentTree { // {{{
  private:
    using F = function<T(T,T)>;
    int n;  // 元の配列のサイズ
    int N;  // n以上の最小の2冪
    vector<T> node;
    F merge;
    T identity;

  public:
    SegmentTree(){}
    SegmentTree(vector<T> a, F f, T id):merge(f), identity(id) {
      n = a.size();
      N = 1; while(N < n) N *= 2;
      node.resize(2*N-1, identity);
      for(int i=0; i<n; i++) node[i+N-1] = a[i];
      for(int i=N-2; i>=0; i--) node[i] = merge(node[2*i+1], node[2*i+2]);
    }
    SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id) {}

    T& operator[](int i) { return node[i+N-1]; }

    void update(int x, T val) {
      x += (N - 1);
      node[x] = val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = merge(node[2*x+1], node[2*x+2]);
      }
    }

    void add(int x, T val) {
      x += (N - 1);
      node[x] += val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = merge(node[2*x+1], node[2*x+2]);
      }
    }

    // query for [l, r)
    T query(int a, int b, int k=0, int l=0, int r=-1) {
      if(r < 0) r = N;
      if(r <= a || b <= l) return identity;
      if(a <= l && r <= b) return node[k];

      T vl = query(a, b, 2*k+1, l, (l+r)/2);
      T vr = query(a, b, 2*k+2, (l+r)/2, r);
      return merge(vl, vr);
    }

    friend ostream& operator<<(ostream &os, SegmentTree<T>& sg){ //
      os << "[";
      for(int i=0; i<sg.n; i++){
        os << sg[i] << (i==sg.n-1?"]\n":", ");
      }
      return os;
    }
};
// }}}
struct tree{/*{{{*/
  int n;
  vector<int> par;  // par[i]: dfs木における親
  vector<int> cost;  // par[i]: dfs木における親への辺のコスト
  vector<int> dfstrv; // dfstrv[i]: dfs木でi番目に訪れるノード。dpはこれを逆順に回す
  vector<int> ord;  // ord[u]: uのdfs木における訪問順
  vector<int> pos;  // pos[u]: uのdfs終了時のカウンター
  vector<int> psize; // psize[u]: uのpartial tree size
  // vの部分木は[ord[v], pos[v])
  // ordとdfstrvは逆変換

  vector<int> depth;  // depth[i]: dfs木でのiの深さ
  vector<vector<pair<int, int>>> g; // 辺(隣接リスト)
  vector<vector<int>> children;
  vector<int> euler_tour;
  vector<int> et_fpos;  // euler_tour first occurence position
  SegmentTree<int> _seg;  // seg(map(ord, euler_tour), mymin, 1e18)

  int _counter = 0;

  tree(int n):
    n(n),par(n),cost(n,1),ord(n),pos(n),psize(n),depth(n),g(n),children(n),et_fpos(n)
  {};

  void add_edge(int u, int v, int cost){
    g[u].emplace_back(v, cost);
    g[v].emplace_back(u, cost);
  }
  void add_edge(int u, int v){
    g[u].emplace_back(v, 1);
    g[v].emplace_back(u, 1);
  }

  void build(int root){
    _counter = 0;
    par[root] = -1;
    cost[root] = INF;
    _dfs_tree(root, -1, 0);
    _dfs_et(root);
    vector<int> ini(2*n-1); rep(i, 2*n-1) ini[i] = ord[euler_tour[i]];
    _seg = SegmentTree<int>(ini, [](auto a, auto b){return min(a,b);}, 1e18);
  }

  void _dfs_tree(int u, int pre, int _depth){
    dfstrv.pb(u);
    ord[u] = _counter;
    depth[u] = _depth;

    _counter++;
    each(el, g[u]){
      int v = el.first;
      if (v==pre) continue;

      children[u].pb(v);
      par[v] = u;
      cost[v] = el.second;
      _dfs_tree(v, u, _depth+1);
    }
    pos[u] = _counter;
    psize[u] = pos[u] - ord[u];
  }

  void _dfs_et(int u){
    et_fpos[u] = euler_tour.size();
    euler_tour.pb(u);
    each(v, children[u]){
      _dfs_et(v);
      euler_tour.pb(u);
    }
  }

  int lca(int u, int v){
    if (u==v) return u;
    if (et_fpos[u]>et_fpos[v]) swap(u, v);
    return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];
  }
};/*}}}*/
  // ----sample------
  // int n,q;cin>>n>>q;
  // tree tr(n);
  // rep(u, 1, n){
  //   int p;cin>>p;
  //   tr.add_edge(p,u);
  // }
  // tr.build(0);
  // rep(_, q){
  //   int u,v;cin>>u>>v;
  //   cout << tr.lca(u, v) << endl;
  // }

//%snippet.end()%


signed main() {
  // tree tr(8);
  // tr.add_edge(0, 1, 1);
  // tr.add_edge(0, 2, 1);
  // tr.add_edge(1, 3, 1);
  // tr.add_edge(1, 4, 1);
  // tr.add_edge(4, 6, 1);
  // tr.add_edge(4, 7, 1);
  // tr.add_edge(2, 5, 1);
  //
  // tr.build(2);
  // dump(tr.par);
  // dump(tr.dfstrv);
  // dump(tr.ord);
  // dump(tr.pos);
  // dump(tr.depth);
  // dump(tr.children);
  // dump(tr.euler_tour);
  // dump(tr.et_fpos);
  // dump(tr.lca(3, 5));

  // https://judge.yosupo.jp/problem/lca
  int n,q;cin>>n>>q;
  tree tr(n);
  rep(u, 1, n){
    int p;cin>>p;
    tr.add_edge(p,u);
  }
  tr.build(0);
  rep(_, q){
    int u,v;cin>>u>>v;
    cout << tr.lca(u, v) << endl;
  }
}
