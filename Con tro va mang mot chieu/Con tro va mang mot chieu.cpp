#include<iostream>
using namespace std;
//dung con tro de truyen tham so co the ap dung voi mang
//int* a=int a[]
void showResult(int* a) {
	int* posPtr = a;
	for (; posPtr <= &a[9]; posPtr++) {
		cout << *posPtr << " ";
		//in ra phan tu ma posPtr tro toi
	}

	for (size_t i = 0; i < 10; i++) {
		cout << a[i] << " ";
		cout << *a << "";
		//neu khong co them lenh thi ta se in ra phan tu co dia chi thu nhat
		a++;
		//tang hoac giam dia chi ma con tro tro toi
	}
}

int main() {
	int b[] = { 1,2,3,4,5,6,7,8,9,0};//cap phat tinh
	int* ptr = b;
	//gan mang cho con tro
	//dia chi chua con con tro posPtr cua ben tren la dia chi cua phan tu dau tien trong mang a
	int* a = new int[10];//cap phat dong
	int* ptr;
	int c = 100;
	//dia chi cua mang la dia chi cua phan tu dau tien trong ham, ke ca cap phat tinh hay
	//cap phat dong
	for (size_t i = 0; i < 10; i++) {
		a[i] = 10 * i;
	}
	cout << "Dia chi cua b :" << b << endl;
	cout << "dia chi cua b[0] :" << &b[0] << endl;
}