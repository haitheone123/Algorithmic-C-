#include <iostream>
using namespace std;
int tong_cac_chu_so(int n) {
	int sum = 0;
	int i;
	while (n > 0) {
		i = n % 10;
		sum = sum + i;
		n = n / 10;


	}
	return sum;

}
 
void tich_cac_so_nguyen_to( int n) {
    
    int dem;

    for (int i = 2; i <= n; i++) {
        dem = 0;
        while (n % i == 0) {
            ++dem;
            n /= i;
        }
        if (dem) {
            cout << i;
            if (dem > 1) cout << "^" << dem;
            if (n > i) {
                cout << " * ";
            }
        }
    }

}


int main() {
    int n;
    cout << " Nhap vao so nguyen duong n " << endl;
    cin >> n;
    if (n < 0) {
        cout << " Nhap lai so nguyen duong n" << endl;
        cin >> n;
    }
    if (n >= 0) {   
        cout << " Tong cac chu so cua so nguyen duong n la " << tong_cac_chu_so(n) << endl;
        cout << " So nguyen duong n co the phan tich thanh cac so nguyen to nhu sau " << endl;
        tich_cac_so_nguyen_to(n);


    }
}