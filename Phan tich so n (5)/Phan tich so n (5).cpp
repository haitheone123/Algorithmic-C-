//Bài 12. Viết chương trình liệt kê các số nguyên có 7 chữ số
//thoả mãn :
//a) Là số nguyên tố.
//b) Tổng các chữ số của số đó là một số nguyên tố.
//c) Các chữ số từ trái qua phải tạo thành dãy không giảm.




#include <iostream>
#include <cmath>
#include <typeinfo>
#include <stdio.h>
using namespace std;

int so_nguyen_to(int n) {
    bool check[n + 1];
    for (int i = 2; i <= n; i++) {
        check[i] = true;
    }
    for (int i = 2; i <= n; i++) {
        if (check[i] == true) {
            for (int j = 2 * i; j <= n; j += i) {
                check[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (check[i] == true) {
            return 1;
        }
    }
    return 0;
}

int so_cac_chu_so(int n) {
    int count = 0;
    while (n > 0) {
        n = n / 10;
        count++;
    }
    if (count == 7) {
        return 1;
    }
    return 0;
}
int tong_cac_chu_so(int n) {
    int max=0;
    int i;
    while (n > 0) {
        i = n % 10;
        max = max + i;
        n = n / 10;
    }
    for (int j = 2; j <= sqrt(max); j++) {
        if (max % j == 0) {
            return 0;
        }
    }
    return 1;
}
int day_so_khong_giam(int n) {
    char a, b;
    while (n > 10) {
        a = n % 10;
        n = n / 10;
        b = n % 10;
        if (a < b) {
            return 0;
        }

    }
    return 1;
}

int main() {
    cout << " Cac so thoa man dieu kien la " << endl;
    for (int i = 2; i <= 9999999; i++) {
        
        int ham_1 = so_nguyen_to(i);
        int ham_2 = tong_cac_chu_so(i);
        int ham_3 = day_so_khong_giam(i);
        int ham_4 = so_cac_chu_so(i);
        if (ham_1 == 1 && ham_2 == 1 && ham_3 == 1&&ham_4==1) {
            cout << " " << i << endl;
        }
    }



}