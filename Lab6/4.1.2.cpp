#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream cin("plantatie.in");
ofstream cout("plantatie.out");

int rmq[10][501][501];
int lg2[501];
int n, m;

void precomputeLog() {
    lg2[1] = 0;
    for (int i = 2; i <= n; ++i) {
        lg2[i] = lg2[i / 2] + 1;
    }
}

void buildRMQ() {
    for (int p = 1; (1 << p) <= n; ++p) {
        int len = 1 << (p - 1);
        for (int i = 1; i + (1 << p) - 1 <= n; ++i) {
            for (int j = 1; j + (1 << p) - 1 <= n; ++j) {
                rmq[p][i][j] = max({
                    rmq[p - 1][i][j],
                    rmq[p - 1][i + len][j],
                    rmq[p - 1][i][j + len],
                    rmq[p - 1][i + len][j + len]
                });
            }
        }
    }
}

int query(int i, int j, int k) {
    int p = lg2[k];
    int len = 1 << p;
    
    return max({
        rmq[p][i][j],
        rmq[p][i + k - len][j],
        rmq[p][i][j + k - len],
        rmq[p][i + k - len][j + k - len]
    });
}

int main() {

    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> rmq[0][i][j];
        }
    }

    precomputeLog();
    buildRMQ();

    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << query(i, j, k) << "\n";
    }

    return 0;
}

// https://infoarena.ro/job_detail/3356891