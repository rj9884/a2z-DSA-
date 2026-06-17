#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

TreeNode* insertNode(TreeNode* root, int key);
void printInOrder(TreeNode* root);

int main() {
    TreeNode* root = nullptr;
    
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 7);

    cout << "In-order traversal: ";
    printInOrder(root);
    cout << endl; 

    return 0;
}

/* time : O(logN) */ 

TreeNode* insertNode(TreeNode* root, int key) {
    if(!root) return new TreeNode(key);

    TreeNode* curr = root;

    while(true) {
        if(curr->val <= key) { 
            if(curr->right) {
                curr = curr->right;
            } else {
                curr->right = new TreeNode(key);
                break;
            }
        }
        else { 
            if(curr->left) {
                curr = curr->left;
            } else {
                curr->left = new TreeNode(key);
                break;
            }
        }
    }
    return root;
}

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}
