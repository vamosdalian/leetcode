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
//获取一个字符串
string getString(){
    string result;
    getline(cin, result);
    return result;
}

string nixu(int n, string strs){
    string result;
    string tmpstr;
    for (int i = 0; i < strs.size(); i++)
    {
        tmpstr.push_back(strs[i]);
        if(tmpstr.size() == n){
            reverse(tmpstr.begin(), tmpstr.end());
            result.insert(result.end(), tmpstr.begin(), tmpstr.end());
            tmpstr.clear();
        }
    }
    reverse(tmpstr.begin(), tmpstr.end());
    result.insert(result.end(), tmpstr.begin(), tmpstr.end());
    tmpstr.clear();
    return result;
}

int main(int argc, char const *argv[])
{
    int n = getNum<int>();
    string strs = getString();
    cout << nixu(n, strs);
    return 0;
}
