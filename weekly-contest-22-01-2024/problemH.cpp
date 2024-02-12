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

int main() {

    int t, n;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int arr[n];
        ll res = 0;
        ordered_set<pair<int, int>> my_set;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        for (int k = n - 1; k >= 0; k--) {
            my_set.insert({ arr[k], -(k + 1) });
            res += my_set.order_of_key({ arr[k], -(k + 1) });
        }
        cout << res << endl;
    }

    return 0;
}
