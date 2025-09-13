#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> prices(n), max_prices(m);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < m; i++) cin >> max_prices[i];

    multiset<int> prices_set(prices.begin(), prices.end());

    for (int i = 0; i < m; i++) {
        auto it = prices_set.upper_bound(max_prices[i]);
        if (it == prices_set.begin()) {
            cout << -1 << endl;
        } else {
            it--;
            cout << *it << endl;
            prices_set.erase(it);
        }
    }

    return 0;
}
