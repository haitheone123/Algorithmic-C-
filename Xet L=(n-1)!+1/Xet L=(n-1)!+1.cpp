#include <iostream>;
#include <cmath>;
using namespace std;
int giaithua(int n) {
	int giaiThua = 1;
	for (int i=1;i<=n-1;i++){
		giaiThua = giaiThua * i;
	}
	return giaiThua;
}
int main() {
	int n;
	cout << " Nhap vao so nguyen n" << endl;
	cin >> n;
	
	if ((giaithua(n) + 1) % 3 == 0) {
		cout << " YES " << endl;
	}
	else {
		cout << " NO " << endl;
	} 
}