#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int comboOf(int cash) {
    if(cash<=2) return cash;
    vector<int> dp(cash+1,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= cash; i++){
        if(i - 5 >= 0){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-5];
        }else{
            dp[i] = dp[i-1] + dp[i-2];
        }
    }
    return dp[cash];
}
/******************************结束写代码******************************/


int main() {
    int res;

    int _cash;
    cin >> _cash;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    
    res = comboOf(_cash);
    cout << res << endl;
    
    return 0;

}
