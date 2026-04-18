#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int countStudent(vector<int>& arr, int maxPagesAllowed);
int findPages(vector<int>& pages, int m);

int main() {
    vector<int>arr = {25, 46, 28, 49, 24};
    cout << findPages(arr, 4) << endl;
    return 0;
}


/* time : O(log(sum - max)) * O(N)
   space : O(1) */
int countStudent(vector<int>& arr, int maxPagesAllowed) {
    int students = 1;
    long long currentPagesSum = 0;

    for (int pages : arr) {
        if (currentPagesSum + pages <= maxPagesAllowed) {
            currentPagesSum += pages;
        } else {
            students++;
            currentPagesSum = pages;
        }
    }
    return students;
}

int findPages(vector<int>& pages, int m) {
    int n = pages.size();
    if (m > n) return -1; 

    int low = *max_element(pages.begin(), pages.end());
    long long high = accumulate(pages.begin(), pages.end(), 0LL);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (countStudent(pages, mid) <= m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low; 
}
