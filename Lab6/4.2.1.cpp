#include <fstream>
#define int long long
 
using namespace std;

ifstream cin("arbint.in");
ofstream cout("arbint.out");

int n, q;
int v[100001];
int aint[400001];
 
void build(int nod, int st, int dr)
{
    if(st == dr) aint[nod] = v[st];
    else {
        int mij = (st + dr) / 2;
        build(2 * nod, st, mij);
        build(2 * nod + 1, mij + 1, dr);
        aint[nod] = max(aint[2 * nod], aint[2 * nod + 1]);
    }
}
 
void update(int nod, int st, int dr, int pos, int val)
{
    if(st == dr && st == pos) aint[nod] = val;
    else {
        int mij = (st + dr) / 2;
        if(mij >= pos) update(2 * nod, st, mij, pos, val);
        if(mij < pos) update(2 * nod + 1, mij + 1, dr, pos, val);
        aint[nod] = max(aint[2 * nod], aint[2 * nod + 1]);
    }
}
 
int query(int nod, int st, int dr, int stq, int drq)
{
    if(stq <= st && dr <= drq) return aint[nod];
    int mij = (st + dr) / 2;
    int q1 = -1e15, q2 = -1e15;
    if(mij >= stq) q1 = query(2 * nod, st, mij, stq, drq);
    if(mij < drq) q2 = query(2 * nod + 1, mij + 1, dr, stq, drq);
    return max(q1, q2);
}
 
signed main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> v[i];
    build(1, 1, n);
 
    while(q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1) update(1, 1, n, x, y);
        else cout << query(1, 1, n, x, y) << '\n';
    }
}

// https://www.infoarena.ro/job_detail/3356894