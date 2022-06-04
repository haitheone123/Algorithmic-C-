//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
char s[111];
int main()
{
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		scanf("%s", s);
		int len = strlen(s);
		string ans;
		for (int j=0; j<len; j++) {
			int k = j;
			while (k < len && s[k]==s[j]) {
				k++;
			}
			ans += s[j];
			if (k < len && s[k] > s[j]) {
				ans += s[j];
			}
		}
		printf("Case #%d: %s\n", t, ans.c_str());
	}
	return 0;
}