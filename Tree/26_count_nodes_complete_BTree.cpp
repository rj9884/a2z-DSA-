#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, int &count);
int countNodesBrute(TreeNode* root);
int countNodesOptimal(TreeNode* root);
int findHeightLeft(TreeNode* node);
int findHeightRight(TreeNode* node);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // int totalNodes = countNodesBrute(root);
    int totalNodes = countNodesOptimal(root);

    cout << "Total number of nodes in the Complete Binary Tree: " << totalNodes << endl;

    return 0;
}

/*Time : O(N) , SPace: O(N) */

void inorder(TreeNode* root, int &count) {
    if (root == NULL) {
        return;
    }
    count++;
    inorder(root->left, count);
    inorder(root->right, count);
}

int countNodesBrute(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    inorder(root, count);
    return count;
}


// Optimal

/* time : O(logN * logN) , space : O(N) ~ O(H) */
int countNodesOptimal(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if (lh == rh) {
        return (1 << lh) - 1;
    }
    return 1 + countNodesOptimal(root->left) + countNodesOptimal(root->right);
}

int findHeightLeft(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}

int findHeightRight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->right;
    }
    return height;
}
