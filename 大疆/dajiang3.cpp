// #include <bits/stdc++.h>
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
 
string findString(string  ss, int k)
{
    if (k >= ss.size())
    {
        return "";
    }
 
    for (int i = 0; i < ss.size()-1; i++)
    {
                //判断如果k为0时，表示删除完毕，则返回字符串
        if (k == 0)
            return ss;
        if (ss[i] > ss[i + 1])
        {
            //如果前面数字大于后面一位数字，将自身删除
            ss.erase(i, 1);
            i = -1; //如果字符串中执行了产出操作，则字符串返回到首 从新遍历
            k--;
        }
        if (k >= 1 && i == ss.size() - 2)
        {
            if (ss[i] <= ss[i + 1])
            {
                ss.erase(i+1, 1);
            }
            i = -1; //如果字符串中执行了产出操作，则字符串返回到首 从新遍历
            k--;
        }
    }
    return ss;
 
}
 
int main()
{
    string ss = getString();
    int k = getNum<int>();
    // cin >> k;
    cout << findString(ss, k) << endl;
 
    // system("pause");
    return 0;
}