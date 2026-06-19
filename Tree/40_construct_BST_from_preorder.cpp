#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int> & preorder, int &i, long long bound);
TreeNode* bstFromPreorder(vector<int>& preorder);
void printInOrder(TreeNode* root);


int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode* root = bstFromPreorder(preorder);

    cout << "Inorder Traversal of BST constructed from preorder traversal:\n";
    printInOrder(root);
    cout << endl;

    return 0;
}


TreeNode* buildTree(vector<int> & preorder, int &i, long long bound) {
    if(i == preorder.size() || preorder[i] > bound) return nullptr;
    TreeNode* root = new TreeNode(preorder[i++]);

    root->left = buildTree(preorder, i, root->val);
    root->right = buildTree(preorder, i, bound);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;

    return buildTree(preorder, i, LLONG_MAX);
}

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}
