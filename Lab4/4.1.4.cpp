/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:

void ser(TreeNode * root, string & s) {
    if(root == nullptr) return;
    
    if(s.size()) s += (',');
    s += to_string(root->val);

    ser(root->left, s);
    ser(root->right, s);
}

TreeNode* deser(const vector<int> & nums, int & index, int mini, int maxi) {
    if(index >= nums.size()) return nullptr;

    int val = nums[index];
    if(val < mini || val > maxi) return nullptr;

    TreeNode * root = new TreeNode(val);
    index++;

    root->left = deser(nums, index, mini, val);
    root->right = deser(nums, index, val, maxi);
    
    return root;
}   

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        ser(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nums;
        string num;
        for(auto c : data) {
            if(c == ',') {
                nums.push_back(stoi(num));
                num.clear();
            }
            else num += c;
        }
        if(num.size()) nums.push_back(stoi(num));

        int index = 0;
        return deser(nums, index, INT_MIN, INT_MAX);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

// https://leetcode.com/problems/serialize-and-deserialize-bst/submissions/1989538055/