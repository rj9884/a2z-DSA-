#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> iterativeInorder(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);


    cout << "Inorder: ";
    vector<int> ans = iterativeInorder(root);
    for(const auto &val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

vector<int> iterativeInorder(TreeNode* root) {
    vector<int>inorder;
    stack<TreeNode*>st;
    TreeNode* node = root;

    while(true) {
        if(node != nullptr) {
            st.push(node);
            node = node->left;
        }
        else {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    return inorder;
}