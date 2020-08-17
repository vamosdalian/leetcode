#include "include.h"

using namespace std;

class Solution {
public:
    static bool cmp(string str1, string str2) {
        // if(str1.size() == str2.size()) return str1 < str2;
        int minsize = min(str1.size(), str2.size());
        int maxsize = max(str1.size(), str2.size());
        // cout << str1<<":"<<str2<<endl;
        for(int i = 0;i < minsize;i++){
            if(str1[i] != str2[i]){
                return str1[i] < str2[i];
            }
        }
        
        if(maxsize == str1.size()){
            for(int i = minsize;i < maxsize;i++){
                if(str1[i] != str1[minsize - 1]){
                    return str1[i] < str1[minsize - 1];
                }
            }
        }
        if(maxsize == str2.size()){
            for(int i = minsize;i < maxsize;i++){
                if(str2[i] != str2[minsize - 1]){
                    // cout << str2[i] << str1[minsize - 1]<<endl;
                    return str2[i] < str2[minsize - 1];
                }
            }
        }
        return false;
    }

    string minNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        vector<string> strvec;
        for(auto num : nums){
            strvec.push_back(to_string(num));
        }
        sort(strvec.begin(),strvec.end(),cmp);
        for(auto s : strvec){
            cout << s<<" ";
        }
        string result;
        for(auto str : strvec){
            // cout << str;
            result.append(str);
        }
        // cout << endl;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> input;
    input.push_back(102);
    input.push_back(10);
    Solution *method = new Solution();
    cout << method->minNumber(input);
    return 0;
}
