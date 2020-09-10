#include "include.h"

using namespace std;

//获取一个字符串
string getString(){
    string result;
    getline(cin, result);
    return result;
}

long long translate(string num){
    long long result = 0;
    bool fu = num[0] == '-';
    int i = 0;
    if(fu){
        i = 1;
    }
    for (; i < num.size(); i++){
        result *= 36;
        if((num[i] >= '0' && num[i] <= '9')){
            result += num[i] - '0';
        }else if((num[i] >= 'a' && num[i] <= 'z')){
            result += num[i] - 'a' + 10;
        }else{
            return 0;
        }
        if(result > 9223372036854775807){
            result = 9223372036854775807;
        }
    }
    
    return fu ? -result : result;
}

int main(int argc, char const *argv[])
{
    string input = getString();
    cout << translate(input) << endl;
    // long long x = 9223372036854775807;
    // cout << x << endl;
    return 0;
}
