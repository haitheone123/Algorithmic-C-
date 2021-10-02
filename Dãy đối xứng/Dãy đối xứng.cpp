#include <iostream> 
using namespace std;
int symmetry(string S) {
    int i;
    int n = S.size();
    for (i = 0; i < n / 2; i++)
    {
        if (S[i] != S[n-1-i]) {
            return 0;
        }
        
    }
    return 1;
}
int main () {
    string S;
    cout << " Nhap vao day S " << endl;
    cin >> S;
    if (symmetry(S) == 1) {
        cout << " Day la day ki tu doi xung " << endl;

    }


    if (symmetry(S) == 0) {
        cout << " Day khong phai la day ki tu doi xung " << endl; 
    }






}
