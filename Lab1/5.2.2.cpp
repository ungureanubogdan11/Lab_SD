#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <cstdlib>

using namespace std;

vector<int> v;
unordered_map<int, int> m;

int main()
{
    srand(time(0));
    int q; cin >> q;
    while(q--) {
        int op; cin >> op; // 1 insert, 2 random pop
        if(op == 1) {
            int x; cin >> x;
            v.push_back(x);
        }
        else if(op == 2) {
            int random_index = rand() % v.size();
            swap(v.back(), v[random_index]);
            v.pop_back();
        }
        for(auto x : v) cout << x << ' ';
        cout << '\n';
    }
}