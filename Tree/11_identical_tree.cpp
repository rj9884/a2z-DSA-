#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, TreeNode* left, TreeNode* right) : val(data), left(left), right(right) {}
};

bool isSameTree(TreeNode* node1, TreeNode* node2);


int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);


    if (isSameTree(root1, root2)) {
        cout << "The binary trees are identical." << endl;
    } else {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}

bool isSameTree(TreeNode* node1, TreeNode* node2) {
    if(!node1 || !node2) return (node1 == node2);

    return (node1->val == node2->val)
        && isSameTree(node1->left, node2->left)
        && isSameTree(node1->right, node2->right);
}