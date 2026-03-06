// print name N times
#include <iostream>

using namespace std;

void printName(int i, int n){
    if(i > n){
        return;
    }
    cout <<"Name" << endl;
    printName(++i, n);
}

int main(){
    int n;
    cout << "Enter N: ";
    cin >> n;
    printName(1, n);
    return 0;
}