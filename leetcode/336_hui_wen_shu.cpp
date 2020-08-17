#include "include.h"

class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > result;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(j == i) continue;
                if(canCompose(words, i, j)){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
    bool canCompose(vector<string>& words, int i, int j){
        string word = words[i] + words[j];
        cout << "compsing : " << i << "and" << j << "   ";
        for(int k = 0; k < word.size() / 2; ++k){
            if(word[k] != word[word.size() - k - 1]){
                cout << "index "<< k <<"not compsed" <<endl;
                return false;
            }
        }
        cout <<endl;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> words{"abcd","dcba","lls","s","sssll"};
    Solution *method = new Solution();
    vector<vector<int> > result;
    result = method->palindromePairs(words);
    for(auto item : result){
        cout << item[0] << "," << item[1] << endl;
    }
    return 0;
}
