#include <fstream>
#include <vector>
#include <unordered_map>
#define int long long

using namespace std;

ifstream cin("secv5.in");
ofstream cout("secv5.out");

int n, l, u;
int v[1000001];

int res(int k) {
    // if(k == 0) return 0;

    unordered_map<int, int> fr;
    int st = 1;
    int diferite = 0;
    int ans = 0;
    
    for(int dr = 1; dr <= n; ++dr) {
        if(fr[v[dr]] == 0) {
            diferite++;
        }
        fr[v[dr]]++;

        while(st <= dr && diferite > k) {
            fr[v[st]]--;
            if(fr[v[st]] == 0) {
                diferite--;
            }
            st++;
        }

        ans += (dr - st + 1);
    }

    return ans;
}

signed main() {
    
    cin >> n >> l >> u;
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    cout << res(u) - res(l - 1);

    return 0;

}