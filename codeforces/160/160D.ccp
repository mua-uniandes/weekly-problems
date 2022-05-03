#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int M = N << 1;

int n, m;
int head[N], num_edge;
int f[N], ans[M];

int depth[N], size[N], fa[N], son[N], top[N];
int dfn[N], idx[N], dis[N], type[N];
bool onTree[M];

struct Node {
    int next, to, dis, idx;
} edge[M];

struct node {
    int u, v, dis, idx;
    bool friend operator<(node a, node b) { return a.dis < b.dis; }
} line[M];

void add_edge(int u, int v, int dis, int idx) { edge[++num_edge] = Node{head[u], v, dis, idx}, head[u] = num_edge; }

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void Kruskal() {
    std::sort(line + 1, line + 1 + m);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1, tot = 0; tot < n and i <= m; i++) {
        int u = line[i].u, v = line[i].v, dis = line[i].dis, idx = line[i].idx;
        int dx = find(u), dy = find(v);
        if (dx != dy)
            onTree[i] = true, f[dx] = dy, tot++, add_edge(u, v, dis, idx), add_edge(v, u, dis, idx);
    }
}

void dfs1(int u, int fa) {
    size[u] = 1, ::fa[u] = fa, depth[u] = depth[fa] + 1;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u), size[u] += size[v], son[u] = size[v] > size[son[u]] ? v : son[u];
}

void dfs2(int u, int idx, int dis) {
    dfn[u] = ++dfn[0], ::idx[dfn[u]] = idx, ::dis[dfn[u]] = dis;
    top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) == son[u])
            dfs2(v, edge[i].idx, edge[i].dis);
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != son[u] and v != fa[u])
            dfs2(v, edge[i].idx, edge[i].dis);
}

struct Segment_Tree {
#define ls (p << 1)
#define rs (p << 1 | 1)
    int max[N << 2], tag[N << 2];
    void push_up(int p) { max[p] = std::max(max[ls], max[rs]); }
    void push_down(int p) {
        if (!tag[p])
            return;
        if (max[p] == max[ls])
            tag[ls] = tag[p];
        if (max[p] == max[rs])
            tag[rs] = tag[p];
        tag[p] = 0;
    }
    void build(int p, int l, int r) {
        if (l == r) {
            max[p] = dis[l];
            return;
        }
        int mid = l + r >> 1;
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    int query(int p, int l, int r, int x, int y) {
        if (l == x and r == y)
            return max[p];
        int mid = l + r >> 1;
        int res = 0;
        if (x <= mid)
            res = std::max(res, query(ls, l, mid, x, std::min(mid, y)));
        if (mid + 1 <= y)
            res = std::max(res, query(rs, mid + 1, r, std::max(mid + 1, x), y));
        return res;
    }
    void modify(int p, int l, int r, int x, int y, int dis, int k) {
        if (l == x and r == y and max[p] == dis) {
            tag[p] = k;
            return;
        }
        push_down(p);
        int mid = l + r >> 1;
        if (x <= mid and max[ls] >= dis)
            modify(ls, l, mid, x, std::min(mid, y), dis, k);
        if (mid + 1 <= y and max[rs] >= dis)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, dis, k);
    }
    void stats(int p, int l, int r) {
        if (l == r) {
            type[idx[l]] = tag[p];
            return;
        }
        push_down(p);
        int mid = l + r >> 1;
        stats(ls, l, mid), stats(rs, mid + 1, r);
    }
} T;

int getmax(int x, int y) {
    int max = 0;
    for (; top[x] != top[y]; max = std::max(max, T.query(1, 2, dfn[0], dfn[top[x]], dfn[x])), x = fa[top[x]])
        if (depth[top[x]] < depth[top[y]])
            std::swap(x, y);
    if (x == y)
        return max;
    if (depth[x] < depth[y])
        std::swap(x, y);
    max = std::max(max, T.query(1, 2, dfn[0], dfn[y] + 1, dfn[x]));
    return max;
}

void modify(int x, int y, int dis, int tag) {
    for (; top[x] != top[y]; T.modify(1, 2, dfn[0], dfn[top[x]], dfn[x], dis, tag), x = fa[top[x]])
        if (depth[top[x]] < depth[top[y]])
            std::swap(x, y);
    if (x == y)
        return;
    if (depth[x] < depth[y])
        std::swap(x, y);
    T.modify(1, 2, dfn[0], dfn[y] + 1, dfn[x], dis, tag);
}

int main() {
    n = read(), m = read();
    for (int i = 1, u, v, dis; i <= m; i++)
        u = read(), v = read(), dis = read(), line[i] = node{u, v, dis, i};
    Kruskal();
    dfs1(1, 0), dfs2(1, 0, 0), T.build(1, 2, n);
    for (int i = 1; i <= m; i++)
		if (!onTree[i]) {
            int u = line[i].u, v = line[i].v, dis = line[i].dis, idx = line[i].idx;
            int max = getmax(u, v);
            if (dis > max)
                type[idx] = 2;
            else if (dis == max)
                type[idx] = 1, modify(u, v, dis, 1);
        }
    T.stats(1, 2, n);
    for (int i = 1; i <= m; i++)  {
        if (type[i] == 0)
            puts("any");
        if (type[i] == 1)
            puts("at least one");
        if (type[i] == 2)
            puts("none");
    }
    return 0;
}