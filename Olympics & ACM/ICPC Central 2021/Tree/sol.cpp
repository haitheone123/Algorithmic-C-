#include <bits/stdc++.h>

#define N 200005

using namespace std;

int n, q;
int a[N];
vector<int> g[N];

int d[N];
int lca[N][20], nxt[N][20];
vector<pair<int, int>> dump[N];
pair<int, int> st[N];

struct NodeMax {
    int max_val;
    NodeMax *left, *right;

    NodeMax(int max_val, NodeMax *left, NodeMax *right) {
        this->max_val = max_val;
        this->left = left;
        this->right = right;
    }
} *tree_max[N];

struct NodeSum {
    int sum;
    NodeSum *left, *right;

    NodeSum(int sum, NodeSum *left, NodeSum *right) {
        this->sum = sum;
        this->left = left;
        this->right = right;
    }
} *tree_sum[N];


NodeMax* init_tree_max(int l, int r) {
    if (l == r) {
        return new NodeMax(0, NULL, NULL);
    } else {
        int mid = (l + r) >> 1;
        return new NodeMax(0, init_tree_max(l, mid), init_tree_max(mid + 1, r));
    }
}

NodeSum* init_tree_sum(int l, int r) {
    if (l == r) {
        return new NodeSum(0, NULL, NULL);
    } else {
        int mid = (l + r) >> 1;
        return new NodeSum(0, init_tree_sum(l, mid), init_tree_sum(mid + 1, r));
    }
}

NodeMax* create_max(int l, int r, int d, int val, NodeMax *p) {
    if (l == r) {
        return new NodeMax(val, NULL, NULL);
    } else {
        int mid = (l + r) >> 1;
        NodeMax *left = p->left;
        NodeMax *right = p->right;
        if (mid >= d) {
            left = create_max(l, mid, d, val, left);
        } else {
            right = create_max(mid + 1, r, d, val, right);
        }
        return new NodeMax(max(left->max_val, right->max_val), left, right);
    }
}

NodeSum* create_sum(int l, int r, int x, int y, NodeSum* p) {
    if (x <= l && r <= y) {
        return new NodeSum(p->sum + 1, p->left, p->right);
    } else {
        int mid = (l + r) >> 1;
        NodeSum *left = p->left;
        NodeSum *right = p->right;
        if (mid >= x) {
            left = create_sum(l, mid, x, y, left);
        }
        if (mid < y) {
            right = create_sum(mid + 1, r, x, y, right);
        }
        return new NodeSum(p->sum, left, right);
    }
}

void build(int u, int f, int sz) {
    d[u] = d[f] + 1;

    int new_sz = upper_bound(st, st + sz, make_pair(-a[u], 0)) - st;
    nxt[u][0] = st[new_sz - 1].second;
    lca[u][0] = f;
    for (int i = 1; i < 20; i++) {
        nxt[u][i] = nxt[nxt[u][i - 1]][i - 1];
        lca[u][i] = lca[lca[u][i - 1]][i - 1];
    }

    tree_max[u] = create_max(1, n, d[u], a[u], tree_max[f]);
    if (new_sz < sz && st[new_sz].first + a[u] == 0) {
        tree_sum[u] = create_sum(1, n, d[st[new_sz].second] + 1, d[u], tree_sum[f]);
    } else {
        tree_sum[u] = create_sum(1, n, d[st[new_sz - 1].second] + 1, d[u], tree_sum[f]);
    }

    dump[new_sz].push_back(st[new_sz]);
    st[new_sz] = {-a[u], u};
    for (int v : g[u]) {
        if (v != f) {
            build(v, u, new_sz + 1);
        }
    }
    st[new_sz] = dump[new_sz].back();
    dump[new_sz].pop_back();
}

void init() {
    a[0] = 1e9;
    st[0] = {-1e9, 0};
    tree_max[0] = init_tree_max(1, n);
    tree_sum[0] = init_tree_sum(1, n);
    build(1, 0, 1);
}

int get_lca(int u, int v) {
    if (d[u] > d[v]) {
        swap(u, v);
    }
    int delta = d[v] - d[u];
    for (int i = 0; i < 20; i++) {
        if (delta & (1 << i)) {
            v = lca[v][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = 19; i >= 0; i--) {
        if (lca[u][i] != lca[v][i]) {
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    return lca[u][0];
}

pair<int, int> jump(int u, int p) {
    int cnt = 1;
    for (int i = 19; i >= 0; i--) {
        if (d[nxt[u][i]] >= d[p]) {
            cnt += 1 << i;
            u = nxt[u][i];
        }
    }
    return {cnt, u};
}

int find_first(int l, int r, int x, int val, NodeMax *p) {
    if (p->max_val <= val) {
        return -1;
    }
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    int ret = -1;
    if (mid > x) {
        ret = find_first(l, mid, x, val, p->left);
    }
    if (ret < 0) {
        ret = find_first(mid + 1, r, x, val, p->right);
    }
    return ret;
}

int get_sum(int l, int r, int x, NodeSum *p) {
    if (l == r) {
        return p->sum;
    }
    int mid = (l + r) >> 1;
    if (mid >= x) {
        return p->sum + get_sum(l, mid, x, p->left);
    } else {
        return p->sum + get_sum(mid + 1, r, x, p->right);
    }
}

int solve(int u, int v) {
    int p = get_lca(u, v);
    auto up = jump(u, p);
    if (v != p) {
        int pos = find_first(1, n, d[p], a[up.second], tree_max[v]);
        if (pos > 0) {
            up.first += get_sum(1, n, pos, tree_sum[v]);
        }
    }
    return up.first;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    init();

    for (int i = 0, x, y, p = 0; i < q; i++) {
        scanf("%d%d", &x, &y);
        int u = (x + p) % n + 1;
        int v = (y + p) % n + 1;
        printf("%d\n", p = solve(u, v));
    }
}