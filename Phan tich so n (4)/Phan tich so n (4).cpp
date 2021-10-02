//Bài 11. Viết chương trình liệt kê các số nguyên có từ 5 đến
//7 chữ số thoả mãn :
//a) Là số nguyên tố.
//b) Là số thuận nghịch.
//c) Không chứa chữ số 4.

#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;
int so_nguyen_to(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
	
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int so_cac_chu_so(int n) {
	int k = 0;
	while (n > 0) {
		n = n / 10;
		k++;
	}
	if (k>=5&&k<=7) {
		return 1;
		
	}
	return 0;
}

int so_thuan_nghich(int n) {
	int temp = n;
	int reverse = 0;
	while (temp > 0) {
		
		reverse = reverse * 10 + temp % 10;
		temp = temp / 10;
	}
	if (reverse == n) {
		return 1;
	}
	return 0;
}
int kiem_tra_chu_so(int n) {
	int i;
	while (n > 0) {
		
		i = n % 10;
		n = n / 10;
		if (i == 4) {
			return 0;
		}
	
	}
	return 1;
}
int main() {
	cout << " Cac so can tim la : " << endl;
	int i;
	for (i = 0; i <= 10000000; i++) {
		if (so_nguyen_to(i) == 1 && so_thuan_nghich(i) == 1 && kiem_tra_chu_so(i) == 1 && so_cac_chu_so(i) == 1) {
			cout << "  " << i << endl;
		}
	}

	}
	


