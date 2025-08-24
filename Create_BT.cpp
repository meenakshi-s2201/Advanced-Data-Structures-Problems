#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    //constructor - not using as intializer list is better
    // TreeNode(int v){
    //     val = v;
    //     left = nullptr;
    //     right = nullptr;
    // }

    //initializer list - better as they directly construct the members (instead of assigning after default construction) 
    // and more efficient as it avoids an extra step of creating + assigning
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};



TreeNode* buildTreeLevelOrder() {
    cout << "Enter data for the root node (enter -1 for no node): ";
    int data;
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(data);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        cout << "Enter left child data for " << temp->val << " (enter -1 for no node): ";
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new TreeNode(leftData);
            q.push(temp->left);
        }

        cout << "Enter right child data for " << temp->val << " (enter -1 for no node): ";
        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new TreeNode(rightData);
            q.push(temp->right);
        }
    }
    return root;
}





// Traversals
void preorder(TreeNode* root) {
    if (!root){
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (!root){
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}



//Delete at the end to free up space
void destroy(TreeNode* root) {
    if (!root){
        return;
    }
    destroy(root->left);
    destroy(root->right);
    delete root;
}


//Main
int main() {
    TreeNode* root = nullptr;

    root = buildTreeLevelOrder();

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