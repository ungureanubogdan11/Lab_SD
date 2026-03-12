#include <iostream>

using namespace std;

int a[200001];
int sp[200001];
int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) sp[i] = sp[i - 1] + a[i];

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << sp[r] - sp[l - 1] << '\n';
    }
}