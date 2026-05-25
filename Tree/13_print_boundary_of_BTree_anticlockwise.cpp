#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, TreeNode* left, TreeNode* right) : val(data), left(left), right(right) {}
};

bool isLeaf(TreeNode* root);
void addLeft(TreeNode* node, vector<int> &res);
void addLeaf(TreeNode* node, vector<int> &res);
void addRight(TreeNode* node, vector<int> &res);
vector<int> printBoundary(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->left->left->right = new TreeNode(7);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(9);

    vector<int>ans = printBoundary(root);

    for(const auto val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

bool isLeaf(TreeNode* root) {
    return root && !root->left && !root->right;
}

void addLeft(TreeNode* node, vector<int> &res) {
    TreeNode* curr = node->left;

    while(curr) {
        if(!isLeaf(curr)) res.push_back(curr->val);

        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
    
}

void addLeaf(TreeNode* node, vector<int> &res) {
    if(isLeaf(node)) {
        res.push_back(node->val);
        return;
    }
    if(node->left) addLeaf(node->left, res);
    if(node->right) addLeaf(node->right, res);
}

void addRight(TreeNode* node, vector<int> &res) {
    vector<int>temp;
    TreeNode* curr = node->right;

    while(curr) {
        if(!isLeaf(curr)) temp.push_back(curr->val);

        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    for(int i = temp.size() - 1; i >= 0; --i) {
        res.push_back(temp[i]);
    }
}

/* time : O(N) , Space: O(h) recursion stack + O(h) temp vector for right boundary */
vector<int> printBoundary(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->val);
    addLeft(root, res);
    addLeaf(root, res);
    addRight(root, res);

    return res;
}