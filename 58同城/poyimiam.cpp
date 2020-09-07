#include "include.h"

using namespace std;

/**
 * 翻译组合数
 * @param num int整型 数字加密报文
 * @return int整型
 */
int translateNum(int num) {
    vector<int> nums;
    while(num > 0){
        nums.insert(nums.begin(), num%10);
        num /= 10;
    }
    vector<int> dp(nums.size() + 1,1);
    // dp[1] = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if(nums[i-1] * 10 + nums[i] <= 25){
            dp[i+1] = dp[i-1] + dp[i];
        }else{
            dp[i+1] = dp[i];
        }
    }
    return dp[dp.size()-1];
}

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    cout << translateNum(num);
    return 0;
}
