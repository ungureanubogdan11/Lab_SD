#include <fstream>
#define int long long
 
using namespace std;

ifstream cin("mit.in");
ofstream cout("mit.out");

struct salut {
    int val, lazy = 0;
};
 
int n, q;
int v[200001];
salut aint[800001];
 
void build(int nod, int st, int dr)
{
    if(st == dr) aint[nod].val = v[st];
    else {
        int mij = (st + dr) / 2;
        
        build(2 * nod, st, mij);
        build(2 * nod + 1, mij + 1, dr);
 
        aint[nod].val = max(aint[2 * nod].val, aint[2 * nod + 1].val);
    }
}
 
void update(int nod, int st, int dr, int stq, int drq, int x)
{
    if(stq <= st && dr <= drq) {
        aint[nod].lazy += x;
        aint[nod].val += x;
    }
    else {
        int mij = (st + dr) / 2;
        
        if(aint[nod].lazy) {
            aint[2 * nod].lazy += aint[nod].lazy; 
            aint[2 * nod].val += aint[nod].lazy; 
            aint[2 * nod + 1].lazy += aint[nod].lazy;
            aint[2 * nod + 1].val += aint[nod].lazy;
            aint[nod].lazy = 0;
        }
 
        if(mij >= stq) update(2 * nod, st, mij, stq, drq, x);
        if(mij < drq) update(2 * nod + 1, mij + 1, dr, stq, drq, x);
 
        aint[nod].val = max(aint[2 * nod].val, aint[2 * nod + 1].val);
    }
}
 
int query(int nod, int st, int dr, int stq, int drq)
{
    if(stq <= st && dr <= drq) {
        return aint[nod].val;
    }
    else {
        int mij = (st + dr) / 2;
 
        if(aint[nod].lazy) {
            aint[2 * nod].lazy += aint[nod].lazy; 
            aint[2 * nod].val += aint[nod].lazy; 
            aint[2 * nod + 1].lazy += aint[nod].lazy;
            aint[2 * nod + 1].val += aint[nod].lazy;
            aint[nod].lazy = 0;
        }
 
        int ans = -4e18;
        if(mij >= stq) ans = max(ans, query(2 * nod, st, mij, stq, drq));
        if(mij < drq) ans = max(ans, query(2 * nod + 1, mij + 1, dr, stq, drq));
 
        return ans;
    }
}
 
signed main() {

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> v[i];
 
    build(1, 1, n);
 
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int a, b; cin >> a >> b;
            cout << query(1, 1, n, a, b) << '\n';
        }
        else if(op == 2) {
            int a, b, x; cin >> a >> b >> x;
            update(1, 1, n, a, b, x);
        }
    }

    return 0;
}

// https://www.infoarena.ro/job_detail/3357339