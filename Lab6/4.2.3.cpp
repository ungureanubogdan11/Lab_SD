#include <fstream>
#include <algorithm>
#define int long long
 
using namespace std;

ifstream cin("maxq.in");
ofstream cout("maxq.out");

struct node {
    int suma = 0, mx = 0, mxl = 0, mxr = 0;
} aint[800001];
 
int n, q;
int v[200001];
 
void op(int nod)
{
    aint[nod].suma = aint[2 * nod].suma + aint[2 * nod + 1].suma;
    aint[nod].mxl = max(aint[2 * nod].mxl, aint[2 * nod].suma + aint[2 * nod + 1].mxl);
    aint[nod].mxr = max(aint[2 * nod + 1].mxr, aint[2 * nod + 1].suma + aint[2 * nod].mxr);
    aint[nod].mx = max({aint[2 * nod].mx, aint[2 * nod + 1].mx, aint[2 * nod].mxr + aint[2 * nod + 1].mxl}); 
}
 
void build(int nod, int st, int dr)
{   
    if(st == dr) {
        aint[nod] = {v[st], v[st], v[st], v[st]};
    }
    else {
        int mij = (st + dr) / 2;
 
        build(2 * nod, st, mij);
        build(2 * nod + 1, mij + 1, dr);
 
        op(nod);
    }
}    
 
void update(int nod, int st, int dr, int p, int val)
{
    if(st == dr) {
        aint[nod] = {val, val, val, val};
    }
    else {
        int mij = (st + dr) / 2;
 
        if(mij >= p) update(2 * nod, st, mij, p, val);
        else update(2 * nod + 1, mij + 1, dr, p, val);
 
        op(nod);
    }
}
 
node query(int nod, int st, int dr, int stq, int drq)
{
    if(stq <= st && dr <= drq) {
        return aint[nod];
    }
    int mij = (st + dr) / 2;
 
    node l, r;
    if(stq <= mij) l = query(2 * nod, st, mij, stq, drq);
    if(mij < drq) r = query(2 * nod + 1, mij + 1, dr, stq, drq);
    
    node rez;
    rez.suma = l.suma + r.suma;
    rez.mxl = max(l.mxl, l.suma + r.mxl);
    rez.mxr = max(r.mxr, r.suma + l.mxr);
    rez.mx = max({l.mx, r.mx, l.mxr + r.mxl});
    return rez;
}
 
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> v[i];
    build(1, 1, n);
    
    cin >> q;
    while(q--) {
        int op, p, val;             
        cin >> op >> p >> val;
        if(op == 0) update(1, 1, n, p + 1, val);
        else cout << max(0ll, query(1, 1, n, p + 1, val + 1).mx) << '\n';
    }
} 


// https://www.infoarena.ro/job_detail/3356896