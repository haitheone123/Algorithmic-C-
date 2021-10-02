#include <iostream>
using namespace std;


int main() {
	int n;
	cout << " Nhap vao so nguyen n " << endl;
	cin >> n ;
	int max = 0;
	int P = 1;
	while (5 <= n && n <= 100) {
		cout << " Nhap lai so nguyen n " << endl;
		cin >> n;
	}
	 if (n<5 || n>100) {
	for (int i = 1; i <= n; i++) {
		P = P * i;
		max = max + P;

	}
	cout << " Gia tri cua S la " << max << endl;


} 

}



