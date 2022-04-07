#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100000];
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		memset(a, -1, sizeof a);
		bool bad=false;
		for(int i=0; i<n; i++) {
			if(i-k>=0 && a[i-k]==-1)
				a[i-k]=i;
			else if(i+k<n && a[i+k]==-1)
				a[i+k]=i;
			else
				bad=true;
		}
		if(bad)
			printf("-1\n");
		else {
			for(int i=0; i<n; i++)
				cout<<a[i]+1;
			cout<<endl;
		}
	}
	return 0;
}