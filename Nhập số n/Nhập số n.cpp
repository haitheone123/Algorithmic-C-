#include <iostream> 
using namespace std;
int so_nguyen_to(int i) {
	if (i < 2) {
		return 0;
	}
		
	if (i  >= 2) {
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) return 0;
		}
	}

	return 1;

}

int so_fibonacci(int i) {
	
	if (i < 0) {
		return -1;
	}
	else if (i == 0 || i == 1) {
		return i;
	}
	else {
		// su dung phuong phap de quy 
		return so_fibonacci(i - 1) + so_fibonacci(i - 2);
		
	}
	
}
int main() {
	int n;
	cout << " Nhap vao so nguyen n " << endl;
	cin >> n;
	int count = 0;
	int i = 2;
	
	if (n >= 95) {
		cout << " Nhap lai so nguyen n " << endl;
		cin >> n;
	}
	if (n < 95) {
		cout << n << " so nguyen to dau tien la : " << endl;
		while (count < n) {
			if (so_nguyen_to(i) == 1) {
				cout << " " << i;
				count++;
			}
			i++;
		}
		cout << " " << endl;
		cout << n << " So fibonacci dau tien la :" << endl;
		for (int i = 0; i < n; i++) {
			cout << " " << so_fibonacci(i);
		}
		

	}
	
}

