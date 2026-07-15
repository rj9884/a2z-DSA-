#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        const int MOD = 100000;

        if (start == end) return 0;

        vector<int> dist(MOD, 1e9);
        queue<pair<int, int>> q;

        dist[start] = 0;
        q.push({start, 0});

        while (!q.empty()) {
            auto [node, step] = q.front();
            q.pop();

            for (int x : arr) {
                int num = (node * x) % MOD;

                if (step + 1 < dist[num]) {
                    dist[num] = step + 1;

                    if (num == end)
                        return step + 1;

                    q.push({num, step + 1});
                }
            }
        }

        return -1;
    }
};

/*Time: O(100000 * N) , Space: O(100000 * N) */

int main() {
    vector<int>arr = {3, 4, 65};
    int start = 7;
    int end = 66175;

    Solution sol;
    cout << "Minimum step required to reach end is " << sol.minimumMultiplications(arr, start, end) << endl;
    return 0;
}