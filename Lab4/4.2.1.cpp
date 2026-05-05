#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> v;

public: 

    void insert(int x) {
        v.push_back(x);
        int index = v.size() - 1;
        
        while(x < v[(index - 1) / 2]) {
            swap(v[index], v[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    int top() {
        return v[0];
    }

    void pop() {
        if (v.empty()) return;

        v[0] = v.back();
        v.pop_back();

        if (v.empty()) return;

        int index = 0;
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int mini = index;

            if (left < v.size() && v[left] < v[mini]) {
                mini = left;
            }
            if (right < v.size() && v[right] < v[mini]) {
                mini = right;
            }

            if (mini != index) {
                swap(v[index], v[mini]);
                index = mini;
            } else {
                break;
            }
        }
    }

};

int main()
{
    Heap h;
    h.insert(5);
    h.insert(51);
    h.insert(52);
    h.insert(53);
    h.insert(54);
    cout << h.top() << '\n';
    h.pop();
    h.pop();
    cout << h.top() << '\n';
}