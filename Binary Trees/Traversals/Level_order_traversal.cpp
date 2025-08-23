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
    //BFS but separate vectors for each level inside the ans vector
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }

        queue<TreeNode*> q;
        //The queue always holds the nodes of “the next level to process.”
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int>levelVector;

            for(int i=0; i<levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                levelVector.push_back(node->val);

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(levelVector);
        }
        return ans;

    }
};