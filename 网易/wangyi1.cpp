#include "include.h"

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int getParlindrome1(string s, string& res) {
       if (s.size() == 0) return 0;
       int len = s.size();
       vector<vector<int> >dp(len, vector<int>(len, 0));
       for (int j = 1;j < len;++j) {
              dp[j - 1][j] = s[j-1] == s[j] ? 0 : 1;
              for (int i = j - 2;i > -1;--i) {
                     if (s[i] == s[j]) {
                           dp[i][j] = dp[i + 1][j-1];
                     }
                     else {
                           dp[i][j] = min(dp[i+1][j],dp[i][j-1]) + 1;
                     }
              }
       }
       int addnumber = dp[0][len - 1];
       int total = addnumber + len;
       string tmp(total,'x');
       int s_lhs = 0;
       int s_rhs = len - 1;
       int tmp_lhs = 0;
       int tmp_rhs = total - 1;
       while (s_lhs <= s_rhs) {
              if (s[s_lhs] == s[s_rhs]) {
                     tmp[tmp_lhs++] = s[s_lhs++];
                     tmp[tmp_rhs--] = s[s_rhs--];
              }
              else if (dp[s_lhs][s_rhs] == dp[s_lhs][s_rhs -1] + 1) {
                     tmp[tmp_lhs++] = s[s_rhs];
                     tmp[tmp_rhs--] = s[s_rhs--];
              }
              else {
                     tmp[tmp_rhs--] = s[s_lhs];
                     tmp[tmp_lhs++] = s[s_lhs++];
              }
       }
       res = tmp;
       return addnumber;
}

string shortestPalindrome(string s)
{
    int n = s.size();
    string rev(s);
    reverse(rev.begin(), rev.end());
    string s_new = s + "#" + rev;
    // string s_new = rev + "#" + s;
    int n_new = s_new.size();
    vector<int> f(n_new, 0);
    for (int i = 1; i < n_new; i++) {
        int t = f[i - 1];
        while (t > 0 && s_new[i] != s_new[t])
            t = f[t - 1];
        if (s_new[i] == s_new[t])
            ++t;
        f[i] = t;
    }
    //return rev.substr(0, n - f[n_new - 1]) + s;
    return s + rev.substr(n - f[n_new - 1], n-1);
}
//回文字符串
bool isHui(string str){
    int size = str.size();
    for(int i = 0;i < size/2;i++){
        if(str[i] != str[size - i - 1]){
            return false;
        }
    }
    return true;
}
string method(string str){
    string tmpStr(str);
    reverse(tmpStr.begin(),tmpStr.end());
    string result = str+tmpStr;
    // cout << result;
    int size = result.length()/2;
    string returnStr;
    for(int i = 0;i < result.size() / 2; i++){
        string tmpRes(result.begin(),result.begin()+size);
        tmpRes.append(result.begin()+size+i,result.end());
        if(isHui(tmpRes)){
            returnStr = tmpRes;
        }else{
            return returnStr;
        }
    }
    return returnStr;
}
string method2(string str){
    string tmp(str);
    reverse(tmp.begin(),tmp.end());
    str = str + tmp;
    int size = str.size();
    int hafSize = str.size() /2;
    string result;
    for(int i = 0;i < str.size()/2;i++){
        if(isHui(str.substr(0,hafSize) + str.substr(hafSize + i, size))){
            result = str.substr(0,hafSize) + str.substr(hafSize + i, size);
        }
    }
    return result;
}

int main() {
       string s = "no";
    //    string res;
       cout << method(s) << endl;
    //    cout << res << endl;
       return 0;
}
