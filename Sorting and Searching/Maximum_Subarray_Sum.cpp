#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_subarray_sum = -1e18, cur_sum = 0;
    for (int i = 0; i < n; i++) {
        cur_sum += a[i];
        if (cur_sum > max_subarray_sum) max_subarray_sum = cur_sum;
        if (cur_sum < 0) cur_sum = 0;
    }

    cout << max_subarray_sum << endl;

    return 0;
}