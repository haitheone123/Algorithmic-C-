#include <bits/stdc++.h>

#define N 10005

using namespace std;

int n;
int x[N], y[N], w[N], h[N];

vector<int> g[N + N], gt[N + N];
int used[N + N], comp[N + N], mark[N + N];
int assignment[N];
vector<int> order;

struct Rect {
    long long x1, y1, x2, y2;
    Rect(long long x1, long long y1, long long x2, long long y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;  
    }
};

bool check(Rect &a, Rect &b) {
    return a.x2 <= b.x1 || a.x1 >= b.x2 || a.y2 <= b.y1 || a.y1 >= b.y2;
}

void add(int u, int v) {
    g[u ^ 1].push_back(v);
    g[v ^ 1].push_back(u);
    gt[v].push_back(u ^ 1);
    gt[u].push_back(v ^ 1);
}

void build_graph() {
    for (int i = 0; i < n; i++) {
        Rect a(2LL * x[i] - w[i], 2LL * y[i] - h[i], 2LL * x[i] + w[i], 2LL * y[i] + h[i]);
        for (int j = i + 1; j < n; j++) {
            Rect b(2LL * x[j] - w[j], 2LL * y[j] - h[j], 2LL * x[j] + w[j], 2LL * y[j] + h[j]);
            if (!check(a, b)) {
                add(2 * i + 1, 2 * j + 1);
            }
            Rect _b(2LL * x[j] - h[j], 2LL * y[j] - w[j], 2LL * x[j] + h[j], 2LL * y[j] + w[j]);
            if (!check(a, _b)) {
                add(2 * i + 1, 2 * j);
            }
        }
        Rect _a(2LL * x[i] - h[i], 2LL * y[i] - w[i], 2LL * x[i] + h[i], 2LL * y[i] + w[i]);
        for (int j = i + 1; j < n; j++) {
            Rect b(2LL * x[j] - w[j], 2LL * y[j] - h[j], 2LL * x[j] + w[j], 2LL * y[j] + h[j]);
            if (!check(_a, b)) {
                add(2 * i, 2 * j + 1);
            }
            Rect _b(2LL * x[j] - h[j], 2LL * y[j] - w[j], 2LL * x[j] + h[j], 2LL * y[j] + w[j]);
            if (!check(_a, _b)) {
                add(2 * i, 2 * j);
            }
        }
    }
}

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool valid(int u) {
    mark[u] = 1;
    for (int v : g[u]) {
        if (mark[v]) {
            continue;
        }
        if (used[v] < 0) {
            if (!valid(v)) {
                return 0;
            }
        } else {
            if (used[v] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

bool solve_2SAT() {
    order.clear();
    for (int i = 0; i < n + n; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    
    memset(comp, -1, sizeof comp);
    for (int i = 0, j = 0; i < n + n; ++i) {
        int v = order[n + n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }
    
    for (int i = 0; i < n + n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
    }

    memset(assignment, -1, sizeof assignment);
    memset(used, -1, sizeof used);
    for (int i = 0; i < n; i++) {
        if (assignment[i] < 0) {
            used[2 * i] = 1;
            used[2 * i + 1] = 0;
            assignment[i] = 1;
            memset(mark, 0, sizeof mark);
            if (!valid(2 * i)) {
                used[2 * i] = 0;
                used[2 * i + 1] = 1;
                assignment[i] = 0;
            }
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> w[i] >> h[i];
    }    

    build_graph();
    if (solve_2SAT()) {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            if (assignment[i]) {
                cout << "K";
            } else {
                cout << "Q";
            }
        }
    } else {
        cout << "No";
    }
}