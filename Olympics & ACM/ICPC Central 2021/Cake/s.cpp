#include <bits/stdc++.h>
using namespace std;

int checkCollision(double xA, double yA, double xB, double yB, double xC, double yC, double radius, double *x1, double *y1, double *x2, double *y2) {
    double xBA = xB - xA;
    double yBA = yB - yA;
    double xCA = xC - xA;
    double yCA = yC - yA;

    double a = xBA * xBA + yBA * yBA;
    double b = xBA * xCA + yBA * yCA;
    double c = xCA * xCA + yCA * yCA - radius * radius;

    double p = b / a;
    double q = c / a;

    double disc = p * p - q;
    if (disc < 0) return 0;
    else if (disc == 0) return 1;
    else {

        double t = sqrt(disc);
        double scalingFactorAB1 = -p + t;
        double scalingFactorAB2 = -p - t;

        *x1 = xA - xBA * scalingFactorAB1;
        *y1 = yA - yBA * scalingFactorAB1;
        *x2 = xA - xBA * scalingFactorAB2;
        *y2 = yA - yBA * scalingFactorAB2;
        return 2;
    }
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    freopen("18.in", "r", stdin);
    freopen("18.out", "w", stdout);
    double xA, yA, xB, yB, xC, yC, R, request;
    cin>>xA>>yA>>xB>>yB>>xC>>yC>>R>>request;
    double x1, y1, x2, y2;
    //int _count = checkCollision(3, 0, 3, -5, 3, -5, 3, &x1, &y1, &x2, &y2);
    int _count = checkCollision(xA, yA, xB, yB, xC, yC, R, &x1, &y1, &x2, &y2);
    if (_count <= 1) {
        cout<<"NO";
        return 0;
    }

    double d = distance(x1, y1, x2, y2);
    double h = sqrt(R*R - d*d/4);

    double S_triangle = d*h/2;
    double theta = (asin(d/2/R))*2;
    double S_sector = R*R/2*theta;
    double S_segment = S_sector - S_triangle;
    double S = M_PI * R * R;
    //cout << fabs(S_segment / S * 100) << endl;
    if (fabs(S_segment / S * 100 - request) < 5)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
