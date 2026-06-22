#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode *first, *middle, *last, *prev;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

public:
    Solution() : first(nullptr), middle(nullptr),
                 last(nullptr), prev(nullptr) {}

    void recoverTree(TreeNode* root) {
        inorder(root);

        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }

    void printInorder(TreeNode* root) {
        if (!root) return;

        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
};

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution sol;

    cout << "Before fixing: ";
    sol.printInorder(root);
    cout << endl;

    sol.recoverTree(root);

    cout << "After fixing: ";
    sol.printInorder(root);
    cout << endl;

    return 0;
}