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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        helper(root, ans); //need helper function to pass ans parameter as we want all recursive calls to add to the same vector
        return ans;
    }

    void helper(TreeNode* root, vector<int>& ans) { //used & as we're passing by reference so that changes are made in the same array
        if (!root){ // ends current recursive branch
            return;
        } 
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
};