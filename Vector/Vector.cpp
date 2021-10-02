#include <iostream>
using namespace std;
class Vector {
		int n;
		float* v;
	public:
		 Vector() {
			n = 0;
		}
		void nhap() {
			cout << "nhap so luong pt:"; cin >> n;
			v = new float[n];
			for (int i = 0; i < n; i++) {
				cout << "v[" << i << "] = "; cin >> v[i];
			}
		}
		void saochep(Vector& a) {
			n = a.n;
			v = new float[n];
			for (int i = 0; i < n; i++)
				v[i] = a.v[i];
		}
		~Vector() {
			delete v;
		}
		void in() {
			cout << "hien thi : ";
			for (int i = 0; i < n; i++)
				cout << "  " << v[i];
		}
		void operator=(Vector& a) {
			n = a.n;
			v = new float[n];
			for (int i = 0; i < n; i++)
				v[i] = a.v[i];
		}
		friend Vector operator*(Vector& a, float k);
	};
	Vector operator*(Vector& a, float k) {
		for (int i = 0; i < a.n; i++)
			a.v[i] = k * a.v[i];
		return a;
	}
	int main() {
		float k;
		cout << "nhap k: "; cin >> k;
		Vector a;
		a.nhap();
		a.in();
	}