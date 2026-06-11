#include <fstream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int block;
int n, q;
vector<int> v[50001];
int ans[100001];
int nr_soldati = 0;
int fr[10001];

struct salut {
    int st, dr, idx;
    bool operator < (const salut & other) const {
        int block_a = st / block;
        int block_b = other.st / block;
        if(block_a != block_b) {
            return block_a < block_b;
        }

        return (block_a & 1) ? (dr < other.dr) : (dr > other.dr);
    }
} queries[100001];

void process_army(int k) {
    for(const auto & x : v[k]) {
        if (fr[x] == 1) {
            fr[x] = 0;
            nr_soldati--;
        } 
        else {
            fr[x] = 1;
            nr_soldati++;
        }
    }
}

int main() {

    ifstream cin("infinitywar.in");
    ofstream cout("infinitywar.out");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        int k; cin >> k;
        v[i].reserve(k);
        while(k--) {
            int x; cin >> x;
            v[i].push_back(x);
        }
    }

    block = sqrt(n);

    for(int i = 1; i <= q; ++i) {
        int st, dr; cin >> st >> dr;
        queries[i] = {st, dr, i};
    }

    sort(queries + 1, queries + q + 1);

    int st = 1, dr = 0;
    for(int i = 1; i <= q; ++i) {
        const auto & q = queries[i];
        while(st > q.st) { st--; process_army(st); }
        while(st < q.st) { process_army(st); st++; }
        while(dr > q.dr) { process_army(dr); dr--; }
        while(dr < q.dr) { dr++; process_army(dr); }
    
        ans[q.idx] = nr_soldati;
    }

    for(int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
    }

}   

// https://www.infoarena.ro/job_detail/3357356