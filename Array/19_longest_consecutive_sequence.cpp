#include <iostream>
#include <unordered_set>
using namespace std;

/*
** Longest consecutive sequence **
arr[] = {102, 4, 100, 1, 101, 3, 2, 1, 1}
- [x] : {100, 101, 102} --> 3
- [] : {1, 2, 3, 4} --> 4

so, ans : 4
*/

int longestConsecutiveSequence(int arr[], int n);
int longestConsecutive(int nums[], int n);
int main(){
    int arr[9] = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    cout << longestConsecutiveSequence(arr, 9) << endl;
    cout << longestConsecutive(arr, 9) << endl;
    return 0;
}
// brute
int longestConsecutiveSequence(int arr[], int n){
    int longest = 1;
    for(int i = 0; i < n; i++){
        int count = 1;
        int next = arr[i] + 1;

        for(int j = 0; j < n; j++){
            if(next == arr[j]){
                count++;
                next++;
                j = 0;
            }
        }
        longest = max(longest, count);
    }
    return longest;
}

// optimal
int longestConsecutive(int nums[], int n) {
        unordered_set<int>st;
        int longest = 1;

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        for(auto it: st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int next = it+1;
                
                while(st.find(next) != st.end()){
                    cnt++;
                    next++;
                }
                longest = max(longest, cnt);
            }
            
        }
        return longest;
    }