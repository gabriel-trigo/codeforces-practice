//REFERENCE: CLASS SLIDES https://docs.google.com/presentation/d/1PAZMHCWjNoffQsuHgXLKvPnkp3Iw3n_kbtNiWPiXhQ0/edit#slide=id.g2b2dc4359d9_4_82
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define INF LLONG_MAX
#define MOD 1000000007
#define endl '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

auto cmp = [] (vector<ll> a, vector<ll> b) {
    return a[0] < b[0];
};

int main() {

    ll n, a, b;
    ordered_set<ll> right_ends;
    vector<vector<ll>> segments;
    cin >> n;
    ll res[n];

    for (ll i = 0; i < n; i++) {
        cin >> a >> b;
        segments.push_back({ a, b, i });
        right_ends.insert(b);
    }
    sort(all(segments), cmp);

    for (auto& p : segments) {
        res[p[2]] = right_ends.order_of_key(p[1]);
        right_ends.erase(p[1]);
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
    return 0;
}
