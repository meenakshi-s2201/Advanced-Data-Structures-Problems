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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //postorder will tell us who is the parent 
        //and inorder will tell us who is the left child and who is the right

        //make hashmap for inorder vector to reduce lookup time to constant time
        map<int, int> hm;
        for (int i = 0; i < inorder.size(); i++) {
            hm[inorder[i]] = i;
        }

        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, hm);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe, map<int, int>& hm){
        if(ps>pe || is>ie){ 
            return nullptr;
        }

        //We start creating the tree, as we know the last node in postorder is the root of the tree
        TreeNode* root = new TreeNode(postorder[pe]);

        //Find its index in the inorder traversal
        int inRoot = hm[postorder[pe]]; 
        //This index divides the inorder vector into 2 parts : left side is the left subtree of the root node and right side is the right subtree

        // Number of nodes in the left subtree
        int numsLeft = inRoot - is; 

        // Recursively build the left and right subtrees
        root->left = helper(inorder, postorder, is, inRoot - 1, ps, ps + numsLeft - 1, hm);
        root->right = helper(inorder, postorder, inRoot + 1, ie, ps + numsLeft, pe - 1, hm);

        return root;
    }
};