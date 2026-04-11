#include <iostream>

using namespace std;
int findVal(int mid, int n, int m);
int NthRoot(int n, int m);

int main() {
    cout << NthRoot(3, 64) << endl;
    return 0;
}

int findVal(int mid, int n, int m) {
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}
int NthRoot(int n, int m) {
    int low = 1;
    int high = m;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int val = findVal(mid, n, m);

        if(val == 1) return mid;
        else if(val == 0) low = mid+1;
        else high = mid-1;
    }
    return -1;
}