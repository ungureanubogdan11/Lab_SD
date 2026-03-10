#include <iostream>

using namespace std;

int n, target;
int a[1001][1001];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    cin >> target;

    int line = n;
    for(int i = 1; i <= n; ++i) {
        if(target < a[i][i]) {
            line = i - 1;
            break;
        }
    }

    for(int i = 1; i <= line; ++i) {
        if(a[i][line] == target) {
            cout << i << ' ' << line << '\n';
            return 0;
        }
        if(a[line][i] == target) {
            cout << line << ' ' << i << '\n';
            return 0;
        }
    }

    cout << "Not found\n";
    return 0;

}
/**

input:
4
1 2 3 4
2 4 5 5
2 4 6 7
4 5 5 7
6

output:
3 3

*/