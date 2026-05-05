#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> iterativePostorder(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    
    cout << "Postorder: ";
    vector<int>ans = iterativePostorder(root);
    for(const auto& val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}


// Using 2 stacks
/* time : O(N) , space : O(2N) */
vector<int> iterativePostorder(TreeNode* root) {
    vector<int>postorder;
    stack<TreeNode*> st1, st2;
    st1.push(root);

    while(!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != nullptr) st1.push(root->left);
        if(root->right != nullptr) st1.push(root->right);
    }
    while(!st2.empty()) {
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder;
}