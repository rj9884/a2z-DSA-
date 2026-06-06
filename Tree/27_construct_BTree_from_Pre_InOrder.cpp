#include <iostream>
#include <map>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printInorder(TreeNode* root);
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap);

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Inorder of Unique Binary Tree Created:\n";
    printInorder(root);
    cout << endl;

    return 0;
}


/* Time : O(N), Space : O(N) */

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}

TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap) {
    
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inRoot = inMap[root->val];

    int numsLeft = inRoot - inStart;

    root->left = build(preorder, preStart + 1, preStart + numsLeft,
                        inorder, inStart, inRoot - 1, inMap);
    root->right = build(preorder, preStart + numsLeft + 1, preEnd,
                        inorder, inRoot + 1, inEnd, inMap);

    return root;
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}