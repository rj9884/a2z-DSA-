#include <iostream>
using namespace std;
struct Node {
    int data;       
    Node* left;    
    Node* right;    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isBalanced(Node* root);
int dfsHeight(Node* root);
int getHeight(Node* root);
bool isBalancedBruteForce(Node* root);

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    if (isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    if (isBalancedBruteForce(root)) {
        cout << "The tree is balanced (Brute Force)." << endl;
    } else {
        cout << "The tree is not balanced (Brute Force)." << endl;
    }

    return 0;
}




// Brute Force Approach: O(n^2) time complexity, Space : O(H) where H is the height of the tree

bool isBalancedBruteForce(Node* root) {
    if (root == nullptr) {
        return true;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (abs(leftHeight - rightHeight) <= 1 &&
        isBalanced(root->left) &&  
        isBalanced(root->right)) { 
        return true;
    }

    return false;
}

int getHeight(Node* root) {
    if (root == nullptr) return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Optimized Approach: O(n) time complexity, Space : O(H) where H is the height of the tree

bool isBalanced(Node* root) {
    return dfsHeight(root) != -1;
}

int dfsHeight(Node* root) {
    if (root == NULL) return 0;

    int leftHeight = dfsHeight(root->left);

    if (leftHeight == -1) return -1;

    int rightHeight = dfsHeight(root->right);

    if (rightHeight == -1)  return -1;

    if (abs(leftHeight - rightHeight) > 1)   return -1;

    return max(leftHeight, rightHeight) + 1;
}