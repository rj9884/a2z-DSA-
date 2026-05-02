#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, struct TreeNode *left, struct TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(struct TreeNode* root);

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>>ans = levelOrder(root);
    for(const auto& row: ans) {
        for(const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int>level;

        for(int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}