#include <fstream>
#include <vector>

using namespace std;

ifstream cin("ratina.in");
ofstream cout("ratina.out");

int n, q, t;
vector<long long> h[10001];
int idx[11];
int p = 53, MOD = 1e9 + 7;

bool check(int x) {
    x--;
    if(x >= h[idx[1]].size()) return 0;
    for(int i = 2; i <= t; ++i) {
        if(x >= h[idx[i]].size() || h[idx[1]][x] != h[idx[i]][x]) return 0;
    }
    return 1;
}

void solve() {
    int st = 1, dr = 2000;
    int ans = 0;

    while(st <= dr) {
        int mij = (st + dr) / 2;
        if(check(mij)) {
            ans = mij;
            st = mij + 1;
        }
        else {
            dr = mij - 1;
        }
    }

    cout << ans << '\n';
}

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        h[i].resize(s.size());
        h[i][0] = s[0] - 'a' + 1;
        for(int j = 1; j < s.size(); ++j) {
            h[i][j] = (h[i][j - 1] * p + (s[j] - 'a' + 1)) % MOD;
        }
    }

    while(q--) {
        cin >> t;
        for(int i = 1; i <= t; ++i) {
            cin >> idx[i];
        }
        solve();
    }
    
}

// https://www.infoarena.ro/job_detail/3353104