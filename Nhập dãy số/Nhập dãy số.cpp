#include <iostream> 
using namespace std;
int check(string S) {
	int n = S.size();
	if (5 <= n &&  n <= 100) {
		return 0;
	}
	return 1;
}


int main() {
	string S;
	cout << " Nhap vao so nguyen S " << endl;
	cin >> S;
	if (check(S) == 1) {
		cout << " Thoa man dieu kien " << endl;
	}
	while (check(S) == 0) {
		cout << " Nhap lai so nguyen S " << endl;
		cin >> S;
	}


}
