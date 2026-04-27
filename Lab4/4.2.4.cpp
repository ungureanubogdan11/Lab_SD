#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int v[100001];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> v[i], pq.push(v[i]);
    int rez = 0;
    while(pq.size() > 1) {
        int x = pq.top(); pq.pop(); int y = pq.top(); pq.pop();
        rez += (y + x);
        pq.push(y + x);
    }
    cout << rez;
    return 0;
}

// https://www.pbinfo.ro/detalii-evaluare/44209345