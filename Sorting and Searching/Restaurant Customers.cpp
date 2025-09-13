#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        times.push_back({a, 1});
        times.push_back({b, -1});
    }
    sort(times.begin(), times.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    // Line sweep algorithm
    int count = 0, max_count = 0;
    for (int i = 0; i < times.size(); i++) {
        count += times[i].second;
        max_count = max(max_count, count);
    }
    cout << max_count << endl;

    return 0;
}
