#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> findVertical(TreeNode* root);
void printResult(const vector<vector<int>>& result);


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    vector<vector<int>> verticalTraversal = findVertical(root);

    cout << "Vertical Traversal:" << endl;
    printResult(verticalTraversal);

    return 0;
}

/* time : O(NlogN) , space: O(N)*/
vector<vector<int>> findVertical(TreeNode* root) {
    map<int, map<int, multiset<int>>> TreeNodes;
    queue<pair<TreeNode*, pair<int, int>>> todo;

    todo.push({root, {0, 0}});

    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();

        TreeNode* temp = p.first;
        int x = p.second.first;
        int y = p.second.second;

        TreeNodes[x][y].insert(temp->val);

        if (temp->left) {
            todo.push({temp->left, {x - 1, y + 1}});
        }

        if (temp->right) {
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;

    for (auto p : TreeNodes) {
        vector<int> col;
            for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}

void printResult(const vector<vector<int>>& result) {
    for (auto level : result) {
        for (auto TreeNode : level) {
            cout << TreeNode << " ";
        }
        cout << endl;
    }
    cout << endl;
}