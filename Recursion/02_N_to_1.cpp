// print number from N to 1
#include <iostream>

using namespace std;

void printNum(int n){
    if(n <= 0){
        return;
    }
    cout << n << endl;
    printNum(--n);
    // cout << n << endl;  backtrack 0,1,2,3,....
}

int main(){
    int n;
    cout << "Enter N: ";
    cin >> n;
    printNum(n);
    return 0;
}