#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, TreeNode* left, TreeNode* right) : val(data), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);


    vector<vector<int>> ans = zigzagLevelOrder(root);

    cout << "[";
    for (auto &level : ans) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i != level.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;
    return 0;
}

/* time : O(N), Space: O(N) */

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if(!root) return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int>zigzag(size);

        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            int idx = leftToRight ? i : (size-1-i);
            zigzag[idx] = node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(zigzag);
    }
    return ans;
}