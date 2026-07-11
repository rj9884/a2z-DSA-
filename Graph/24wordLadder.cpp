#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({beginWord, 1});

        st.erase(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endWord) return step;

            for(int i = 0; i < word.size(); i++) {
                char originalChar = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, step+1});
                    } 
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};

/* Time: O(N * word.length * 26 * logN) ; N=wordList size
Space : O(N) */

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    Solution sol;
    cout << "shortest transformation sequence length is " << sol.ladderLength(beginWord, endWord, wordList);
    cout << endl;
}