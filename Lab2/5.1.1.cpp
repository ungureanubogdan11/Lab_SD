#include <iostream>
#include <stack>

using namespace std;

int n;
int a[1001];
int ans[1001];

int main()
{   
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    stack<int> s;
    s.push(1);
    for(int i = 2; i <= n; ++i) {
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(s.empty()) ans[i] = 0;
        else ans[i] = s.top();
        s.push(i);
    }

    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}