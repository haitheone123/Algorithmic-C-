// in ra cac so nguyen to giua khoang m va n
#include <iostream> 
using namespace std;
int checksonguyento (int x){
	if (x==1){
		return false;
	}
	for(int i=2;i<=sqrt(x);i++){
		if (x%i==0){
			return false;
		}
	}
	return true; 
}
int main () {
	int m ,n;
	cin >> m >> n;
	for(int i=m;i<=n;i++){
		if(checksonguyento(i)==true){
			cout<<i<<endl;
		}
	}





}

