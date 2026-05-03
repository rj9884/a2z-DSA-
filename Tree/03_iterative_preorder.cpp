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

vector<int> iterativePreorder(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);


    cout << "Preorder: ";
    vector<int> ans = iterativePreorder(root);
    for(const auto &val : ans) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}

/* time: O(N), Space: O(H) ; H = height of Bin Tree*/
vector<int> iterativePreorder(TreeNode* root) {
    vector<int>preorder;
    if(!root) return preorder;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        root = st.top();
        st.pop();
        if(root->right != nullptr) st.push(root->right);
        if(root->left != nullptr) st.push(root->left);
        preorder.push_back(root->val);
    }
    return preorder;
}