#include <iostream>

using namespace std;

int * v;
int size = 0, cap = 0;

void init()
{
    v = new int[1];
    cap = 1;
}

int get_size() 
{
    return size;
}

void pop_back()
{
    if(size > 0) size--;
}

void resize()
{   
    int * new_v = new int[2 * cap];
    cap *= 2;
    for(int i = 0; i < size; ++i) {
        new_v[i] = v[i];
    }

    delete[] v;
    v = new_v;

}

void push_back(int val)
{  
    if(size + 1 > cap) {
        resize();
    }

    size++;
    v[size - 1] = val;
}

void print()
{
    for(int i = 0; i < size; ++i) cout << v[i] << ' ';
    cout << '\n';
}

int main()
{
    init();
    push_back(7);
    push_back(10);
    push_back(8);
    push_back(2);
    cout << get_size() << '\n';
    pop_back();
    pop_back();
    cout << get_size() << '\n';
    push_back(4);
    cout << get_size() << '\n';
    print();
}