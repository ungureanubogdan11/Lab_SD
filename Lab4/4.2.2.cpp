/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    multiset<int> s;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto nod : lists) {
            while(nod != nullptr) {
                s.insert(nod->val);
                nod = nod->next;
            }
        }

        ListNode * root, * curr;
        if(s.size() == 0) return nullptr; 
        auto it = s.begin();
        root = new ListNode(*s.begin());
        it++;
        curr = root;
        for(; it != s.end(); ++it) {
            curr->next = new ListNode(*it); 
            curr = curr->next;
        }   

        return root;
    }
};

// https://leetcode.com/problems/merge-k-sorted-lists/submissions/1989591738/