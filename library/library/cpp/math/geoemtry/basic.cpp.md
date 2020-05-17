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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :warning: library/cpp/math/geoemtry/basic.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#cef394f212ede05bd80525fdb8bcaf21">library/cpp/math/geoemtry</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/math/geoemtry/basic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-18 01:50:00+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class T> T dist(T x1, T y1, T x2, T y2){ return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); }
template<class T> T rad(T x){ return x * M_PI / 180.0; }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/cpp/math/geoemtry/basic.cpp"
template<class T> T dist(T x1, T y1, T x2, T y2){ return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); }
template<class T> T rad(T x){ return x * M_PI / 180.0; }

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

