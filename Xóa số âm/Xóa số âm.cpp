#include <iostream>
#include <list>
#include <iterator>
using namespace std;

list<int> danhSachDiem;
void showlist(list <int> g)
{
    list <int> ::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
void nhapMang(int n) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        cout << " Nhap vao phan tu thu " << i + 1 << " cua mang " << endl;
        cin >> temp;
        danhSachDiem.push_back(temp);
    }
    danhSachDiem.sort();


}
int main() {
    int n;
    cout << " Nhap vao so cac so cua phan tu " << endl;
    cin >> n;
    nhapMang(n);
    showlist(danhSachDiem);



}


