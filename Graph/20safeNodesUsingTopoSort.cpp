#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>>reverseGraph(V);
        vector<int>indegree(V, 0);
        for(int i = 0; i < graph.size(); i++) {
            for(auto &it : graph[i]) {
                reverseGraph[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int>ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: reverseGraph[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/* Time: O(V + E) , Space: O(V + E) */

int main() {
    vector<vector<int>> graph = {
        {1,2},{2,3},{5},{0},{5},{}, {} 
    };
    Solution sol;
    vector<int>res = sol.eventualSafeNodes(graph);
    cout << "Safe Nodes are: " << endl;

    for(auto &it: res) {
        cout << it << " ";
    }
    cout << endl;
}