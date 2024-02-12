#include <bits/stdc++.h>

using namespace std;

int main() {
    int f, n, v;
    cin >> f;

    for (int i = 0; i < f; i++) {
        cin >> n;
        // cout << n << '\n';
        vector<map<string, int> > vec;
        queue<map<string, int> > q;
        for (int j = 0; j < n; j++) {
            map<string, int> el;
            cin >> v;
            //cout << v << ' ' << j << '\n';
            el["idx"] = j;
            el["val"] = v;
            el["next"] = (j + 1) % n;
            el["prev"] = (j - 1) % n;
            vec.push_back(el);
        }
        int j = 0;
        while (j < n) {
            if (gcd(vec[j]["val"], vec[vec[j]["next"]]["val"]) == 1) {
                j++;
                q.push(vec[vec[i]["next"]]);
            }
            j++;
        };
        vector<int> res;
        while (q.size()) {
            map<string, int> pop = q.front(); q.pop();
            if (gcd(pop["val"], vec[pop["prev"]]["val"]) == 1) {
                res.push_back(pop["idx"] + 1);
            } else continue;

            if (vec[pop["prev"]] == pop["idx"]) continue;
            pop["prev"] = pop["idx"];
            vec[pop["next"]]["prev"] = pop["prev"];
            if (gcd(vec[pop["next"]]["val"], vec[pop["prev"]]["val"]) == 1) {
                q.push(vec[pop["next"]]);
            }
        }
        cout << res.size() << " ";
        for (int k = 0; k < res.size(); k++) {
            cout << res[k] << " ";
        }
        
    }
}
