#include <bits/stdc++.h>

using namespace std;

int main() {
    long double xa, xb, xc, ya, yb, yc, R, P;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> R >> P;
    xa -= xc;
    ya -= yc;
    xb -= xc;
    yb -= yc;

    long double a = ya - yb;
    long double b = xb - xa;
    long double c = xa * yb - ya * xb;
    long double d = a * a + b * b;
    if (c * c >= d * R * R) {
        cout << "NO";
    } else {
        d = abs(c) / sqrt(d);
        long double angle = acos(d / R);
        long double area = angle * R * R;
        long double e = sqrt(R * R - d * d);
        long double s = d * e;
        area -= s;
        long double per = area / (acos(-1) * R * R) * 100;
        if (abs(per - P) <= 5) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
}