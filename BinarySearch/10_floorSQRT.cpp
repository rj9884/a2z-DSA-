#include <iostream>
#include <vector>

using namespace std;
int floorSqrt(int n);

int main() {
    cout << floorSqrt(37) << endl;
    return 0;
}

int floorSqrt(int n) {
    int low = 1;
    int high = n;

    while(low <= high) {
        long long mid = low + (high - low) / 2;
        int val = mid * mid;
        if(val <= n) low = mid+1;
        else high = mid-1;
    }
    return high;
}