#include <bits/stdc++.h>

using namespace std;

int main() {
	int T, iT;
	scanf("%d",&T);
	for (iT = 0; iT < T; iT++) {
		int C[3];
		int M[3];
		int Y[3];
		int K[3];
		int i;
		for (i = 0; i < 3; i++) {
			scanf("%d %d %d %d",&C[i],&M[i],&Y[i],&K[i]);
		}
		int c, m, y, k;
		c = min(C[0], min(C[1], C[2]));
		m = min(M[0], min(M[1], M[2]));
		y = min(Y[0], min(Y[1], Y[2]));
		k = min(K[0], min(K[1], K[2]));
		if (c == 0 || m == 0 || y == 0 || k == 0 || (c + m + y + k) < 1000000) {
			printf("Case #%d: IMPOSSIBLE\n",iT+1);
		} else {
			c = max(1000000 - m - y - k, 1);
			m = max(1000000 - c - y - k, 1);
			y = max(1000000 - c - m - k, 1);
			k = max(1000000 - c - m - y, 1);
			printf("Case #%d: %d %d %d %d\n",iT+1,c,m,y,k);
		}
	}
	return 0;
}
