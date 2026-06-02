#include <iostream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root);
void changeTree(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    changeTree(root);

    cout << "Binary Tree after Children Sum Property: " ;
    inorderTraversal(root);
    cout << endl;
    return 0;
}

/*time : O(N) , Spcae: O(H) */

void inorderTraversal(TreeNode* root) {
    if (!root) return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void changeTree(TreeNode* root) {
    if(!root) return;

    int child = 0;
    if(root->left) child += root->left->val;
    if(root->right) child += root->right->val;

    if(child >= root->val) root->val = child;
    else {
        if(root->left) root->left->val = root->val;
        else if(root->right) root->right->val = root->val; 
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total += root->left->val;
    if(root->right) total += root->right->val;

    if(root->left || root->right) root->val = total;
}