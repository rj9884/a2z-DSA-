#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;
vector<int> majorityElementsII(vector<int> arr);
vector<int> majorityElementsIIBetter(vector<int>nums);


// majority Elements : greater than floor(N/3)
int main() {
    vector<int>v = {2,2,1,3,1,1,3,1,1};
    // vector<int>ans = majorityElementsII(v);
    vector<int>ans = majorityElementsIIBetter(v);

    for(auto val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}



// Better Sol : time - O(n(log(n))) , space : O(n)

vector<int> majorityElementsII(vector<int> arr) {
    int n = arr.size();
    int mini = (int)(n/3) + 1;
    unordered_map<int, int>mpp;
    vector<int>ls;

    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
        if(mpp[arr[i]] == mini) {
            ls.push_back(arr[i]);
        }
        if(ls.size() == 2) break;
    }

    return ls;
}


// Optimal Sol : time - O(n) , space : O(1)

vector<int> majorityElementsIIBetter(vector<int>nums) {
    int n = nums.size();
    int cnt1 = 0; int cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    vector<int>ans;

    for(int i = 0; i < n; i++) {
        if(cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            el1 = nums[i];
        }else if(cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i];
        }else if(el1 == nums[i]) cnt1++;
            else if(el2 ==  nums[i]) cnt2++;
            else{
            cnt1--;
            cnt2--;
            }
    }
    cnt1 = 0; cnt2 = 0;
    int mini = (int)(n/3) + 1;
    for(int i = 0; i < n; i++) {
        if(el1 == nums[i]) cnt1++;
        if(el2 == nums[i]) cnt2++;
    }
    if(cnt1 >= mini) ans.push_back(el1);
    if(cnt2 >= mini) ans.push_back(el2);

    return ans;
}