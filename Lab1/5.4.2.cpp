#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

double bs_square_root(double x)
{
    double st = 1, dr = x;
    double rez, diff = 1e9;
    while(st <= dr) {
        double mij = (st + dr) / 2.;
        double aux = mij * mij;

        if(abs(x - aux) < diff) {
            diff = abs(x - aux), rez = mij;
        }


        if(aux < x) st = mij + 0.00000001;
        else dr = mij - 0.00000001;
    }
    return rez;
}

double heron_square_root(int x)
{
    double curr = x / 2.;
    double diff = 0.01;

    while(1) {
        double next = 0.5 * (curr + x / curr);
        if(abs(next - curr) < diff) {
            return next;
        }
        curr = next;
    }

    return curr;
}

int main()
{
    int x = 1;
    auto start_time = time(0);
    int cnt = 0;
    while(difftime(time(0), start_time) < 1.0) {
        
        // int sqrt_x = bs_square_root(x);
        int sqrt_x = heron_square_root(x);
        // int sqrt_x = sqrt(x);
        cnt++;
    }
    cout << "Computed " << cnt << " square roots in 1 second.\n";

}