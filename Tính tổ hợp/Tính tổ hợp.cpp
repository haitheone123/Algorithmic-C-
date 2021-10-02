#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int to_hop(int i,int n) {
	if (i == 0 || i == n) return 1;
	if (i == 1) return n;
	return to_hop(i - 1, n - 1) + to_hop(i, n - 1);
		
	
}

int main() {
	int n;
	cout << " Nhap vao gia tri n " << endl;
	cin>> n;
	for (int i = 0; i <= n; i++) {
		cout << " To hop chap " <<i<< " cua n la " << to_hop(i, n) << endl;
	}
	

}
