#include "include.h"

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

// long long maxDiff(string str){
//     // vector<vector<long long > dp(str.size()+1,vector<long long>(str.size() + 1, 0));
//     long long countE = 0;
//     long long countF = 0;
//     long long result = 0;
//     // int i = 0; 
//     // int j = 1;
//     // vector<long long> dp(str.size(),0);
//     for(int i = 0 ;i < str.size(); i++){
//         for(int j = i; j < str.size();j++){
//             if(str[j] == 'E') countE++;
//             else countF++;
//             if(countE - countF > result){
//                 result = countE - countF;
//             }
//         }
//     }
//     return result;
//     // if(str[i] == 'E') countE++;
//     // else countF++;
//     // while(i < j && j < str.size()){
//     //     if(str[j] == 'F'){
//     //         countF++;
//     //         j++;
//     //     }else if(str[j] == 'E'){
//     //         countE++;
//     //         j++;
//     //     }
//     // }
// }

// int main(int argc, char const *argv[])
// {
//     long long n = getNum<long long>();
//     string str = getString();
//     cout << maxDiff(str);
//     return 0;
// }

// #include <bits/stdc++.h>
using namespace std;
#define N 300100

int e[N], f[N];

int main(){
    int n;
    string s;
    scanf("%d", &n);
    cin >> s;
    int res = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'E'){
            e[i+1] = e[i]+1;
            f[i+1] = f[i];
            if(e[i+1] == f[i+1]){
                e[i+1] = 1;
                f[i+1] = 0;
            }
            res = max(res, abs(e[i+1]-f[i+1]));
        }else if(s[i] == 'F'){
            f[i+1] = f[i]+1;
            e[i+1] = e[i];
            if(e[i+1] == f[i+1]){
                e[i+1] = 0;
                f[i+1] = 1;
            }
            res = max(res, abs(e[i+1]-f[i+1]));
        }
       // cout << e[i+1] << " " << f[i+1] << endl;
    }
    cout << res << endl;
    return 0;
}