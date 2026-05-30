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

void rightDFS(TreeNode* root, int level, vector<int> &res);
vector<int> rightView(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    vector<int> right = rightView(root);
   
    cout << "\nRight View: ";
    for (int val : right) cout << val << " ";
}

/* time : O(N) , Space : O(H)*/

void rightDFS(TreeNode* root, int level, vector<int> &res) {
    if(!root) return;

    if(res.size() == level) res.push_back(root->val);
    rightDFS(root->right, level+1, res);
    rightDFS(root->left, level+1, res);
}

vector<int> rightView(TreeNode* root) {
    vector<int>ans;
    rightDFS(root, 0, ans);

    return ans;
}