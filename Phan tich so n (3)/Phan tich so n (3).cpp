//Bài 13. Viết chương trình liệt kê các số nguyên có 7 đến 9
//chữ số thoả mãn :
//a) Là số thuận nghịch.
//b) Chỉ có chữ số 0, 6, 8.
//c) Tổng chữ số chia hết cho 10.






#include <iostream>
#include <cmath> 
#include <typeinfo>
using namespace std;
int kiem_tra_so_thuan_nghich(int n) {
	int max = 0;
	int temp = n;
	int i=0;
	while (n > 0) {
		
		if (n <= 0) {
			break;
		}
		i = n % 10;
		max = max * 10 + i;
		n = n / 10;
		
	}
	if (max == temp) {
		return 1;
	}
	return 0;
}

int kiem_tra_chu_so(int n) {
		if (n==0||n==6||n==8) {
			return 1 ;
		}
		return 0 ;
}

int kiem_tra_chu_so_2(int n) {
	int j;
	while (n > 0) {
		j = n % 10;
		n=n/10;
		if (kiem_tra_chu_so(j)==0 ) {
			return 0;
		}
	}
	return 1;
}

int tong_cac_chu_so(int n) {
	int sum = 0;
	int k;
	while (n > 0) {
		k = n % 10;
		sum = sum + k;
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
	cout << " Cac so thoa man dieu kien de bai la " << endl;
	for (int i = 1000000; i <= 99999999; i++) {
		int ketqua_1 = kiem_tra_so_thuan_nghich(i);
		int ketqua_2 = kiem_tra_chu_so_2(i);
		int ketqua_3 = tong_cac_chu_so(i);
		
		if (ketqua_1 == 1&&ketqua_2==1&&ketqua_3==1) {
			cout << i << endl;
		}

	}
	
}