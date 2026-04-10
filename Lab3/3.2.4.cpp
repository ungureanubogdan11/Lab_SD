#include <iostream>
#include <random>
#include <time.h>
#define int long long

using namespace std;

int n;
int v[100001];
int prefix_hash[100001];
unordered_map<int, long long> hash_value;
int expected_hash[100001];

signed main() {
    std::mt19937_64 rng(time(0));

    cin >> n;
    for(int i = 0; i < n; ++i) {
        hash_value[i] = rng();
    }
    
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
        prefix_hash[i] = prefix_hash[i - 1] + hash_value[v[i]];
    }

    expected_hash[0] = hash_value[0];
    for(int i = 1; i <= n; ++i) {
        expected_hash[i] = expected_hash[i - 1] + hash_value[i];
    }

    int q; 
    cin >> q;
    while(q--) {
        int st, dr; 
        cin >> st >> dr;
        int k = dr - st + 1;
        if(prefix_hash[dr] - prefix_hash[st - 1] == expected_hash[k - 1]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

}

/**
    input:
    5
    0 1 3 2 5
    2
    1 5
    1 4    

    output:
    NO
    YES

 */