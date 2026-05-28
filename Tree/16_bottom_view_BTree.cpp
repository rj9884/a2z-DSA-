#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

vector<int> bottomView(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    vector<int>ans = bottomView(root);

    cout << "Top View: " << endl;

    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/* TC: O(N) , SC: O(N) */

vector<int> bottomView(TreeNode* root) {
    vector<int>ans;
    if(!root) return ans;

    map<int, int>mpp;
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;

        mpp[line] = node->val;

        if(node->left) q.push({node->left, line-1});
        if(node->right) q.push({node->right, line+1});
    }

    for(const auto &it: mpp) {
        ans.push_back(it.second);
    }
    return ans;
}