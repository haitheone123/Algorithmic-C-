//Bài 13.	 Nhập một dãy số có n phần tử trong đó không cho phép nhập các số trùng nhau. Nếu nhập một số 
// đã có thì yêu cầu nhập lại. Sau đó in ra dãy số n
#include <iostream>
#include <cmath>
#include <typeinfo> 
using namespace std;
bool find_index(int a[], int num_elements, int value)
{
	int i;
	for (int i = 0; i < num_elements; i++)
	{
		if (a[i] == value)
		{
			return true;
		}
	}
	return false;
}

void nhap_mang(int a[], int& num_elements){
	int temp;
	for (int i = 0; i < num_elements; i++)
	{
		cout << " Nhap phan tu thu " << i + 1 << " cua mang : " << endl;
		cin >> temp;
		if (find_index(a, i, temp) == true)
		{
			cout << " Gia tri bi trung vui long nhap lai " << endl;
			i--;
		}
		else
		{
			a[i] = temp;
		}
	}

}

void xuat_mang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	

}
int main() {
	int n, a[1000];
	cout << " Nhap vao so phan tu cua mang " << endl;
	cin >> n;
	nhap_mang(a, n);
	xuat_mang(a, n);

}


