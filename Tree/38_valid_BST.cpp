#include <iostream>
#include <climits>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};



bool checkValidBST(TreeNode* root, long long min, long long max);


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);

    cout << checkValidBST(root, LLONG_MIN, LLONG_MAX) << endl;
    
    return 0;
}

bool checkValidBST(TreeNode* root, long long min, long long max) {
    if(!root) return true;

    if(root->val <= min || root->val >= max) return false;
    return checkValidBST(root->left, min, root->val) &&
        checkValidBST(root->right, root->val, max);
}