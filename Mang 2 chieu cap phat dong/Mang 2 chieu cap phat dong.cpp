#include <iostream>
using namespace std;
int main() {
	int a[10][10];
	int** arr, arr1, arr2;
	float** floatArray;
	char** friends;
	arr = new int* [100];
	for (int i = 0; i < 100; i++) {
		arr[i] = new int[100];
	}
}
fill(arr[0], arr[0] + 100 * 100, -1);
 for (int i = 0; i < 100; i++) {
	for (int j = 0; j < 100; j++) {
		cout << arr[i][j] << " ";
	}
	cout << endl;
}
