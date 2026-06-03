#include <bits/stdc++.h>
using namespace std;

// Structure to represent a node in a binary tree
struct TreeNode {
    // Value stored in the node
    int val;
    // Pointer to the left child
    TreeNode *left;
    // Pointer to the right child
    TreeNode *right;

    // Constructor to initialize the node with a value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
    // Function to record the parent of each node in the tree
    void markParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
        // Create a queue for level-order traversal
        queue<TreeNode*> q;
        // Start traversal from the root
        q.push(root);

        // Continue until the queue is empty
        while (!q.empty()) {
            // Take the front node from the queue
            TreeNode* current = q.front();
            // Remove the node from the queue
            q.pop();

            // If the current node has a left child
            if (current->left) {
                // Record the parent of the left child
                parent_track[current->left] = current;
                // Add the left child to the queue
                q.push(current->left);
            }

            // If the current node has a right child
            if (current->right) {
                // Record the parent of the right child
                parent_track[current->right] = current;
                // Add the right child to the queue
                q.push(current->right);
            }
        }
    }

public:
    // Function to find all nodes at distance k from a given target node
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Map to store parent relationships for each node
        unordered_map<TreeNode*, TreeNode*> parent_track;
        // Fill parent relationships by traversing the tree
        markParents(root, parent_track);

        // Map to track visited nodes so we don’t revisit them
        unordered_map<TreeNode*, bool> visited;

        // Queue for BFS traversal starting from target node
        queue<TreeNode*> q;
        // Push the target node as the starting point
        q.push(target);
        // Mark the target as visited
        visited[target] = true;

        // Variable to track the current BFS level
        int curr_level = 0;

        // Continue BFS until we process all nodes or reach the desired distance
        while (!q.empty()) {
            // Number of nodes in the current level
            int size = q.size();

            // If we have reached the desired distance, stop further BFS
            if (curr_level++ == k) break;

            // Process all nodes at this level
            for (int i = 0; i < size; i++) {
                // Take the front node in the queue
                TreeNode* current = q.front();
                // Remove it from the queue
                q.pop();

                // If the left child exists and is not visited
                if (current->left && !visited[current->left]) {
                    // Add left child to the queue
                    q.push(current->left);
                    // Mark it as visited
                    visited[current->left] = true;
                }

                // If the right child exists and is not visited
                if (current->right && !visited[current->right]) {
                    // Add right child to the queue
                    q.push(current->right);
                    // Mark it as visited
                    visited[current->right] = true;
                }

                // If the parent exists and is not visited
                if (parent_track[current] && !visited[parent_track[current]]) {
                    // Add parent to the queue
                    q.push(parent_track[current]);
                    // Mark it as visited
                    visited[parent_track[current]] = true;
                }
            }
        }

        // Vector to store the final result (nodes at distance k)
        vector<int> result;

        // Collect all nodes remaining in the queue
        while (!q.empty()) {
            // Take the front node
            TreeNode* current = q.front();
            // Remove it from the queue
            q.pop();
            // Store the value of this node
            result.push_back(current->val);
        }

        // Return the list of nodes at distance k
        return result;
    }
};

// Driver code
int main() {
    // Create the root of the binary tree
    TreeNode* root = new TreeNode(3);
    // Add left child to root
    root->left = new TreeNode(5);
    // Add right child to root
    root->right = new TreeNode(1);
    // Add more children to build the tree
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Create an object of Solution class
    Solution sol;

    // Define the target node (node with value 5)
    TreeNode* target = root->left;
    // Define the distance k
    int k = 2;

    // Call the function to find nodes at distance k
    vector<int> result = sol.distanceK(root, target, k);

    // Print the result
    cout << "Nodes at distance " << k << " from target node " << target->val << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // End of program
    return 0;
}
