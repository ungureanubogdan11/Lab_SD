#include <fstream>

using namespace std;

ifstream cin("trie.in");
ofstream cout("trie.out");

struct TrieNode {    
    TrieNode* children[26];
    int cnt;
    int precnt;

    TrieNode() {
        cnt = 0;
        precnt = 0;
        for(int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
    ~TrieNode() {
        for(int i = 0; i < 26; ++i) {
            if(children[i]) delete children[i];
        }
    }
};

class Trie {
    TrieNode* root;

public: 
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }

    void insert(const string & s) {
        TrieNode * curr = root;
        for(const char c : s) {
            if(curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
            curr->precnt++;
        }
        curr->cnt++;
    }

    void erase(const string & s) {
        if(count(s) == 0) return;

        TrieNode * curr = root;
        for(const char c : s) {
            TrieNode * next = curr->children[c - 'a'];
            next->precnt--;
            if(next->precnt == 0) {
                delete next;
                curr->children[c - 'a'] = nullptr;
                return;
            }

            curr = next;
        }
        curr->cnt--;
    }

    int count(const string & s) {
        TrieNode * curr = root;
        for(const char c : s) {
            if(curr->children[c - 'a'] == nullptr) return 0;
            curr = curr->children[c - 'a'];
        }
        return curr->cnt;
    }

    int longest_common_prefix(const string & s) {
        TrieNode * curr = root;
        int ans = 0;
        for(const char c : s) {
            TrieNode * next = curr->children[c - 'a'];
            if(next != nullptr) ans++;
            else break;
            curr = next;
        }
        return ans;
    }

};

int main()
{
    int op;
    string word;
    Trie t;
    while(cin >> op >> word) {
        // cout << op << ' ' << word << '\n';
        if(op == 0) {
            t.insert(word);
        }
        if(op == 1) {
            t.erase(word);
        }
        if(op == 2) {
            cout << t.count(word) << '\n';
        }
        if(op == 3) {
            cout << t.longest_common_prefix(word) << '\n';
        }
    }
    return 0;
}

// https://www.infoarena.ro/job_detail/3353085