#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int subArrayWithXORBrute(vector<int> &nums, int k);
int subArrayWithXORBetter(vector<int> &nums, int k);
int subArrayWithXOROptimal(vector<int> &nums, int k);

int main() {
    vector<int>nums = {4,2,2,6,4};
    // cout << subArrayWithXORBrute(nums, 6) << endl;
    // cout << subArrayWithXORBetter(nums, 6) << endl;
    cout << subArrayWithXOROptimal(nums, 6) << endl;
    return 0;
}




// Brute Force

int subArrayWithXORBrute(vector<int> &nums, int k) {
    int n = nums.size();
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int XOR = 0;

            for(int k = i; k <= j; k++) {
                XOR = XOR^nums[k];
            }
            if(XOR == k) {
                cnt++;
            }
        }
    }
    return cnt;
}

// Better Sol.

int subArrayWithXORBetter(vector<int> &nums, int k) {
    int n = nums.size();
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        int XOR = 0;
        for(int j = i; j < n; j++) {
            XOR ^= nums[j];
            if(XOR == k) {
                cnt++;
            }
        }
        
    }
    return cnt;
}


// Optimal Sol. time: O(n) or O(nlogn) , space : O(n)

int subArrayWithXOROptimal(vector<int> &nums, int k) {
    int n = nums.size();
    int xr = 0;
    unordered_map<int, int>mpp;
    mpp[xr]++;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        xr ^= nums[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}