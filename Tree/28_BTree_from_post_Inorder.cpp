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
TreeNode* buildTreeInPos(vector<int> &inorder, int is, int ie, vector<int>&postorder, int ps, int pe, map<int, int>&hm);
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = buildTree(inorder, postorder);

    cout << "Inorder of Unique Binary Tree Created:\n";
    printInorder(root);
    cout << endl;

    return 0;
}


/* Time : O(N), Space : O(N) */

TreeNode* buildTreeInPos(vector<int> &inorder, int is, int ie, vector<int>&postorder, int ps, int pe, map<int, int>&hm) {
    if(is > ie || ps > pe) return nullptr;

    TreeNode* root = new TreeNode(postorder[pe]);

    int inRoot = hm[postorder[pe]];
    int numLeft = inRoot - is;

    root->left = buildTreeInPos(inorder, is, inRoot-1, postorder, ps, ps+numLeft-1, hm);

    root->right = buildTreeInPos(inorder, inRoot+1, ie, postorder, ps+numLeft, pe-1, hm);

    return root;

}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() != postorder.size()) return nullptr;

    map<int, int>hm;
    for(int i = 0; i < inorder.size(); i++) {
        hm[inorder[i]] = i;
    }

    return buildTreeInPos(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, hm);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}