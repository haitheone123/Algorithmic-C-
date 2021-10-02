#include <iostream>
using namespace std;


int so_thuan_nghich(int n) {
	int reverse = 0;
	int j;
	while (n > 0) {
		j = n % 10;
		reverse = reverse * 10 + j;
		n = n / 10;
	}
	if (reverse == n) {
		return 1;
	}
	else {
		return 0;
	}

}
int tong_cac_chu_so(int n) {
	int sum = 0;
	int j;
	while (n > 0) {
		j = n % 10;
		sum = sum + j;
		n = n / 10;
	}
	if (sum % 10 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	int n;
	cout << "Nhap vao so nguyen n" << endl;
	cin >> n;
	if(n<100000&&n>999999){
		cout << " Nhap lai so nguyen m " << endl;
		cin >> n;
	}
	
	else {
		if (so_thuan_nghich(n) == 1 && tong_cac_chu_so(n) == 1) {
			cout << " So nguyen n thoa man cac dieu kien " << endl;
		}
		else {
			cout << " So nguyen n khong thoa man dieu kien " << endl;
		}
	}
	int reverse = 0;
	int j;
	while (n > 0) {
		j = n % 10;
		reverse = reverse * 10 + j;
		n = n / 10;
	}
	cout << reverse << endl;
	int sum=0;
	while (n > 0) {
		j = n % 10;
		sum = sum + j;
		n = n / 10;
	}
	cout << sum << endl;
}