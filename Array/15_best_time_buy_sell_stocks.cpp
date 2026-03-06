#include <iostream>
using namespace std;


int bestTimeToBuyStock(int arr[], int n){
    int minimum = arr[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++){
        int cost = arr[i] - minimum;
        maxProfit = max(maxProfit, cost);

        minimum = min(arr[i], minimum);
    }
    return maxProfit;
}
int main(){
    int arr[6] = {7, 1, 4, 5, 6, 2};
    cout << bestTimeToBuyStock(arr, 6) << endl;
    return 0;
}