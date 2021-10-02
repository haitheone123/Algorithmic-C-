#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int n;
    cout << " Moi ban nhap so tien " << endl;
    cin >> n;

    while (n < 1000) {
        if (n % 1000 != 0) {
            cout << "so tien phai chia het cho 1000" << endl;

        }

    }
    int namtram = n / 500000;
    n = n % 500000;
    int haitram = n / 200000;
    n = n % 200000;
    int mottram = n / 100000;
    n = n % 100000;
    int nammuoi = n / 50000;
    n = n % 50000;
    int haimuoi = n / 20000;
    n = n % 20000;
    int muoi = n / 10000;
    n = n / 10000;
    int nam = n / 5000;
    n = n % 5000;
    int hai = n / 2000;
    n = n % 2000;
    int mot = n / 1000;
    n = n % 1000;
    cout << "Ket qua : " << endl;
}