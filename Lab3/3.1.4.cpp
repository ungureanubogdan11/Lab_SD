#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <time.h>

using namespace std;

class perfect_hash {
    int a, b; // primary parameters
    vector<int> c, d; // secondary parameters
    int p;
    int size;
    vector<list<int>> m; // first table
    vector<vector<int>> M; // final table

    int hash_function(int x, int p1, int p2, int mod) {
        return ((1ll * p1 * x + p2) % p) % mod;
    }  

    void choose_parameters(int & p1, int & p2) {
        std::mt19937 gen(time(0));
        std::uniform_int_distribution<> distrib(1, p - 1);
        p1 = distrib(gen);
        p2 = distrib(gen);
    }

    void init_bucket(const list<int> & l, const int ind) {
        choose_parameters(c[ind], d[ind]);


        for(auto x : l) {
            int y = hash_function(x, c[ind], d[ind], M[ind].size());
            
            if(M[ind][y] == -1) {
                M[ind][y] = x;
            }
            else {
                M[ind].clear(); 
                M[ind].assign(m[ind].size() * m[ind].size(), -1);
                init_bucket(l, ind);
                return;
            }

        }
    }

    public:
    perfect_hash(const int size, const int p) {
        this->size = size;
        this->p = p;
        m.assign(size, list<int>());
    }

    void init(const vector<int> & v) {
        choose_parameters(a, b);        

        for(auto x : v) {
            int y = hash_function(x, a, b, size);
            m[y].push_back(x);
        }

        int s = 0;
        for(int i = 0; i < size; ++i) {
            s += m[i].size() * m[i].size();
        }

        if(s > 4 * v.size()) {
            m.clear();
            init(v);
            return;
        }

        M.assign(size, vector<int>());
        c.assign(size, 0);
        d.assign(size, 0);
        for(int i = 0; i < size; ++i) {
            M[i].assign(m[i].size() * m[i].size(), -1);
            init_bucket(m[i], i);
            m[i].clear();
        }

    }

    bool exists(int x) {
        int y = hash_function(x, a, b, size);
        
        if(M[y].empty()) return 0;
        int z = hash_function(x, c[y], d[y], M[y].size());

        return (M[y][z] == x);
    }

};

int main() {
    vector<int> v({1, 2, 3, 10, 30, 20});

    perfect_hash map(v.size(), 1e9 + 7);
    map.init(v);

    cout << map.exists(10) << ' ' << map.exists(15) << ' ' << map.exists(20) << '\n';

    return 0;
}

/**
    impartim cele n numere in n bucket-uri in functie de hash-ul lor
    pentru fiecare bucket creem un alt tabel de marime size^2 
    pentru a putea pune numerele intr-un loc unic, fara a exista coliziuni

 */