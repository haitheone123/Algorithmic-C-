#include<iostream>
#include<cmath>
using namespace std;
void input (int n, int a[]) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void max_number_of_pairs(int n, int a[], int k) {
	int ans=0, m[1000];
	for (int i = 0; i < sizeof(a); i++) {
		if (m[k - a[i]] > 0) {
			m[k - a[i]]--;
			ans++;
		}
		else {
			m[a[i]]++;
			
		}

	}
	cout << ans << endl;


}
int main() {
	int k, a[1000], n;
	cin >> n >> k;
	input(n,a);
	max_number_of_pairs(n, a, k);






}