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

void huisu(vector<vector<int> > &matrix,int target, int &sum, int &i, int &j,vector<int> &tmpres, vector<vector<int> > &result){
    if(sum == target){
        result.push_back(tmpres);
        return ;
    }else if(sum < target){
        if(i-1 >= 0){
            i--;
            tmpres.push_back(matrix[i][j]);
            sum+=matrix[i][j];
            huisu(matrix, target, sum, i, j, tmpres, result);
            sum-=matrix[i][j];
            tmpres.pop_back();
            i++;
        }
        if(j+1 <= matrix[0].size()-1){
            j++;
            tmpres.push_back(matrix[i][j]);
            sum+=matrix[i][j];
            huisu(matrix, target, sum, i, j, tmpres, result);
            sum-=matrix[i][j];
            tmpres.pop_back();
            j--;
        }
    }else{
        return ;
    }

}

//输出二维vector
template <typename T>
void printVector2(vector<vector<T> > input){
    for(int i = 0 ; i < input.size(); ++i){
        for(int j = 0; j < input[i].size(); ++j){
            cout << input[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    //获取矩阵目标路径（没有对空矩阵判断）
    int n = getNum<int>();//矩阵行数
    vector<vector<int> > matrix = getNums2<int>(n);//矩阵
    int target = getNum<int>();//目标值
    int i = n-1,j = 0;
    int sum = matrix[i][j];
    vector<int> tmpvec{matrix[i][j]};
    vector<vector<int> > result;//结果
    huisu(matrix, target, sum, i, j, tmpvec, result);
    printVector2(result);
    return 0;
}
