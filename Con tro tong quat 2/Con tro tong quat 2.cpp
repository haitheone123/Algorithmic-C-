#include<iostream>
#include<string>
using namespace std;
// con tro : la mot bien dac biet, am chi mot bien x nao do
// thong qua dia chi cua bien do 
// con tro la mot bien ma gia tri cua no la dia chi cua bien khac
struct conNguoi {
	conNguoi(std::string ht,int t, float v1, float cc) {
		tuoi = t;
		vong_mot = v1;
		chieu_cao = cc;
		ho_ten = ht;
	}
	std::string ho_ten;
	int tuoi;
	float vong_mot;
	float chieu_cao;
	bool con_zin;
};
void pha_zin(conNguoi * nguoi) {
	cout << " Thuc hien pha zin em " << (*nguoi).ho_ten << endl;
	(*nguoi).con_zin = false;


}

int main() {
	conNguoi hoi_phu_nu[5] = {
	conNguoi("thao",22, 95, 1.65),
	conNguoi("lan",18, 90, 1.70),
	conNguoi("huong",29, 85, 1.63),
	conNguoi("nhung", 27, 90, 1.62),
	conNguoi("phuong", 19, 100, 1.73),


	};
	conNguoi* bo_nhi = nullptr;
	//bo_nhi = &thao;
//cout << (*bo_nhi).tuoi << endl;
//		//lay ra gia tri cua bien tai dia chi duoc gan, o day la tuoi cua Thao
	//bo_nhi = &lan;
	//cout << (*bo_nhi).vong_mot << endl;
		// in ra vong mot cua Lan 
	//bo_nhi = bo_nhi + 2;
		//bo_nhi hien tai la dia chi cua Huong ( phep toan con tro )
	//cout << (*bo_nhi).chieu_cao << endl;
		//in ra chieu cao cua Huong
		//khong khuyen khich su dung phep toan tren cac bien tu do
	for (bo_nhi = hoi_phu_nu; bo_nhi < hoi_phu_nu + 5; bo_nhi++) {
		cout << (*bo_nhi).ho_ten << endl;
	}
	//gan 2 con tro cho nhau de xet mang
	cout << " Truoc khi pha, em " << hoi_phu_nu[3].ho_ten << " " << (hoi_phu_nu[3].con_zin ? "con zin" : "mat zin") << endl;
	pha_zin(&hoi_phu_nu[3]);
	cout<<" Sau khi pha, em "<<hoi_phu_nu[3].ho_ten << " " << (hoi_phu_nu[3].con_zin ? "con zin" : "mat zin") << endl;
	//do bien conNguoi.nguoi va Nhung la hai bien hoan toan khac nhau, chi co tham so la giong
	//nen neu dung o day va cout thi em Nhung van con zin
	//them con tro vao void pha_zin, nho phai them dau & vao hoi_phu_nu[3]

		
}