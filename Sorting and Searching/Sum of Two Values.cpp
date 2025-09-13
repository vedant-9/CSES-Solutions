#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int rem = target - a[i];
        if (mp.find(rem) != mp.end()) {
            cout << mp[rem] + 1 << " " << i + 1 << endl;
            return 0;
        }
        mp[a[i]] = i;
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
