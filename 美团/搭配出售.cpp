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

long long maxPrice(vector<int> nums){
    int first = 0, second = 0, third = 0;
    if(nums[4] >= nums[5] && nums[4] >= nums[6]){
        first = 4;
        if(nums[5] >= nums[6]){
            second = 5;
            third = 6;
        }else{
            second = 6;
            third = 5;
        }
    }else if(nums[5] >= nums[4] && nums[5] >= nums[6]){
        first = 5;
        if(nums[4] >= nums[6]){
            second = 4;
            third = 6;
        }else{
            second = 6;
            third = 4;
        }
    }else if(nums[6] >= nums[5] && nums[6] >= nums[4]){
        first = 6;
        if(nums[5] >= nums[4]){
            second = 5;
            third = 4;
        }else{
            second = 4;
            third = 5;
        }
    }
    cout << first << " " << second << " " << third << endl;
    long long  result = 0;
    if(nums[3] >= nums[first - 4]){
        result += nums[first - 4] * nums[first];
        nums[3] -= nums[first - 4];
    }else{
        result += nums[3] * nums[first];
        return result;
    }
    if(nums[3] >= nums[second - 4]){
        result += nums[second - 4] * nums[second];
        nums[3] -= nums[second - 4];
    }else{
        result += nums[3] * nums[second];
        return result;
    }
    if(nums[3] >= nums[third - 4]){
        result += nums[third - 4] * nums[third];
        nums[3] -= nums[third - 4];
    }else{
        result += nums[3] * nums[third];
        return result;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = getNums<int>();
    cout << maxPrice(nums);
    return 0;
}
