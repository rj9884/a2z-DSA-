#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class DSU {
    unordered_map<int, int> parent;

public:
    int find(int node) {
        if (parent.find(node) == parent.end()) {
            parent[node] = node;
        }

        if (parent[node] == node) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v) {
        parent[find(u)] = find(v);
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        DSU dsu;

        for (auto &stone : stones) {
            dsu.unite(stone[0], stone[1] + 10001);
        }

        unordered_set<int> components;

        for (auto &stone : stones) {
            components.insert(dsu.find(stone[0]));
        }

        return stones.size() - components.size();
    }
};

/*Time:  O(N * α(N)), where N is number of stones
Space: O(N) */

int main() {
    Solution obj;

    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2}
    };

    cout << obj.removeStones(stones) << endl;

    return 0;
}