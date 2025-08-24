#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};


TreeNode* insertIntoBST(TreeNode* root, int data) {
    if (root == nullptr) {
        return new TreeNode(data);
    }

    if (data < root->val) {
        root->left = insertIntoBST(root->left, data);
    }
    else {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

TreeNode* buildBST() {
    TreeNode* root = nullptr; 
    cout << "Enter data for the BST (enter -1 to stop): ";
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data); 
        cout << "Enter next data (enter -1 to stop): ";
        cin >> data;
    }
    return root; 
}

void inorder(TreeNode* root) {
    if (!root) { 
        return;
    }
    inorder(root->left); 
    cout << root->val << " "; 
    inorder(root->right); 
}

void preorder(TreeNode* root) {
    if (!root) { 
        return;
    }
    cout << root->val << " "; 
    preorder(root->left); 
    preorder(root->right); 
}

void postorder(TreeNode* root) {
    if (!root) { 
        return;
    }
    postorder(root->left); 
    postorder(root->right); 
    cout << root->val << " "; 
}



void destroy(TreeNode* root) {
    if (!root) { 
        return;
    }
    destroy(root->left); 
    destroy(root->right); 
    delete root;
}



int main() {
    TreeNode* root = nullptr; 
    root = buildBST();

    cout << "\nIn-order Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postorder(root);
    cout << endl;

    destroy(root);
    return 0; 
}