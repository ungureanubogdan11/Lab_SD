#include <iostream>
#include <list>

using namespace std;

class Map {
    int size;
    int elements;
    vector<list<int>> m;
    
    int hash_function(int x) {
        return (x + 1) % size; // stiu ca nu e cea mai buna functie
    }

    void resize() {
        vector<list<int>> aux = m;
        size *= 2;
        m.assign(size, list<int>{});
        elements = 0;

        for(int i = 0; i < aux.size(); ++i) {
            for(auto x : aux[i]) {
                insert(x);
            }
        }

    }

    public:

    Map() {
        size = 16;
        elements= 0;
        m.assign(size, list<int>{});
    } 

    void insert(int x) {
        int y = hash_function(x);
        m[y].push_back(x);
        elements++;

        double load = (double) elements / size; 
        if(load >= 0.75) resize();
    }

    bool exists(int x) {
        int y = hash_function(x);
        auto it = find(m[y].begin(), m[y].end(), x);
        return (it != m[y].end());
    }

    void erase(int x) {

        int y = hash_function(x);
        auto it = find(m[y].begin(), m[y].end(), x);
        if(it != m[y].end()) m[y].erase(it), elements--;
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