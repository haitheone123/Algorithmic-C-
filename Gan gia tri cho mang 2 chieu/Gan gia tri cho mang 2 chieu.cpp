// khoi tao mang mot chieu, hai chieu voi gia tri cho truoc
// dung vong lap, ham std::fill(from,to,value)



#include <iostream>
using namespace std;
int main() {
	int a[1000];
	int b[10][10];
	fill(a, a + 1000, -1);
	fill(b[0], b[0] + 10 * 10, 20);
	
	
	for (size_t i = 0; i < 10; i++) {
		for (size_t j = 0; j < 10; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}