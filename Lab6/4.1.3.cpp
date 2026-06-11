#include <fstream>
#include <vector>

using namespace std;

ifstream cin("stramosi.in");
ofstream cout("stramosi.out");

int parent[19][250005];
int n, m;

void build() {
    for (int p = 1; p < 19; ++p) {
        for (int i = 1; i <= n; ++i) {
            parent[p][i] = parent[p - 1][parent[p - 1][i]];
        }
    }
}

int query(int q, int p) {
    for (int i = 0; i < 19; ++i) {
        if ((p >> i) & 1) {
            q = parent[i][q];
        }
    }
    return q;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> parent[0][i];
    }

    build();

    while (m--) {
        int q, p;
        cin >> q >> p;
        cout << query(q, p) << "\n";
    }

    return 0;
}

// https://infoarena.ro/job_detail/3356892