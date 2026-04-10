#include <fstream>
#include <deque>

using namespace std;

ifstream cin("deque.in");
ofstream cout("deque.out");

int n, k;
int a[5000001];
deque<int> dq;

int main() {
    
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    long long sum = 0;
    
    for(int i = 1; i <= n; ++i) {
        
        while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);

        while(dq.front() <= i - k) dq.pop_front();
        
        if(i >= k) {
            sum += a[dq.front()];
        }

    }

    cout << sum << '\n';

    return 0;
}   

// https://www.infoarena.ro/job_detail/3350231