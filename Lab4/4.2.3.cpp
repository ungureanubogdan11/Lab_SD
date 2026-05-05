#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream cin("dijkstra.in");
ofstream cout("dijkstra.out");

struct salut {
    int cost;
    int nod;
    bool operator < (const salut & other) const {
        return cost > other.cost;
    }
};

int n, m;
vector<salut> G[100001];
int d[100001];

void dijkstra() {
    for(int i = 2; i <= n; ++i) d[i] = 1e9;
    priority_queue<salut> pq;
    pq.push({0, 1});
    while(pq.size()) {
        salut nod = pq.top();
        pq.pop();

        if(nod.cost > d[nod.nod]) continue;

        for(auto nodnou : G[nod.nod]) {
            if(d[nod.nod] + nodnou.cost < d[nodnou.nod]) {
                d[nodnou.nod] = d[nod.nod] + nodnou.cost;
                pq.push({d[nodnou.nod], nodnou.nod});
            }
        }
    }
}

int main() {
    
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({c, b});
    }

    dijkstra();

    for(int i = 2; i <= n; ++i) {
        if(d[i] == (int) 1e9) cout << "0 ";
        else cout << d[i] << ' ';
    }
}

// https://www.infoarena.ro/job_detail/3352457