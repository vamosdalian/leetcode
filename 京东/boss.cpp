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

//获取多个数字
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

long long methods(int m, vector<int> bk){
    vector<vector<int> > dp(bk.size()+1,vector<int>(m+1, 0));
    for(int j = 1 ;j <= m;j++){
        if(j >= bk[0]) dp[0][j] = 1;
        else dp[0][j] = 0;
    }
    for(int i = 1; i <= bk.size();i++){
        for(int j = 1; j <= m;j++){
            if(i - bk[i] <= 0){
                dp[i][j] = dp[i][j-1];
            }else{
                dp[i][j] = dp[i-bk[i]][j]+dp[bk[i]][j];
            }
        }
    }
    return dp[bk.size()][m];
}

int main(int argc, char const *argv[])
{
    vector<int> tmp = getNums<int>();
    int n = tmp[0],m = tmp[1];
    vector<int> pai;
    while(n--){
        pai.push_back(getNum<int>());
    }
    sort(pai.begin(),pai.end());
    // cout << pai[2];
    cout << methods(m,pai);
    return 0;
}
