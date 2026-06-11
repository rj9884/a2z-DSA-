#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void flatten(TreeNode* root);
void flatten(TreeNode* root, TreeNode*& prev);
void printPreorder(TreeNode* root);
void printFlattenTree(TreeNode* root);

void flattenBetter(TreeNode* root);
void flattenOptimal(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(7);

    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    // flatten(root);
    // flattenBetter(root);
    flattenOptimal(root);

    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;

    return 0;
}


// Brute 
/* time O(N) , Space : O(N)*/

void flatten(TreeNode* root, TreeNode*& prev) {
    if (!root) return;

    flatten(root->right, prev);
    flatten(root->left, prev);

    root->right = prev;
    root->left = nullptr;

    prev = root;
}

void flatten(TreeNode* root) {
    TreeNode* prev = nullptr;
    flatten(root, prev);
}

void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printFlattenTree(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
}


// Better
/* Time : O(N) , Space : O(logN) */ 

void flattenBetter(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* cur = st.top();
        st.pop();
        if (cur->right != nullptr) st.push(cur->right);
        if (cur->left != nullptr) st.push(cur->left);
        if (!st.empty()) cur->right = st.top();
        cur->left = nullptr;
    }
}


// Optimal
/* time : O(2N) , Space: O(1) */

void flattenOptimal(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            TreeNode* pre = curr->left;
            while (pre->right) {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;

            curr->left = NULL;
        }
        curr = curr->right;
    }
}