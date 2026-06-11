#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int val);

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* result = searchBST(root, 2);

    if (result)
        cout << "Node found: " << result->val << endl;
    else
        cout << "Node not found" << endl;

    return 0;
    return 0;
}

TreeNode* searchBST(TreeNode* root, int val) {
    while(root && root->val != val) {
        root = val < root->val ? root->left : root->right;
    }

    return root;
}