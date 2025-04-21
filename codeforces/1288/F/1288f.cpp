#include<bits/stdc++.h>

using namespace std;

const int N = 443;

int n1, n2, m, r, b;
string s1, s2;
int u[N];
int v[N];

struct edge
{
    int y, c, f, cost;
    edge() {};
    edge(int y, int c, int f, int cost) : y(y), c(c), f(f), cost(cost) {};
};

int bal[N][N];
int s, t, oldS, oldT, V;
vector<int> g[N];
vector<edge> e;

void add(int x, int y, int c, int cost)
{
    g[x].push_back(e.size());
    e.push_back(edge(y, c, 0, cost));
    g[y].push_back(e.size());
    e.push_back(edge(x, 0, 0, -cost));
}

int rem(int num)
{
    return e[num].c - e[num].f;
}   

void add_LR(int x, int y, int l, int r, int cost)
{
    int c = r - l;
    if(l > 0)
    {
        add(s, y, l, cost);
        add(x, t, l, cost);
    }
    if(c > 0)
    {
        add(x, y, c, cost);
    }
}

int p[N];
int d[N];
int pe[N];
int inq[N];

bool enlarge()
{
    for(int i = 0; i < V; i++)
    {
        d[i] = int(1e9);
        p[i] = -1;
        pe[i] = -1;
        inq[i] = 0;
    }
    d[s] = 0;
    queue<int> q;
    q.push(s);
    inq[s] = 1;
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        inq[k] = 0;
        for(auto z : g[k])
        {
            if(!rem(z)) continue;
            if(d[e[z].y] > d[k] + e[z].cost)
            {
                p[e[z].y] = k;
                pe[e[z].y] = z;
                d[e[z].y] = d[k] + e[z].cost;
                if(!inq[e[z].y])
                {
                    q.push(e[z].y);
                    inq[e[z].y] = 1;
                }
            }
        }
    }
    if(p[t] == -1)
        return false;
    int cur = t;
    while(cur != s)
    {
        e[pe[cur]].f++;
        e[pe[cur] ^ 1].f--;
        cur = p[cur];
    }
    return true;
}

void add_edge(int x, int y)
{
    add(x, y + n1, 1, r);
    add(y + n1, x, 1, b);
}

void impose_left(int x)
{
    if(s1[x] == 'R')
    {
        add_LR(oldS, x, 1, m, 0);
    }
    else if(s1[x] == 'B')
    {
        add_LR(x, oldT, 1, m, 0);
    }
    else
    {
        add(oldS, x, m, 0);
        add(x, oldT, m, 0);
    }
}

void impose_right(int x)
{
    if(s2[x] == 'R')
    {
        add_LR(x + n1, oldT, 1, m, 0);
    }
    else if(s2[x] == 'B')
    {
        add_LR(oldS, x + n1, 1, m, 0);
    }
    else
    {
        add(oldS, x + n1, m, 0);
        add(x + n1, oldT, m, 0);
    }
}

void construct_bal()
{
    for(int i = 0; i < n1; i++)
    {
        for(auto z : g[i])
        {
            if(e[z].y >= n1 && e[z].y < n1 + n2)
                bal[i][e[z].y - n1] += e[z].f;
        }
    }
}

void find_ans()
{
    int res = 0;
    string w = "";
    for(auto x : g[s])
        if(rem(x))
        {
            cout << -1 << endl;
            return;
        }
    for(int i = 0; i < m; i++)
    {
        if(bal[u[i]][v[i]] > 0)
        {
            bal[u[i]][v[i]]--;
            res += r;
            w += "R";
        }
        else if(bal[u[i]][v[i]] < 0)
        {
            bal[u[i]][v[i]]++;
            res += b;
            w += "B";
        }
        else w += "U";
    }
    cout << res << endl << w << endl;
}

int main()
{                       
    cin >> n1 >> n2 >> m >> r >> b;
    cin >> s1;
    cin >> s2;
    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }

    oldS = n1 + n2;
    oldT = oldS + 1;
    s = oldT + 1;
    t = s + 1;
    V = t + 1;

    for(int i = 0; i < n1; i++)
        impose_left(i);
    for(int i = 0; i < n2; i++)
        impose_right(i);
    for(int i = 0; i < m; i++)
        add_edge(u[i], v[i]);
    add(oldT, oldS, 100000, 0);
    while(enlarge());
    construct_bal();
    find_ans();
}