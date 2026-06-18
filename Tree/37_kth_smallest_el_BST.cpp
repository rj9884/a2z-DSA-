#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 };



int kthSmallest(TreeNode* root, int k);
int kthLargest(TreeNode* root, int k);
vector<int> kLargesSmall(TreeNode* root, int k);
void inorder(TreeNode* node, int& k, int& result);
void reverseInorder(TreeNode* node, int& k, int& result);



int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    
    int k = 1;
    vector<int> result = kLargesSmall(root, k);
    
    cout << "[" << result[0] << ", " << result[1] << "]" << endl; 
    
    return 0;
}


int kthSmallest(TreeNode* root, int k) {
    int result = -1;
    inorder(root, k, result);
    return result;
}

int kthLargest(TreeNode* root, int k) {
    int result = -1;
    reverseInorder(root, k, result);
    return result;
}

vector<int> kLargesSmall(TreeNode* root, int k) {
    return {kthSmallest(root, k), kthLargest(root, k)};
}

void inorder(TreeNode* node, int& k, int& result) {
    if (!node || result != -1) return;

    inorder(node->left, k, result);

    if (--k == 0) {
        result = node->data;
        return;
    }

    inorder(node->right, k, result);
}

void reverseInorder(TreeNode* node, int& k, int& result) {
    if (!node || result != -1) return;

    reverseInorder(node->right, k, result);

    if (--k == 0) {
        result = node->data;
        return;
    }

    reverseInorder(node->left, k, result);
}