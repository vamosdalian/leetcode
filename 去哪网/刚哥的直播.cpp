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

int c(int n, int m){
    int result = 1;
    int k = n-m;
    for(int i = n; i > 1; i--){
        result *= i;
    }
    for(int i = k; i >= 1; i--){
        result /= i;
    }
    for(int i = m; i >1; i--){
        result /= i;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int n = getNum<int>();
    int m = getNum<int>();
    cout << c(n, m);
    return 0;
}
