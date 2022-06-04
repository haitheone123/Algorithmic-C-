#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

struct node {
	long long sum, first;
};

static int a[MAXN];
static int s[MAXN];
static int val[MAXN];
static int p[MAXN];
static node ans[MAXN];

void DFS(int point) {
	if (s[point] == s[point+1]) {
		ans[point].sum = (long long)(val[point]);
		ans[point].first = (long long)(val[point]);
	} else {
		int i;
		long long S = 0;
		for (i = s[point]; i < s[point+1]; i++) {
			DFS(a[i]);
			S += ans[a[i]].sum;
		}
		ans[point].sum = 0;
		ans[point].first = 0;
		for (i = s[point]; i < s[point+1]; i++) {
			long long candFirst =  max(ans[a[i]].first, (long long)(val[point]));
			long long candSum = S - ans[a[i]].first + candFirst;
			if ((candSum > ans[point].sum) || (candSum == ans[point].sum && candFirst < ans[point].first)) {
				ans[point].sum = candSum;
				ans[point].first = candFirst;
			}
		}
	}
}

int main() {
	int T, iT;
	scanf("%d",&T);
	for (iT = 0; iT < T; iT++) {
		int N;
		int i;
		scanf("%d",&N);
		for (i = 0; i < N; i++) {
			scanf("%d",&val[i]);
		}
		for (i = 0; i < N; i++) {
			scanf("%d",&p[i]);
			p[i]--;
		}
		memset(s,0,sizeof(s));
		for (i = 0; i < N; i++) {
			if (p[i] != -1) {
				s[p[i]]++;
			}
		}
		for (i = 1; i <= N; i++) {
			s[i] += s[i-1];
		}
		for (i = 0; i < N; i++) {
			if (p[i] != -1) {
				s[p[i]]--;
				a[s[p[i]]] = i;
			}
		}
		long long res = 0;
		for (i = 0; i < N; i++) {
			if (p[i] == -1) {
				DFS(i);
				res += ans[i].sum;
			}
		}
		printf("Case #%d: %lli\n",iT+1,res);
	}
	return 0;
}
