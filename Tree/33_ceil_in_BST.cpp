#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x) , left(nullptr), right(nullptr) {}
};

void printInOrder(TreeNode* root);
int findCeil(TreeNode* root, int val);



int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    int target = 8;
    int ceil = findCeil(root, target);
    
    if(ceil != -1){
        cout << "Ceiling of " << target << " is: " << ceil << endl;
    }
    else{
        cout << "No ceiling found!" << endl;
    }
    
    return 0;
}


void printInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

/* time : O(logN) , space : O(1) */

int findCeil(TreeNode* root, int val) {
    int ceil = -1;
    while(root) {
        if(val == root->val) {
            ceil =  val;
            return ceil;
        }
        else if(val > root->val) root = root->right;
        else {
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}