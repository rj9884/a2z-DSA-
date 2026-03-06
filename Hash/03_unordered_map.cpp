#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<char, int>charCount;

    string str = "myNamerajan";
    for(int i = 0; i < str.size(); i++){
        charCount[str[i]]++;
    }

    for(auto it: charCount){
        cout << it.first << " = " << it.second << endl;
    }
}