#include "include.h"

using namespace std;

//获取一个数字
template <typename T>
T getNum(){
    T result = 0;
    string str;
    bool isFushu = false;
    getline(cin, str);
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '-'){
            isFushu = true;
            continue;
        }
        if(str[i]>='0' && str[i] <= '9'){
            result = isFushu? result*10 - str[i] + '0' : result*10 + str[i] - '0';
        }
    }
    return result;
}

int classCount(int n){
    vector<int> dp(n+1,1);
    for(int i = 2; i <= n; i++){
        int tmp = 0;
        for(int j = 0; j < (i/2); j++){
            tmp += 2 * dp[i-j-1] * dp[j];
        }
        if(i%2 == 1){
            tmp += dp[i/2] * dp[i/2];
        }
        // tmp += dp[i/2];
        dp[i] = tmp;
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int n = getNum<int>();
    cout << classCount(n);
    return 0;
}
