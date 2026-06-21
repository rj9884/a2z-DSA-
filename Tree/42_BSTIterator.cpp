
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*>st;
    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
     void pushAll(TreeNode* node) {
        for(; node != nullptr; st.push(node), node = node->left);
    }
};
void printInOrder(TreeNode* root);

/*time : O(1), space : O(H) */

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    
    cout << "Tree Initialised: ";
    printInOrder(root);
    cout << endl;

    BSTIterator bstIterator(root);
    

    cout << "Functions Called:" << endl;
    cout << "BSTIterator()" << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;

    return 0;
}
                                


void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}