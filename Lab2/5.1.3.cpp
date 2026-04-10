#include <fstream>
#include <stack>

using namespace std;

ifstream cin("fadema.in");
ofstream cout("fadema.out");

int n, m;
int a[1001][1001], skyline[1001][1001];
int st[1001], dr[1001];
int lst[1001][1001], ldr[1001][1001];

void gen_st(int i)
{
    stack<int> s; 
    for(int j = 1; j <= n; ++j) {
        while(!s.empty() && skyline[s.top()][i] >= skyline[j][i]) s.pop();
        if(s.empty()) st[j] = 0;
        else st[j] = s.top();
        s.push(j);
    }
}

void gen_dr(int i)
{
    stack<int> s; 
    for(int j = n; j >= 1; --j) {
        while(!s.empty() && skyline[s.top()][i] >= skyline[j][i]) s.pop();
        if(s.empty()) dr[j] = n + 1;
        else dr[j] = s.top();
        s.push(j);
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

    for(int j = 1; j <= m; ++j) {
        for(int i = 1; i <= n; ++i) {
            if(i == 1) lst[i][j] = 0;
            else if(a[i][j] == a[i - 1][j]) lst[i][j] = i - 1;
            else lst[i][j] = lst[i - 1][j];
        }
        for(int i = n; i >= 1; --i) {
            if(i == n) ldr[i][j] = n + 1;
            else if(a[i][j] == a[i + 1][j]) ldr[i][j] = i + 1;
            else ldr[i][j] = ldr[i + 1][j];
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == a[i][j - 1]) skyline[i][j] = 1;
            else skyline[i][j] = 1 + skyline[i][j - 1];
        }
    }
    int rez = -1;
    pair<int, int> x, y;
    for(int i = 1; i <= m; ++i) {
        gen_st(i);
        gen_dr(i);
        for(int j = 1; j <= n; ++j) {
            int val = skyline[j][i] * (min(dr[j], ldr[j][i]) - max(st[j], lst[j][i]) - 1);
            if(val > rez) rez = val;
            // cout << lst[j][i] << ' ' << ldr[j][i] << ' ' << val << '\n';
        }
    }
     cout << rez << '\n';
    return 0;
}

// https://www.infoarena.ro/job_detail/3350224