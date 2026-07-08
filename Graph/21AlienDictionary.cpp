#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
private:
    vector<int> topoSort(vector<vector<int>> &adj, int V) {
        vector<int> topo;
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (int it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int adjNode : adj[node]) {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }

        return topo;
    }

public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);

        for (int i = 0; i < N - 1; i++) {
            string &s1 = dict[i];
            string &s2 = dict[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }

            // Invalid prefix case
            if (!found && s1.size() > s2.size())
                return "";
        }

        vector<int> topo = topoSort(adj, K);

        // Cycle detected
        if (topo.size() != K)
            return "";

        string ans;
        for (int ch : topo) {
            ans += char(ch + 'a');
        }

        return ans;
    }
};

/* Time : O(N*len)+O(K+E), Space: O(K) */

int main() {
    int N = 5;
    int K = 4;
    string dict[] = {"baa","abcd","abca","cab","cad"};

    Solution sol;

    string ans = sol.findOrder(dict, N, K);

    cout << "Order: " << endl;
    for(auto &it : ans) {
        cout << it << " ";
    }
    cout << endl;
}