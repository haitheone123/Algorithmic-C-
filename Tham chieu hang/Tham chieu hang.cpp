#include <iostream>
using namespace std;
string fullName(const string& firstName,const string& lastName) {
	return firstName + lastName;
}
double addTwoNumber(const double& a, const double& b) {
	return a + b;
}
int main() {
	cout << fullName("Nguyen Duc", "Hai") << endl;
}