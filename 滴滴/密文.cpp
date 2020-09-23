// #include "include.h"

// using namespace std;

// //获取一个数字
// template <typename T>
// T getNum(){
//     T result = 0;
//     string str;
//     bool isFushu = false;
//     getline(cin, str);
//     for(int i = 0; i < str.size(); ++i){
//         if(str[i] == '-'){
//             isFushu = true;
//             continue;
//         }
//         if(str[i]>='0' && str[i] <= '9'){
//             result = isFushu? result*10 - str[i] + '0' : result*10 + str[i] - '0';
//         }
//     }
//     return result;
// }
// //获取一个字符串
// string getString(){
//     string result;
//     getline(cin, result);
//     return result;
// }

// string nixu(int n, string strs){
//     string result;
//     string tmpstr;
//     for (int i = 0; i < strs.size(); i++)
//     {
//         tmpstr.push_back(strs[i]);
//         if(tmpstr.size() == n){
//             reverse(tmpstr.begin(), tmpstr.end());
//             result.insert(result.end(), tmpstr.begin(), tmpstr.end());
//             tmpstr.clear();
//         }
//     }
//     reverse(tmpstr.begin(), tmpstr.end());
//     result.insert(result.end(), tmpstr.begin(), tmpstr.end());
//     tmpstr.clear();
//     return result;
// }

// int main(int argc, char const *argv[])
// {
//     int n = getNum<int>();
//     string strs = getString();
//     cout << nixu(n, strs);
//     return 0;
// }

#include "include.h"
// #include "bitset/stdc++.h"
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

//获取二维数组
template <typename T>
vector< vector<T> > getNums2(int n, char c = ' '){
    vector< vector<T> > result;
    vector<T > tmpResult;
    while(n--){
        tmpResult = getNums<T>(c);
        if(tmpResult.size() == 0) break;
        result.push_back(tmpResult);
        tmpResult.clear();
    }
    return result;
}

//输出二维vector
template <typename T>
void printVector2(vector<vector<T> > input, string str = "\t"){
    for(int i = 0 ; i < input.size(); ++i){
        for(int j = 0; j < input[i].size(); ++j){
            cout << input[i][j] << str;
        }
        cout << endl;
    }
}

string nixu(int n, string str){
    return str;
}

int main(int argc, char const *argv[])
{
    // int num = getNum<int>();
    // string str = getString();
    // cout << nixu(num,str);
    // vector<int> nums = getNums<int>(',');
    // for(auto i : nums){
    //     cout << i << endl;
    // }
    vector<vector<int> > nums = getNums2<int>(2);
    printVector2(nums," ");
    return 0;
}

