#include <fstream>

using namespace std;

ifstream cin("rmq.in");
ofstream cout("rmq.out");

int a[100001];
int aint[400001];
int n, q;

void build(int nod, int st, int dr) {
    if(st == dr) {aint[nod] = a[st]; return;}
    int mij = (st + dr) / 2;

    build(2 * nod, st, mij);
    build(2 * nod + 1, mij + 1, dr);

    aint[nod] = min(aint[2 * nod], aint[2 * nod + 1]);
}

int query(int nod, int st, int dr, int stq, int drq) {
    if(stq <= st && dr <= drq) return aint[nod];
    
    int mij = (st + dr) / 2;
    int q1 = 2e9, q2 = 2e9;
    if(mij >= stq) q1 = query(2 * nod, st, mij, stq, drq);
    if(mij < drq) q2 = query(2 * nod + 1, mij + 1, dr, stq, drq);

    return min(q1, q2);
}

int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    build(1, 1, n);

    while(q--) {
        int l, r; cin >> l >> r;
        cout << query(1, 1, n, l, r) << '\n';
    }

}

// https://www.infoarena.ro/job_detail/3356889