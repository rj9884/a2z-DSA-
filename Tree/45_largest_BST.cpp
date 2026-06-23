#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    struct NodeValue {
        int minNode, maxNode, maxSize;
        NodeValue(int minNode, int maxNode, int maxSize) : minNode(minNode), maxNode(maxNode), maxSize(maxSize) {}
    };

    NodeValue largestBSTSubtreeHelper(TreeNode* node) {
        if (!node) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        NodeValue left = largestBSTSubtreeHelper(node->left);
        NodeValue right = largestBSTSubtreeHelper(node->right);

        if (left.maxNode < node->data && node->data < right.minNode) {
            return NodeValue(
                min(node->data, left.minNode),
                max(node->data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    int largestBST(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution sol;
    cout << sol.largestBST(root) << endl; 

    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(15);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(8);
    root2->right->right = new TreeNode(7);

    cout << sol.largestBST(root2) << endl;  

    return 0;
}
