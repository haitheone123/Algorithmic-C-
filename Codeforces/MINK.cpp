	
#include <cstdio>
#include <deque>
using namespace std;
 
int n, k;
int a[17005];
deque<int> dq;
 
void push( int x ) {
	while ( !dq.empty() && a[dq.back()] >= a[x] ) dq.pop_back();
	dq.push_back(x);
}
 
void pop( int x ) {
	while ( !dq.empty() && dq.front() <= x ) dq.pop_front();
}
 
int main() {
	int t; scanf( "%d", &t );
	while(t--) {
		scanf( "%d%d", &n, &k ); dq.clear();
		for( int i = 0; i < n; ++i ) scanf( "%d", a+i );
		for( int i = 0; i < k; ++i ) push(i);
		printf( "%d", a[dq.front()] );
		for( int i = k; i < n; ++i ) {
			pop(i-k); push(i);
			printf( " %d", a[dq.front()] );
		}
		putchar('\n');
	}
	return 0;
}