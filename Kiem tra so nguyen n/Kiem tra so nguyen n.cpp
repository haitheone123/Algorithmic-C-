#include<iostream>
using namespace std;
void dem_chu_so(int n) {
	int i;
	int count_chan = 0;
	int count_le = 0;
	while (n > 0) {
		i = n % 10;
		if (i % 2 == 0) {
			count_chan ++;
		}
		if (i % 2 == 1) {

			count_le++;
		}
		n = n / 10;
	
	}
	cout << " So cac chu so chan cua so nguyen n la " << count_chan << endl;
	cout << " So cac chu so le cua so nguyen n la " << count_le << endl;


}




int main() {
	int n;
	cout << " Nhap vao so nguyen n " << endl;
	cin >> n;
	
	dem_chu_so(n);


}