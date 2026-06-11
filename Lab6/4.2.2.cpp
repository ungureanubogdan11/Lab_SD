#include <fstream>
#include <vector>

using namespace std;

ifstream cin("inv.in");
ofstream cout("inv.out");

const int MOD = 9917;
int n;
vector<int> v, temp;
long long total_inversions = 0;

void merge(int st, int mij, int dr) {
    int i = st;
    int j = mij + 1;
    int k = st;

    while (i <= mij && j <= dr) {
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
            total_inversions += (mij - i + 1);
        }
    }

    while (i <= mij) {
        temp[k++] = v[i++];
    }

    while (j <= dr) {
        temp[k++] = v[j++];
    }

    for (i = st; i <= dr; ++i) {
        v[i] = temp[i];
    }
}

void mergeSort(int st, int dr) {
    if (st >= dr) {
        return;
    }
    int mij = st + (dr - st) / 2;
    mergeSort(st, mij);
    mergeSort(mij + 1, dr);
    merge(st, mij, dr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    v.resize(n);
    temp.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    mergeSort(0, n - 1);

    cout << total_inversions % MOD << "\n";

    return 0;
}

// https://infoarena.ro/job_detail/3356895