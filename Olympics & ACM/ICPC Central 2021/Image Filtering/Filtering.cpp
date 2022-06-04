#include <bits/stdc++.h>

long long A[500005], L[500005], B[500005];


using namespace std;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("C:\\Users\\ASUS\\GoogleDriver_pmtuanAtDut.udn.vn\\OLP\\DUTPC\\2021\\FirstRound\\3.Image Filtering\\data\\secret\\10.in","r",stdin);
	//freopen("C:\\Users\\ASUS\\GoogleDriver_pmtuanAtDut.udn.vn\\OLP\\DUTPC\\2021\\FirstRound\\3.Image Filtering\\data\\secret\\10.ans","w",stdout);
	
	int h,w,X,Y;
	cin >> h >> w >> X >> Y;
	
	for (int i=0;i<h;i++)
		for (int j=0;j<w;j++){
			int a;
			cin >> a;
			A[i*w+j] = a;
		}
	
	for (int i=0;i<X;i++)
		for (int j=0;j<Y;j++){
			int l;
			cin >> l;
			L[i*Y+j] = l;
		}
	for (int i=0;i<h;i++)
		for (int j=0;j<w;j++){
			long long sum = 0;
			for (int x=0;x<X;x++)
				for (int y=0;y<Y;y++){
					int ii = i + x - (X+1)/2 + 1;
					int jj = j + y - (Y+1)/2 + 1;
					long long a = 0;
					if (ii>=0 && ii<h && jj>=0 && jj<w) a = A[ii*w+jj];
					sum += a*L[x*Y+y];
				}
			cout << sum;
			if (j==w-1) {
				if (i!=h-1)
					cout << endl;
			}
			else cout <<" ";
		}

	return 0;
}
