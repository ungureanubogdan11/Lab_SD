#include <iostream>
#include <list>

using namespace std;

class Map {
    int size;
    int elements;
    vector<int> v;
    
    int hash_function(int x) {
        return (x + 1) % size; // stiu ca nu e cea mai buna functie
    }

    void resize() {
        vector<int> aux = v;
        size *= 2;
        v.assign(size, 0);
        elements = 0;

        for(auto x : aux) {
            if(x) insert(x);
        }

    }

    public:

    Map() {
        size = 16;
        elements = 0;
        v.assign(size, 0);
    }

    void insert(int x) {
        int y = hash_function(x);
        while(v[y]) {
            y = hash_function(y);
        }
        v[y] = x;
        elements++;

        double load = (double) elements / size; 
        if(load >= 0.6) resize();
    }

    bool exists(int x) {
        int y = hash_function(x);
        auto it = find(v.begin(), v.end(), x);
        return (it != v.end());
    }

    void erase(int x) {

        int y = hash_function(x);
        auto it = find(v.begin(), v.end(), x);
        if(it != v.end()) *it = 0, elements--;
    }


};

int main()
{
    Map m;
    m.insert(10), m.insert(13), m.insert(20);
    cout << m.exists(10) << '\n' << m.exists(21) << '\n';
    m.erase(10);
    cout << m.exists(10) << '\n';
}