class Solution {
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);

public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }

private:
    void traverse(TreeNode* root) {
        if (!root) return;

        traverse(root->left);

        if (prev != nullptr && root->val < prev->val) {
            if (first == nullptr) {
                first = prev;
            }
            second = root;
        }
        prev = root;

        traverse(root->right);
    }
};

// https://leetcode.com/problems/recover-binary-search-tree/