#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dim;
int qx, qy;
int kx, ky;
int dx, dy;

bool v[1001][1001];

bool sol(int ex, int ey)
{
    if ((ex < 0 || ex >= dim) || (ey < 0 || ey >= dim)) return false;

    if (v[ex][ey] == true)  return false;

    v[ex][ey] = true;

    if (ex == qx || ey == qy)   return false;

    if (ex == dx && ey == dy)
        return true;

    auto r = sol(ex + 1, ey) || sol(ex + 1, ey + 1) || sol(ex, ey + 1) || sol(ex - 1, ey + 1) || sol(ex - 1, ey) ||
        sol(ex - 1, ey - 1) || sol(ex, ey - 1) || sol(ex + 1, ey - 1);

    return r;
}

int main()
{
    cin >> dim;

    cin >> qx >> qy;
    qx--;
    qy--;

    cin >> kx >> ky;
    kx--;
    ky--;

    cin >> dx >> dy;
    dx--;
    dy--;


    cout << (sol(kx, ky) ? "YES" : "NO") << endl;

    return 0;
}