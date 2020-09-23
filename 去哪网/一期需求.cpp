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

int maxlength(vector<int> nums1, vector<int> nums2){
    vector<vector<int> > dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if(nums1[i] == nums2[j]){
                dp[i+1][j+1] = dp[i][j] +1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    return dp[nums1.size()][nums2.size()];
}

int main(int argc, char const *argv[])
{
    int n = getNum<int>();
    vector<int> list1 = getNums<int>();
    vector<int> list2 = getNums<int>();
    cout << maxlength(list1,list2);
    return 0;
}

/*
7
a b c d e f g
b d a c f g e
*/