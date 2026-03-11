#include <iostream>
#include <stack>

using namespace std;

int n;
int a[1001];
int st[1001];
int dr[1001];

void gen_left()
{
    st[1] = 0;
    stack<int> s;
    s.push(1);
    for(int i = 2; i <= n; ++i) {
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(s.empty()) st[i] = 0;
        else st[i] = s.top();
        s.push(i);
    }
}

void gen_right()
{
    dr[n] = n + 1;
    stack<int> s;
    s.push(n);
    for(int i = n - 1; i >= 1; --i) {
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(s.empty()) dr[i] = n + 1;
        else dr[i] = s.top();
        s.push(i);
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    gen_left();
    gen_right();

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, a[i] * (dr[i] - st[i] + 1));
    }

    cout << ans << '\n';
}
