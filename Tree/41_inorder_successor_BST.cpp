#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printInOrder(TreeNode* root);
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p);

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "BST: ";
    printInOrder(root);
    cout << endl;

    TreeNode* p = root->left->right;
  
    TreeNode* successor = inorderSuccessor(root, p);

    if (successor) {
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    } else {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }

    return 0;
}


 TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = nullptr;
    while (root) {
        if (p->val >= root->val) {
            root = root->right;
        }
        else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}