#include<iostream> 
using namespace std;



void nhap_mang(int a[],int n) {
	
	
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao so nguyen thu " << i + 1 << " cua mang " << endl;
		cin >> a[i];
	}
	
}
void xuat_mang(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		cout << "  " << a[i];
	}
	
}

void xoa_phan_tu(int a[], int n, int pos) {
	
	if (n <= 0) {
		cout << " Mang rong " << endl;
	}
	if (pos < 0) {
		// khi pos < 0 ta xoa di phan tu dau tien 
		pos = 0;
	}
	 else if (pos >= n) {
		// khi pos >= n ta xoa di phan tu cuoi cung
		pos = n-1;
	}
	for (int i = pos; i < n; i++) {
		// dich chuyen phan tu trong mang 
		a[i] = a[i + 1];
		
	}

	n--;

}




int main() {
	int n;
	cout << " Nhap vao so phan tu cua mang " << endl;
	cin >> n;
	int a[100], pos;
	cout << " Nhap vao so thu tu cua phan tu muon xoa " << endl;
	cin >> pos;
	pos = pos - 1;

	nhap_mang(a , n);
	xoa_phan_tu(a, n, pos);
	xuat_mang(a, n); 
	 

}
