#include <iostream>
using namespace std;
void changeNumber(int n) {
	n = 2 * n;
}
void changeNumber2(int* n) {
	*n = *n * 2;
}
//called by reference 
//chung ta can thay doi gia tri nguyen thuy cua ham so
//khi kieu du lieu truyen vao ham la rat lon, khac null
//hoac chung ta khong muon ap dung toan cho con tro
void changeNumber3(int& n) {
	n = n * 2;
}
// khi chung ta khong muon cho phep ham lam thay doi gia tri nguyen thuy cua tham so truyen vao
// truyen tham chieu binh thuong 
int main() {
	int n = 100;
	cout << " Truoc khi goi ham changeNumber : " << n << endl;
	changeNumber(n);
	cout << "Sau khi goi ham changeNumber : " << n << endl;

	cout << "Truoc khi goi ham changeNumber2 : " << n << endl;
	changeNumber2(&n);
	cout << " Sau khi goi ham changeNumber2:" <<n  << endl;
	 
	cout << "Truoc khi goi ham changeNumber3 : " << n << endl;
	changeNumber3(n);
	cout << "Sau khi goi ham changeNumber3 :" << n << endl;



}