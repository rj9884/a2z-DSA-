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

vector<vector<int>> preInPostTraversal(TreeNode* root);
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    
    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

/*time : O(3N) , Space : O(3N)*/
vector<vector<int>> preInPostTraversal(TreeNode* root) {
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if(!root) return {};

    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if(it.second == 1) {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->left != nullptr) {
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2) {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->right != nullptr) {
                st.push({it.first->right, 1});
            }
        }
        else {
            post.push_back(it.first->val);
        }
    }
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}