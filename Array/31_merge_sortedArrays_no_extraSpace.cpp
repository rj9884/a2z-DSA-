#include <iostream>
#include <algorithm>

using namespace std;
void merge(int arr1[], int arr2[], int n, int m);
void mergeOptimal(int arr1[], int arr2[], int n, int m);
void mergeOptimalUsingGap(int arr1[], int arr2[], int n, int m);

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[4] = {1,3,4,5};
    int arr2[4] = {2,6,7,8};
    print(arr1, 4);
    print(arr2, 4);
    // merge(arr1, arr2, 4, 4);
    // mergeOptimal(arr1, arr2, 4, 4);
    mergeOptimalUsingGap(arr1, arr2, 4, 4);
    print(arr1, 4);
    print(arr2, 4);
    return 0;
}



// Merge Two Sorted Arrays
/* time : O(n+m) + O(n+m)
   space : O(n+m) */

void merge(int arr1[], int arr2[], int n, int m) {
    long long arr3[n+m];
    int left = 0;
    int right =  0;
    int idx = 0;

    while(left < n && right < m) {
        if(arr1[left] <= arr2[right]) {
            arr3[idx++] = arr1[left++];
        }else{
            arr3[idx++] = arr2[right++];
        }
    }

    while(left < n) {
        arr3[idx++] = arr1[left++];
    }
    while(right < m) {
        arr3[idx++] = arr2[right++];
    }
    for(int i = 0; i < n+m; i++) {
        if(i < n) {
            arr1[i] = arr3[i];
        }else{
            arr2[i-n] = arr3[i];
        }
    }
}


// optimal 1
/* time: O(min(n,m)) + O(nlogn) + O(mlogm)
   space : O(1) */
void mergeOptimal(int arr1[], int arr2[], int n, int m) {
    int left = n-1;
    int right = 0;

    while(left >= 0 && right < m) {
        if(arr1[left] > arr2[right]) {
            swap(arr1[left--], arr2[right++]);
        }else{
            break;
        }
    }
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
}

// optimal 2: Uing gap method
/* time : O(log(n+m)) * O(n+m) 
   space : O(1) */
void swapIfGreater(int arr1[], int arr2[], int idx1, int idx2) {
    if(arr1[idx1] > arr2[idx2]) {
        swap(arr1[idx1], arr2[idx2]);
    }
} 

void mergeOptimalUsingGap(int arr1[], int arr2[], int n, int m) {
    int len = (n+m);
    int gap = (len / 2) + (len % 2);

    while(gap > 0) {
        int left = 0;
        int right = left + gap;
        
        while(right < len) {
            // arr1 && arr2
            if(left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right-n);
            }
            // arr2 && arr2
            else if(left >= n) {
                swapIfGreater(arr2, arr2, left-n, right-n);
            }
            // arr1 && arr1
            else{
                swapIfGreater(arr1, arr1, left, right);
            }
            left++; right++;
        }
        if(gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
}