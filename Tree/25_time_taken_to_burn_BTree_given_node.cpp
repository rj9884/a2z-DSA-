#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& graph);
int minTime(TreeNode* root, int target);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    int target = 1;

    cout << "Minimum time to burn the tree: " << minTime(root, target) << endl;

    return 0;
}

/* time : O(N) , Spcae : O(N) */
int minTime(TreeNode* root, int target) {
    unordered_map<int, vector<int>> graph;
    buildGraph(root, nullptr, graph);

    unordered_set<int> visited;

    queue<int> q;
    q.push(target);
    visited.insert(target);

    int time = 0;

    while (!q.empty()) {
        int size = q.size();
        bool burned = false;

        for (int i = 0; i < size; i++) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                    burned = true;
                }
            }
        }

        if (burned) time++;
    }

    return time;
}

void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& graph) {
    if (!node) return;

    if (parent) {
        graph[node->val].push_back(parent->val);
        graph[parent->val].push_back(node->val);
    }

    buildGraph(node->left, node, graph);
    buildGraph(node->right, node, graph);
}