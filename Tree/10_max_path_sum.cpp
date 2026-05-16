#include <iostream>
#include <climits>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxPathSum(TreeNode* root);
int maxPathDown(TreeNode* node , int &maxi);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->right->right->right = new TreeNode(7);

    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;
    return 0;
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

int maxPathDown(TreeNode* node , int &maxi) {
    if(node == nullptr) return 0;

    int left = max(0 , maxPathDown(node->left , maxi));
    int right = max(0 , maxPathDown(node->right , maxi));

    maxi = max(maxi , left + right + node->data);

    return node->data + max(left , right);
}