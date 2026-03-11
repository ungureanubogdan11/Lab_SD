#include <iostream>

using namespace std;

int n, m;
int a[1001][1001];
int x_start, y_start;
int x_final, y_final;
const int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0};

void bfs()
{
    queue<pair<int, int>> q;
    q.push({x_start, y_start});
    while(!q.empty()) {
        auto nod = q.front();
        q.pop();
        for(int h = 0; h < 4; ++h) {
            int i = nod.first + di[h], j = nod.second + dj[h];
            if(a[i][j] == 0) {
                a[i][j] = a[nod.first][nod.second];
                q.push({i, j});
            }
        }
    }
}

void path(int x, int y)
{
    if(x == x_start && y == y_start) {
        cout << x << ' ' << y << '\n';
    }
    for(int h = 0; h < 4; ++h) {
        int i = x + di[h], j = y + dj[h];
        if(a[i][j] == a[x][y] - 1) {
            path(i, j);
            cout << i << ' ' << j << '\n';
            return;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    cin >> x_start >> y_start;
    cin >> x_final >> y_final;
    
    bfs();
    
    cout << "Path length: " << a[x_final][y_final] << '\n';
    path(x_final, y_final);

    return 0;
}