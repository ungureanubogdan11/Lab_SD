#include <iostream>

using namespace std;

string s[1001];
int p = 57, MOD = 1e9 + 7, h[1001];
int n;

int hash_function(const string & s) {
    int ans = 1;
    for(int i = 0; i < s.size(); ++i) {
        ans = (ans * p + s[i]) % MOD;
    }
    return ans;
}

int main() {

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> s[i];
    for(int i = 1; i <= n; ++i) {
        h[i] = hash_function(s[i]);
        cout << h[i] << '\n';
    }

    return 0;
}