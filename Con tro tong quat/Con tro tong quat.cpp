#include<iostream>
//khi mot ham hoac mot bien duoc gan mot bien con tro thi con tro se tro toi dia chi cua ham hoac bien do
using namespace std;
int main() {
	int a = 100, x = 111, n = 120;
	double d = 10.25689;
	char c = 'X';
	float f = 3.14158f;
	cout << "Dia chi cua bien a : " << &a << endl;
	cout << "Gia tri cua bien a : " << a << endl;
	int* aPtr;
	float* fPtr;
	char* namePtr;
	aPtr = &a;
	cout << " Gia tri trong con tro aPtr " << aPtr << endl;
	aPtr = &x;
	aPtr = &n;
	cout << " Gia tri trong con tro aPtr " << aPtr << endl;
	
}