#include <fstream>
#include <stack>

using namespace std;

ifstream cin("xormax.in");
ofstream cout("xormax.out");

int n;
int a[100001];
int trie[3200001][2];
int node_count;
int leaf[3200001];

void insert(int x, int idx) {
    
    int node = 0;
    for(int i = 30; i >= 0; --i) {
        int bit = (x >> i) & 1;

        if(trie[node][bit] == 0) {
            trie[node][bit] = ++node_count;
        }

        node = trie[node][bit];
    }

    leaf[node] = idx;
}

int query(int x) {

    int node = 0;

    for(int i = 30; i >= 0; --i) {
        int bit = (x >> i) & 1;
        int op_bit = 1 - bit;

        if(trie[node][op_bit]) {
            node = trie[node][op_bit];
        }
        else {
            node = trie[node][bit];
        }

    }

    return leaf[node];
}


int main() {
    
    cin >> n;
    insert(0, 0);
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        a[i] = a[i - 1] ^ x;
    }

    int maxi = -1, st, dr;
    for(int i = 1; i <= n; ++i) {
        int best = query(a[i]);
        int val = a[i] ^ a[best]; 
        if(val > maxi) {
            maxi = val, st = best + 1, dr = i;
        }
        insert(a[i], i);
    }

    cout << maxi << ' ' << st << ' ' << dr << '\n';
}

// https://infoarena.ro/job_detail/3353270