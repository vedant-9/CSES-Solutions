#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        times.push_back({a, b});
    }

    sort(times.begin(), times.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        return a.second < b.second;
    });

    int count = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        if (times[i].first >= end) {
            count++;
            end = times[i].second;
        }
    }
    cout << count << endl;

    return 0;
}