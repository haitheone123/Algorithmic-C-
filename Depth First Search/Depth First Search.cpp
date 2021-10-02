#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector <int> ke[10000000]; 
bool xet[10000000];
int sodinh, socanh;
int Init() {
	cin >> sodinh >> socanh;
	int u, v;
	for (int i = 1; i <= socanh; i++) {
		cin >> u >> v; //hai dinh cua mot canh
		ke[u].push_back(v); //dinh u ke dinh v
		ke[v].push_back(u); //dinh v ke dinh u
	}
}
int DFS_Recurse(int u) {
	xet[u] = false;
	cout << u << " ";
	for (int i = 0; i < ke[u].size(); i++) {
		int v = ke[u][i];
		if (xet[v] == true) {
			DFS_Recurse(v);
		}
	}

}
int DFS_use_Stack(int u) {
	stack <int> s;
	s.push(u);
	xet[u] = false;
	cout << u << " ";
	while (!s.empty()) {
		u = s.top();
		s.pop();
		for (int i = 0; i < ke[u].size(); i++) {
			int v = ke[u][i];
			if (xet[v] == true) {
				s.push(u);
				s.push(v);
				xet[v] = false;
				cout << v << " ";
				break;
			}
		}
	}
}


int main() {
	memset(xet, true, 10000000);
	Init();
	DFS_Recurse(1);
	cout << endl;
	// DFS_use_Stack(1);
	return 0;
}