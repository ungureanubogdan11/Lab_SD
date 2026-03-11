#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a, b, target;
int fr[1001];
struct ceva {
    int a, b, moves;
};

queue<ceva> q;

int vase(int aa, int bb, int moves = 0)
{
    q.push({aa, bb, moves});
    while(!q.empty()) {
        ceva nod = q.front();
        q.pop();
        
        if(fr[nod.a] && fr[nod.b]) continue;
        fr[nod.a] = fr[nod.b] = 1;
        
        if(nod.a == target || nod.b == target) {
            return nod.moves;
        }

        q.push({a, nod.b, nod.moves + 1});
        q.push({nod.a, b, nod.moves + 1});
        q.push({nod.a, 0, nod.moves + 1});
        q.push({0, nod.b, nod.moves + 1});
        q.push({min(a, nod.a + nod.b), max(0, nod.b - nod.a + a), nod.moves + 1});
        q.push({max(0, nod.a - nod.b + b), min(b, nod.b + nod.a), nod.moves + 1});
    }
    return -1;
}

int main()
{
    cin >> a >> b >> target;
    cout << vase(0, 0) << '\n'; 
}  
