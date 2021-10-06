// kieu du lieu do nguoi dung tu dinh nghia : struct 

#include<iostream>
using namespace std;
 
struct Student {
	char ID;
	char name[100];
	int age;
	float mark;
	char address[100];
	
};
struct Car {
	char owner[100];
	char brand[100];
	char color[100];
	int weight, height, width;

};
struct Cat {
	char name[100];
	int age;
	float weight;
	char color[100];
	char eyesColor[100];
};
void getInfo(Student& s) {
	cout << "Enter name :";
	cin.getline(s.name, 99);

	cout << "Enter age :";
	cin >> s.age;

	cout << "Enter address :";
	cin.ignore();
	cin.getline(s.address, 99);

	cout << "Enter mark :";
	cin >> s.mark;

}
void showInfo(Student s) {
	cout << "Student info as below :" << endl;
	cout << "Name:" << s.name << endl;
	cout << "Address:" << s.address << endl;
	cout << "Age:" << s.age << endl;
	cout << "Mark:" << s.mark << endl;
	


}
int main() {
	Student s1, s2;
	Student* sPtr;
	Student arr[100];
	Student bArr[10][20];

	getInfo(s1);
	showInfo(s1);

	return 0;

}