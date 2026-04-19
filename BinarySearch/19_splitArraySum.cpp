#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int countPainters(vector<int>& boards, int time);
int findLargestMinDistance(vector<int>& boards, int k);

int main() {
    vector<int>arr = {10, 20, 30, 40};
    cout << findLargestMinDistance(arr, 2) << endl;
    return 0;
}


/* time : O(log(sum - max)) * O(N)
   space : O(1) */
int countPainters(vector<int>& boards, int time) {
    int painters = 1;
    long long boardsPainter = 0;

    for (int board : boards) {
        if (boardsPainter + board <= time) {
            boardsPainter += board;
        } else {
            painters++;
            boardsPainter = board;
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int>& boards, int k) {
    int n = boards.size();
    if (k > n) return -1; 

    int low = *max_element(boards.begin(), boards.end());
    long long high = accumulate(boards.begin(), boards.end(), 0LL);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (countPainters(boards, mid) <= k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low; 
}
