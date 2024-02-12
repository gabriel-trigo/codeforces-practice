#include <iostream>
#include<bits/stdc++.h>

typedef long long ll;
const ll MAXN = 100001;

ll t[4 * MAXN];
std::pair<int, int> tt[4 * MAXN];
void build(std::vector<ll> a, ll v, ll tl, ll tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    ll tm = (tl + tr) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    t[v] = t[v*2] + t[v*2+1];
  }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r) {
  if (l > r) 
    return 0;
  if (l == tl && r == tr) {
    return t[v];
  }
  ll tm = (tl + tr) / 2;
  return sum(v*2, tl, tm, l, std::min(r, tm))
         + sum(v*2+1, tm+1, tr, std::max(l, tm+1), r);
}

void update(ll v, ll tl, ll tr,
            ll pos, ll new_val) {
  if (tl == tr) t[v] = new_val;
  else {
    ll tm = (tl + tr) / 2;
    if (pos <= tm) update(v*2, tl, tm, pos, new_val);
    else update(v*2+1, tm+1, tr, pos, new_val);
    t[v] = t[v*2] + t[v*2+1];
  }
}

std::pair<ll, ll> pair_max(std::pair<ll, ll> p1, std::pair<ll, ll> p2) {
    if (p1.second > p2.second) return p1;
    return p2;
}


void build_max(std::vector<std::pair<ll, ll>> a, ll v, ll tl, ll tr) {
  if (tl == tr) {
    tt[v] = a[tl];
  } else {
    ll tm = (tl + tr) / 2;
    build_max(a, v*2, tl, tm);
    build_max(a, v*2+1, tm+1, tr);
    tt[v] = pair_max(tt[v*2], tt[v*2+1]);
  }
}

std::pair<ll, ll> max_max(ll v, ll tl, ll tr, ll l, ll r) {
  if (l > r) 
    return { -1, -10e10 };
  if (l == tl && r == tr) {
    return tt[v];
  }
  ll tm = (tl + tr) / 2;
  return pair_max(max_max(v*2, tl, tm, l, std::min(r, tm)),
    max_max(v*2+1, tm+1, tr, std::max(l, tm+1), r));
}

void max_update(ll v, ll tl, ll tr,
            ll pos, std::pair<ll, ll> new_val) {
  if (tl == tr) tt[v] = new_val;
  else {
    ll tm = (tl + tr) / 2;
    if (pos <= tm) max_update(v*2, tl, tm, pos, new_val);
    else max_update(v*2+1, tm+1, tr, pos, new_val);
    tt[v] = pair_max(tt[v*2], tt[v*2+1]);
  }
}


int main() {
    ll n, m;
    ll temp;
    std::vector<ll> a;
    std::vector<std::pair<ll, ll>> aa;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        a.push_back(temp);
        aa.push_back({i, temp});
    }
    build(a, 1, 0, n - 1);
    build_max(aa, 1, 0, n - 1);

    int type;
    ll l;
    ll r;
    ll x;
    ll k;
    std::pair<ll, ll> res;


    for (int i = 0; i < m; i++) {
        std::cin >> type;
        if (type == 1) {
            std::cin >> l >> r;
            l--;
            r--;
            std::cout << sum(1, 0, n - 1, l, r) << '\n';
        } else if (type == 2) {
            std::cin >> l >> r >> x;
            l--;
            r--;
            while (true) {
                res = max_max(1, 0, n - 1, l, r);
                if (res.second < x) break;
                max_update(1, 0, n - 1, res.first, {res.first, res.second % x});
                update(1, 0, n - 1, res.first, res.second % x);
            }
        } else {
            std::cin >> k >> x;
            k--;
            max_update(1, 0, n - 1, k, {k, x});
            update(1, 0, n - 1, k, x);
        }
    }
    return 0;
}
