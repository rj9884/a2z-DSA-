#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void leftDFS(TreeNode* root, int level, vector<int> &res);
vector<int> leftView(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    vector<int> left = leftView(root);
    cout << "Left View: ";
    for (int val : left) cout << val << " ";

    return 0;
}

/* time : O(N) , Space : O(H)*/

void leftDFS(TreeNode* root, int level, vector<int> &res) {
    if(!root) return;

    if(res.size() == level) res.push_back(root->val);
    leftDFS(root->left, level+1, res);
    leftDFS(root->right, level+1, res);
}

vector<int> leftView(TreeNode* root) {
    vector<int>ans;
    leftDFS(root, 0, ans);

    return ans;
}