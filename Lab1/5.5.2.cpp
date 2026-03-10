#include <iostream>

using namespace std;

int n, a[1001];

int main()
{
    cin >> n;
    for(int i = 0; i < n + 1; ++i) cin >> a[i];

    int slow = a[0], fast = a[0];
    do {
        slow = a[slow];
        fast = a[a[fast]];
    } while(slow != fast);

    fast = a[0];
    while(slow != fast) {
        slow = a[slow];
        fast = a[fast];
    }
    cout << slow << '\n';
}

/**

input:
7
1 2 7 3 5 3 2 4

output:
3

*/