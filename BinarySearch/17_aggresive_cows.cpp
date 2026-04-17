#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int aggresiveCows(vector<int>&stalls, int cows);
int canWePlace(vector<int>&stalls, int dist, int cows);

int main() {
    vector<int>arr = {10, 1, 2, 7, 5};
    cout << aggresiveCows(arr, 3);
    return 0;
}

int canWePlace(vector<int>&stalls, int dist, int cows) {
    int cntCows = 1;
    int last = stalls[0];
    int n = stalls.size();

    for(int i = 1; i < n; i++) {
        if((stalls[i] - last) >= dist) {
            cntCows++;
            last = stalls[i];
        }
        if(cntCows >= cows) return 1;
    }
    return 0;
}
/* time : O(N(log(N))) , space : O(1)*/
int aggresiveCows(vector<int>&stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n-1] - stalls[0];

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(canWePlace(stalls, mid, cows)) low = mid+1;
        else high = mid-1;
    }
    return high;
}