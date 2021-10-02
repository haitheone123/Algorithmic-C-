#include <iostream>
#include <cmath>
using namespace std;
void uoc_so(int n) {
	int count = 0;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			cout << "  " <<i;
			count++;
			
		}
		else continue;
		
	}
	cout << endl;
	cout << " So uoc so cua so nguyen duong n la : " << count << endl;

}

bool kiem_tra_uoc_so_nguyen_to(int n) {

	for (int j = 2; j <= sqrt(n); j++) {
		if (n % j == 0) return false;
	}
	return true;
}



void in_ra_uoc_so_nguyen_to(int n) {
	int count_reg = 0;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0 && kiem_tra_uoc_so_nguyen_to(i)) {
			cout << "  " << i;
			count_reg++;
		}
		else continue;
	}
	cout << endl;
	cout << " So uoc so nguyen to cua so nguyen duong n la : " << count_reg << endl;
}

int main() {
	int n;
	cout << " Nhap vao so nguyen duong n  " << endl;
	cin >> n;
	cout << " Cac uoc so cua so nguyen duong n la : " << endl;
	uoc_so(n);
	cout << " Cac uoc so nguyen to cua so nguyen duong n la : " << endl;
	in_ra_uoc_so_nguyen_to(n);

}
