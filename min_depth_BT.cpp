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


//BFS usually better for min depth

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root){
            return 0;  // empty tree
        } 

        queue<pair<TreeNode*, int>> q; 
        q.push({root, 1});  // push root with depth = 1

        while (!q.empty()) {
            //start expanding from root node
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();

            // If this node is a leaf, return its depth immediately
            if (!node->left && !node->right) {
                return depth;
            }

            // Otherwise push children with incremented depth
            if (node->left) {
                q.push({node->left, depth + 1});
            }
            if (node->right) {
                q.push({node->right, depth + 1});
            }
        }
        return 0; 
    }
};


//DFS

// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if (!root) { //Checks if the tree is empty. We need it here because in DFS we're returning INT_MAX (see logic below)
//             return 0;
//         }
//         return dfs(root, 1); //Since tree isn't empty pass 1 as depth
//     }

//     int dfs(TreeNode* root, int depth) {
//         if (!root) {
//             return INT_MAX;    // if we return 0 then it'll always be selected as "min" between right and left recursion, even though it may just be a node that doesn't have either left or right child but does have the other one, so that's not a leaf node, this is why we had to handle the case of empty tree separately initially
//         }
//         if (!root->left && !root->right) {
//             return depth;      // both left and right child are absent => leaf, so report depth
//         }

//         return min(dfs(root->left, depth + 1), dfs(root->right, depth + 1)); 
//     }
// };
