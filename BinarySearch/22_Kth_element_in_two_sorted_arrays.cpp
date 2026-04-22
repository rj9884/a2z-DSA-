#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

double KthElement(vector<int>&a, vector<int>&b, int k);
int main() {
    vector<int>arr1 = {1,3,4,7,10,12};
    vector<int>arr2 = {2,3,6,15};
    cout << KthElement(arr1, arr2, 5) << endl;
    return 0;
}


// Optimal : Using Binary Search
/* time : O(min(logn1, logn2)) */

double KthElement(vector<int>&a, vector<int>&b, int k) {
    int n1 = a.size();
    int n2 = b.size();

    if(n1 > n2) return KthElement(b, a, k);

    int low = max(k-n2, 0);
    int high = min(k, n1);
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while(low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];

        if(mid1 - 1 >= 0) l1 = a[mid1-1];
        if(mid2 - 1 >= 0) l2 = b[mid2-1];

        if(l1 <= r2 & l2 <= r1) {
            return max(l1, l2);
        }
        else if(l1 > r2) high = mid1-1;
        else low = mid1+1;
    }
    return 0;
}