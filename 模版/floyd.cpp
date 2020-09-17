//Floyd（弗洛伊德）代码模版
//用途    ： 获取图各点到各点的最短路径
//输入    ： 有向图，邻接矩阵
//author ： 孟凡宇
//email  ： elve960520@163.com

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


vector<vector<int> > Floyd(vector<vector<int> > nums){
    int tmp = INT_MAX;
    for (int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums.size();j++){
            for (int k = 0; k < nums.size(); k++){
                tmp = (nums[j][i] == INT_MAX || nums[i][k] == INT_MAX) ? INT_MAX : nums[j][i] + nums[i][k];
                if(tmp < nums[j][k]){
                    nums[j][k] = tmp;
                }
            }
        }
    }
    return nums;
}

int main(int argc, char const *argv[])
{
    int n = getNum<int>();
    vector<vector<int> > nums = getNums2<int>(n);
    vector<vector<int> > result = Floyd(nums);
    printVector2(result, " ");
    return 0;
}
