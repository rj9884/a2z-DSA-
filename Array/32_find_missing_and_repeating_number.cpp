#include <iostream>
#include <vector>

using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int>&nums);
vector<int> findMissingRepeatingNumbersOptimalUsingFormula(vector<int>&nums);

int main() {
    vector<int>arr = {1, 2, 3, 2};
    // vector<int> ans = findMissingRepeatingNumbers(arr);
     vector<int> ans = findMissingRepeatingNumbersOptimalUsingFormula(arr);
    for(auto val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}



// better
/* time : O(2n) 
   space : O(n) */

vector<int> findMissingRepeatingNumbers(vector<int>&nums) {
    int n = nums.size();
    int hash[n+1] = {0};

    for(int i = 0; i < n; i++) {
        hash[nums[i]]++;
    }
    int repeating = -1;
    int missing = -1;
    for(int i = 1; i <= n; i++) {
        if(hash[i] == 2 ) repeating = i;
        else if(hash[i] == 0) missing = i;

        if(repeating != -1 && missing != -1) break;
    }
    return {repeating, missing};
}

// Optimal using formula
/* time : O(n) 
   space : O(1) */

vector<int> findMissingRepeatingNumbersOptimalUsingFormula(vector<int>&nums) {
    int n = nums.size();
    // Sn = (n*(n+1)) / 2
    // S2n = (n * (n+1) * (2*n+1)) / 6
    // S - Sn :  x+y
    // S2 - S2n

    long long Sn = (n * (n+1)) / 2;
    long long S2n = (n* (n+1) * (2*n+1)) / 6;
    long long S = 0, S2 = 0;

    for(int i = 0; i < n; i++) {
        S += nums[i];
        S2 += (long long)nums[i] * (long long)nums[i];
    }
    long long val1 = S -  Sn;
    long long val2 = S2 - S2n;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x , (int)y};
}
