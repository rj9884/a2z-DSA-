#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* lca1 = lowestCommonAncestor(root, root->left, root->right);
    cout << "LCA of 2 and 8: " << lca1->val << endl;

    return 0;
}


/* time: O(H) , Space : O(1) , excluding call stack*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return nullptr;

    if(root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    if(root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}