#include <iostream>

using namespace std;

int n, k;
int v[100001];

int partition(int st, int dr)
{   
    int pivot = v[dr]; // ultimul numar ca pivot
    int index = st - 1;
    for(int i = st; i < dr; ++i) {
        if(v[i] <= pivot) {
            index++;
            swap(v[i], v[index]);
        }
    }
    swap(v[index + 1], v[dr]);
    return index + 1;
}

int quickselect(int st, int dr, int k)
{
    if(st == dr) {
        return v[st];
    }

    int index = partition(st, dr);
    
    if(k == index) {
        return v[index];
    }
    else if(k < index) {
        return quickselect(st, index - 1, k);
    }
    else {
        return quickselect(index + 1, dr, k);
    }

}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> v[i];

    int ans = quickselect(1, n, k);
    cout << ans << '\n';
    
    return 0;
}

/**
input:
7 4
7 10 3 8 9 23 5 

output:
8

 */