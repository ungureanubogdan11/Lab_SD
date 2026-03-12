#include <iostream>

using namespace std;

int a[200001];
int n, s;

int main()
{
    cin >> n >> s;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    pair<int, int> ans = {0, 0};
    int st = 1, dr = n;
    int mini = 2e9;
    while(st <= dr) {
        int sum = a[st] + a[dr];
        if(abs(sum - s) < mini) {
            ans = {st, dr};
        }
        if(sum < s) st++;
        else dr--;
    }
    cout << ans.first << ' ' << ans.second; 
}