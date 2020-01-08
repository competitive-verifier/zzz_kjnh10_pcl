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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: codes/cpp/segtree/segment_tree.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#be3aa2b43feda595aa89da363e1e6700">codes/cpp/segtree</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/segtree/segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-05 18:24:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

#include <bits/stdc++.h>
using namespace std;

//%snippet.set('SegmentTree')%
//%snippet.config({'alias':'rmq'})%

template<typename T, typename F>
struct SegmentTree { // {{{
  private:
    int n; 
    int N;  // 
    vector<T> node;
    F merge;
    T identity;

  public:
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

    // query for [l, r)
    T query(int a, int b, int k=0, int l=0, int r=-1) {
      if(r < 0) r = N;
      if(r <= a || b <= l) return identity;
      if(a <= l && r <= b) return node[k];

      T vl = query(a, b, 2*k+1, l, (l+r)/2);
      T vr = query(a, b, 2*k+2, (l+r)/2, r);
      return merge(vl, vr);
    }

    friend ostream& operator<<(ostream &os, SegmentTree<T, F>& sg){ //
      os << "[";
      for(int i=0; i<sg.n; i++){
        os << sg[i] << (i==sg.n-1?"]\n":", ");
      }
      return os;
    }
};
// }}}
// Sample:
  // -----------------------------------------------
  // auto mymin=[&](auto a, auto b){return min(a,b);};
  // SegmentTree<int, decltype(mymin)> seg(a, mymin, 1e18);

  // auto mymax=[&](auto a, auto b){return max(a,b);};
  // SegmentTree<int, decltype(mymax)> seg(a, mymax, -1e18);

  // auto add=[&](auto a, auto b){return a+b;};
  // SegmentTree<int, decltype(add)> seg(a, add, 0);
  // -----------------------------------------------

//%snippet.end()%

int main() {
  vector<int> a = {1, 4, -2, 3, 6, 7};
  auto f=[&](auto a, auto b){return max(a,b);};
  SegmentTree<int, decltype(f)> seg(a, f, -1e9);

  assert(seg.query(0, 8)==7);
  cout << seg.query(0, 8) << endl;
  cout << seg.query(0, 10) << endl;
  cout << seg.query(-3, 10) << endl;
  cout << seg[0] << endl;
  cout << seg[1] << endl;
  cout << seg[2] << endl;
  cout << seg << endl;
  seg.update(2, 10);
  cout << seg.query(0, 8) << endl;

  // doubleなど他の型でも動くかチェック
  auto mymax=[&](auto a, auto b){return max(a,b);};
  vector<double> p(6);
  SegmentTree<double, decltype(mymax)> segd(p, mymax, -1e18);
  segd.update(0, 1.2);
  segd.update(1, 1.4);
  segd.update(2, 1.6);
  double v = segd.query(0, 6);
  cout << v << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/segtree/segment_tree.cpp"
// http://tsutaj.hatenablog.com/entry/2017/03/29/204841

#include <bits/stdc++.h>
using namespace std;

//%snippet.set('SegmentTree')%
//%snippet.config({'alias':'rmq'})%

template<typename T, typename F>
struct SegmentTree { // {{{
  private:
    int n; 
    int N;  // 
    vector<T> node;
    F merge;
    T identity;

  public:
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

    // query for [l, r)
    T query(int a, int b, int k=0, int l=0, int r=-1) {
      if(r < 0) r = N;
      if(r <= a || b <= l) return identity;
      if(a <= l && r <= b) return node[k];

      T vl = query(a, b, 2*k+1, l, (l+r)/2);
      T vr = query(a, b, 2*k+2, (l+r)/2, r);
      return merge(vl, vr);
    }

    friend ostream& operator<<(ostream &os, SegmentTree<T, F>& sg){ //
      os << "[";
      for(int i=0; i<sg.n; i++){
        os << sg[i] << (i==sg.n-1?"]\n":", ");
      }
      return os;
    }
};
// }}}
// Sample:
  // -----------------------------------------------
  // auto mymin=[&](auto a, auto b){return min(a,b);};
  // SegmentTree<int, decltype(mymin)> seg(a, mymin, 1e18);

  // auto mymax=[&](auto a, auto b){return max(a,b);};
  // SegmentTree<int, decltype(mymax)> seg(a, mymax, -1e18);

  // auto add=[&](auto a, auto b){return a+b;};
  // SegmentTree<int, decltype(add)> seg(a, add, 0);
  // -----------------------------------------------

//%snippet.end()%

int main() {
  vector<int> a = {1, 4, -2, 3, 6, 7};
  auto f=[&](auto a, auto b){return max(a,b);};
  SegmentTree<int, decltype(f)> seg(a, f, -1e9);

  assert(seg.query(0, 8)==7);
  cout << seg.query(0, 8) << endl;
  cout << seg.query(0, 10) << endl;
  cout << seg.query(-3, 10) << endl;
  cout << seg[0] << endl;
  cout << seg[1] << endl;
  cout << seg[2] << endl;
  cout << seg << endl;
  seg.update(2, 10);
  cout << seg.query(0, 8) << endl;

  // doubleなど他の型でも動くかチェック
  auto mymax=[&](auto a, auto b){return max(a,b);};
  vector<double> p(6);
  SegmentTree<double, decltype(mymax)> segd(p, mymax, -1e18);
  segd.update(0, 1.2);
  segd.update(1, 1.4);
  segd.update(2, 1.6);
  double v = segd.query(0, 6);
  cout << v << endl;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
