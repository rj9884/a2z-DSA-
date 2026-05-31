#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* P, TreeNode* Q);

int main() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    TreeNode* P = root->left;
    TreeNode* Q = root->right->left;

    TreeNode* sol = lowestCommonAncestor(root, P, Q);
    cout << "lowest Common Ancestor: " << sol->val << endl;
    return 0;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* P, TreeNode* Q) {
    if(!root || root == P || root == Q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, P, Q);
    TreeNode* right = lowestCommonAncestor(root->right, P, Q);

    if(!left) return right;
    else if(!right) return left;
    else return root;
}