#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool checkSymmetry(TreeNode* leftNode, TreeNode* rightNode);
bool isSymmetric(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root))
        cout << "This Tree is Symmetrical\n";
    else
        cout << "This Tree is NOT Symmetrical\n";

    return 0;
}

/* time : O(N), Space : O(N) */

bool checkSymmetry(TreeNode* leftNode, TreeNode* rightNode) {
    if (!leftNode && !rightNode)
        return true;

    if (!leftNode || !rightNode)
        return false;

    return (leftNode->val == rightNode->val) &&
           checkSymmetry(leftNode->left, rightNode->right) &&
           checkSymmetry(leftNode->right, rightNode->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;

    return checkSymmetry(root->left, root->right);
}