#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to compute height of each node
int computeHeights(TreeNode* root, unordered_map<TreeNode*, int>& heightMap) {
    if (!root){
        return -1;
    } 
    
    int left = computeHeights(root->left, heightMap);
    int right = computeHeights(root->right, heightMap);
    
    int h = 1 + max(left, right);
    heightMap[root] = h;
    
    return h;
}


// Example usage
int main() {
    /*
         1
        / \
       2   3
      / \
     4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    unordered_map<TreeNode*, int> heightMap;
    computeHeights(root, heightMap);

    // Print heights
    for (pair<TreeNode* const, int>& p : heightMap) {
        cout << "Node " << p.first->val << " has height " << p.second << endl;
    }

    return 0;
}