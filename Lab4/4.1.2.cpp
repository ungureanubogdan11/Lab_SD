/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #include <climits>
class Solution {
public:
    bool isValidBST(TreeNode* root, long long mini = -1e18, long long maxi = 1e18) {
        if(root == nullptr) return true;
        if(root->val <= mini || root->val >= maxi) return false;

        return 
        isValidBST(root->left, mini, min(maxi, 1ll * root->val)) && 
        isValidBST(root->right, max(mini, 1ll * root->val), maxi);
    }
};

// https://leetcode.com/problems/validate-binary-search-tree/submissions/1989444210/