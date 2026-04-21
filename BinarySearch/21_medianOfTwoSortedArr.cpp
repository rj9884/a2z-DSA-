#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

double medianSortedBrute(vector<int>&arr1, vector<int>&arr2);
double medianSortedBetter(vector<int>&arr1, vector<int>&arr2);
double median(vector<int>&a, vector<int>&b);
int main() {
    vector<int>arr1 = {1,3,4,7,10,12};
    vector<int>arr2 = {2,3,6,15};
    // cout << medianSortedBrute(arr1, arr2) << endl;
    cout << medianSortedBetter(arr1, arr2) << endl;
    cout << median(arr1, arr2) << endl;
    return 0;
}

// Brute Approach

double medianSortedBrute(vector<int>&arr1, vector<int>&arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = n1 + n2;

    int i = 0;
    int j = 0;
    vector<int>arr3;

    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) arr3.push_back(arr1[i++]);
        else arr3.push_back(arr2[j++]);
    }
    while(i < n1) arr3.push_back(arr1[i++]);
    while(j < n2) arr3.push_back(arr2[j++]);

    if(n3 % 2 != 0) return arr3[n3/2];
    else return (double)((double)(arr3[n3 / 2] + (double)arr3[(n3 / 2) - 1]) / 2.0);
    
}

// Better : removing extra space
double medianSortedBetter(vector<int>&arr1, vector<int>&arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = n1 + n2;

    int i = 0;
    int j = 0;
    int idx2 = n3/2;
    int idx1 = n3/2 - 1; 

    int idx1el = -1;
    int idx2el = -1;
    int cnt = 0;
    

    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) {
            if(cnt == idx1) idx1el = arr1[i];
            if(cnt == idx2) idx2el = arr1[i];
            cnt++;
            i++;
        }
        else {
            if(cnt == idx1) idx1el = arr2[j];
            if(cnt == idx2) idx2el = arr2[j];
            cnt++;
            j++;
        }
    }
    while(i < n1) {
        if(cnt == idx1) idx1el = arr1[i];
        if(cnt == idx2) idx2el = arr1[i];
        cnt++;
        i++;
    }
    while(j < n2) {
        if(cnt == idx1) idx1el = arr2[j];
        if(cnt == idx2) idx2el = arr2[j];
        cnt++;
        j++;
    }

    if(n3 / 2 == 1) return idx2el;
    return (double)((double)(idx1el + idx2el)) / 2.0;
    
}


// Optimal : Using Binary Search
/* time : O(min(logn1, logn2)) */

double median(vector<int>&a, vector<int>&b) {
    int n1 = a.size();
    int n2 = b.size();

    if(n1 > n2) return median(b, a);

    int low = 0;
    int high = n1;
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
            if(n % 2 == 1) return max(l1, l2);
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if(l1 > r2) high = mid1-1;
        else low = mid1+1;
    }
    return 0;
}