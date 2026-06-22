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
        // reverse --> true : before
        int reverse;
        void pushAll(TreeNode* node) {
            for(; node != nullptr;) {
                st.push(node);
                if(reverse) {
                    node = node->right;
                }
                else {
                    node = node->left;
                }
            }
        }
    public:
        BSTIterator(TreeNode* root, int isreverse) {
            reverse = isreverse;
            pushAll(root);
        }
        int next() {
            TreeNode* temp = st.top();
            st.pop();
            if(reverse) {
                pushAll(temp->left);
            }
            else {
                pushAll(temp->right);
            }
            return temp->val;
        }
        bool hasNext() {
            return !st.empty();
        }
        
 };

bool findTarget(TreeNode* root, int k);
void printInOrder(TreeNode* root);

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    cout << "Tree Initialized: ";
    printInOrder(root);
    cout << endl;

    int target = 22;

    bool exists = findTarget(root, target);

    if (exists) cout << "Pair with sum " << target << " exists." << endl;
    else cout << "Pair with sum " << target << " does not exist." << endl;

    return 0;
}

/* time : O(N) , space: O(H) * 2 */


 bool findTarget(TreeNode* root, int k) {
    if(!root) return false;

    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();

    while(i < j) {
        if(i+j == k) return true;
        else if(i+j < k) i = l.next();
        else j = r.next(); 
    }
    return false;
}

void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}