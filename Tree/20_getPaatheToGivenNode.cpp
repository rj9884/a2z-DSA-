#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> solve(TreeNode* root, int nodeVal);
bool getPath(TreeNode* root, vector<int> & arr, int nodeVal);


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> path = solve(root, 5);

    for (int x : path) cout << x << " ";
    cout << endl;

    return 0;
}

/* time : O(N), Space : O(H) */

vector<int> solve(TreeNode* root, int nodeVal) {
    vector<int> arr;
    if(!root) return arr;

    getPath(root, arr, nodeVal);
    return arr;
}

bool getPath(TreeNode* root, vector<int> & arr, int nodeVal) {
    if(!root) return false;

    arr.push_back(root->val);

    if(root->val == nodeVal) return true;

    if(getPath(root->left, arr, nodeVal) ||
       getPath(root->right, arr, nodeVal)) return true;

    arr.pop_back();

    return false;
}