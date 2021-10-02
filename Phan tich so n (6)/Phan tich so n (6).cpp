//Bài 14. Viết chương trình liệt kê các số nguyên có 7 chữ số
//thoả mãn :
//a) Là số nguyên tố.
//b) Tất cả các chữ số là nguyên tố.
//c) Đảo của nó cũng là một số nguyên tố.

#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int * so_nguyen_to( int * results, int &sptkq) {
	int N = 1000000;
	bool check[1000000];
	// Khởi tạo tất cả các số [2...N] đều là số nguyên tố
	for (int i = 2; i <= N; i++) {
		check[i] = true
	}

	// Thuật toán sàng nuyên tố
	// Nếu một số là số nguyên tố, thì tất cả các bội của nó không phải số nguyên tố
	for (int i = 2; i <= N; i++) {
		if (check[i] == true) {
			for (int j = 2 * i; j <= N; j += i) {
				check[j] = false;
			}
		}
	}
	// In ra các số là số nguyên tố
	for (int i = 2; i <= N; i++) {
		if (check[i] == true) {
			results[sptkq] = i;
			sptkq++;
		}
	}
	return results;
}

void display(int sptkq, int * results) {

	for (int i = 0; i < sptkq; i++) {
		cout << results[i] << "    ";

	}
	cout << endl;
}
int main() {
	cout << " Cac so can tim la " << endl;
	int sptkq = 0;
	int* result;
	result = so_nguyen_to(m sptkq);
	display;

	}







