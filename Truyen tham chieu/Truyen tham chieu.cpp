#include <iostream>
using namespace std;
void updateBalance(int& balance, int change) {
	balance += change;
}
int main() {
	int a = 100;
	int amount = 1000;
	//nap tien vao tai khoan
	updateBalance(amount, 2000);
	//rut tien khoi the 
	updateBalance(amount, -4000);
	cout << amount << endl;
}