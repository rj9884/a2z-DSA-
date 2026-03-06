#include <iostream>

using namespace std;

int fibonacci(int n){
    if(n <= 1) return n;
    int last = fibonacci(n-1);
    int sLast = fibonacci(n-2);

    return last + sLast;
}
int main(){

    cout << fibonacci(5) << endl;
    return 0;
}