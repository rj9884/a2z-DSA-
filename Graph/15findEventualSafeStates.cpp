#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool dfsCheck(vector<vector<int>>& graph, int start, vector<int>& vis, vector<int>& path, vector<int>& check) {
        vis[start] = 1;
        path[start] = 1;
        check[start] = 0;

        for(auto adjNode: graph[start]) {
            if(!vis[adjNode]) {
                if(dfsCheck(graph, adjNode, vis, path, check) == true) return true;
            }
            else if(path[adjNode] == 1) return true;
        }
        path[start] = 0;
        check[start] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>vis(n, 0);
        vector<int>path(n, 0);
        vector<int>check(n, 0);
        vector<int>safeNode;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfsCheck(graph, i, vis, path, check);
            }
        }

        for(int i = 0; i < n; i++) {
            if(check[i]) safeNode.push_back(i);
        }

        return safeNode;
    }
};

/* Time: O(N + E) , O(N) */

int main() {
    vector<vector<int>>graph = {
        {1,2},{2,3},{5},{0},{5},{},{}
    };

    Solution sol;
    vector<int>res = sol.eventualSafeNodes(graph);
    cout << "Safe Nodes are: " << endl;
    for(auto const val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}