#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

void printInOrder(Node* root);
Node* findMin(Node* root);
Node* deleteNode(Node* root, int key);

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    
    deleteNode(root, 10);
    printInOrder(root);
    cout << endl;

    return 0;
}

void printInOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

Node* findMin(Node* root) {
    while (root->left)
        root = root->left;
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr)
            return root->right;
        else if (root->right == nullptr)
            return root->left;

        Node* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}