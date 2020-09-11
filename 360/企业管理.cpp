#include "include.h"

using namespace std;

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

int main(int argc, char const *argv[])
{
    
    return 0;
}
