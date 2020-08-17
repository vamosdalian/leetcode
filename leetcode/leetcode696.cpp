#include "include.h"

class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size() == 1) return 0;
        int result = 0;
        // int count0 = 0, count1 = 0;
        int left0 = 0, left1 = 0, right0 = 1,right1 = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i-1]){
                result += min(right0 - left0, right1 - left1);
                if(s[i] == '0'){
                    left0 = i;
                    right0 = i+1;
                }
                if(s[i] == '1'){
                    left1 = i;
                    right1 = i+1;
                }
            }else{
                if(s[i] == '0'){
                    right0 = i+1;
                }
                if(s[i] == '1'){
                    right1 = i+1;
                }
            }
        }
        // result += min(right0 - left0, right1 - left1);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution *method = new Solution();
    cout << method->countBinarySubstrings("00110");
    return 0;
}
