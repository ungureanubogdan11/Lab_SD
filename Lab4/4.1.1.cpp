#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node ( int value = 0)
    : val ( value ) , left ( nullptr ) , right ( nullptr )
    {}
    int val;
    Node * left ;
    Node * right ;
};

class BST {
private:
    Node * root = nullptr;
    Node * last = nullptr;

    Node * search(int val, Node * nod) {
        if(nod != nullptr) last = nod;
        if(nod == nullptr) return nullptr;
        if(nod->val == val) return nod;
        if(val < nod->val) return search(val, nod->left);
        if(val > nod->val) return search(val, nod->right);
        return nullptr;
    }

    Node* min_value_node(Node* nod) {
        Node* curr = nod;
        while (curr && curr->left != nullptr) curr = curr->left;
        return curr;
    }

    Node* erase(Node* nod, int x) {
        if (nod == nullptr) return nullptr;
        if (x < nod->val) nod->left = erase(nod->left, x);
        else if (x > nod->val) nod->right = erase(nod->right, x);
        else {
            if (nod->left == nullptr) {
                Node* temp = nod->right;
                delete nod;
                return temp;
            } else if (nod->right == nullptr) {
                Node* temp = nod->left;
                delete nod;
                return temp;
            }
            Node* temp = min_value_node(nod->right);
            nod->val = temp->val;
            nod->right = erase(nod->right, temp->val);
        }
        return nod;
    }

public:
    BST() = default;
    BST(int val) {
        root = new Node(val);  
    }

    void construct(const vector<int>& v) {
        for (int x : v) insert(x);
    }

    bool exists(int x) {
        return (search(x, root) != nullptr);
    }

    void insert(int x) {
        if (root == nullptr) {
            root = new Node(x);
            return;
        }
        if (exists(x)) return;
        if (x < last->val) last->left = new Node(x);
        else last->right = new Node(x);
    } 

    void erase(int x) {
        root = erase(root, x);
    }

    Node* successor(int x) {
        Node* curr = root;
        Node* succ = nullptr;
        while (curr != nullptr) {
            if (x < curr->val) {
                succ = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return succ;
    }

    Node* predecessor(int x) {
        Node* curr = root;
        Node* pred = nullptr;
        while (curr != nullptr) {
            if (x > curr->val) {
                pred = curr;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        return pred;
    }
};

int main() {
    
    return 0;
}