#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    assert(1 <= n && n <= 1000000);
    vector<long double> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        assert(abs(a[i]) <= 1e5);
    }

    vector<long double> opt(n + 1);

    vector<pair<long double, long double>> intersections;
    for (int i = 1; i <= n; i++) {
        intersections.push_back({1, a[i]});
        while (intersections.size() >= 2) {
            auto p1 = intersections.back();
            auto p2 = intersections[intersections.size() - 2];
            if (p1.second / p1.first < p2.second / p2.first) {
                p1.first += p2.first;
                p1.second += p2.second;
                intersections.pop_back();
                intersections.pop_back();
                intersections.push_back(p1);
            }
            else break;
        }
        auto u = intersections.back();
        opt[i] = u.second / u.first;
    }

    vector<long double> res(n + 1);
    long double cost = 0;
    res[n] = opt[n];
    for (int i = n - 1; i >= 1; i--) {
        res[i] = min(res[i + 1], opt[i]);
    }

    for (int i = 1; i <= n; i++) {
        cost += (res[i] - a[i]) * (res[i] - a[i]);
    }
    cout << fixed << setprecision(10) << sqrt(cost) << endl;
    return 0;
}