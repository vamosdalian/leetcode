#include "include.h"

using namespace std;

//获取一维数组
template <typename T>
vector<T> getNums(char c = ' '){
    vector<T> result;
    string str;
    T tmp = 0;
    bool minus = false;
    getline(cin, str);
    if(str.size() == 0) return result;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == c){
            result.push_back(tmp);
            tmp = 0;
            minus = false;
            continue;
        }
        if(str[i] == '-'){
            minus = true;
            continue;
        }
        tmp = minus? tmp*10 - str[i] + '0' : tmp*10 + str[i] - '0';
    }
    result.push_back(tmp);
    return result;
}

int maxmul(vector<int> nums){
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return nums[0] * nums[1] + max(nums[0], nums[1]);
    if(nums.size() == 3) return nums[0] * nums[1] * nums[2] + nums[0] * nums[2] + max(nums[0],nums[2]);
    return 167;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = getNums<int>(',');
    cout << maxmul(nums);
    return 0;
}
