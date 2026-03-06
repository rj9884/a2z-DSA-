#include <iostream>

using namespace std;

int main(){

    int n = 26;
    string s = "helloworld";

    int hash[26] = {0};

    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a']++;
    }
    cout << "h = " << hash['h'-'a'] << endl;
    cout << "e = " << hash['e'-'a'] << endl;
    cout << "l = " << hash['l'-'a'] << endl;
    cout << "a = " << hash['a'-'a'] << endl;
    cout << "w = " << hash['w'-'a'] << endl;
    return 0;
}